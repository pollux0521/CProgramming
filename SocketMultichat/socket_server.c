#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>
#define PORT_NUM 8881
#define MAX_LENGTH 20
//문제 : client_socket을 accept 를 했는데 왜 client_sockets[num]에서 recv를 하면 받아지나? 
//전역변수들
int serv_socket;                           //서버 소켓
int client_sockets[10] = { 0, };           //쓰레드로 여러 클라이언트를 담을 것이므로 배열(최대 10명)
int client_num = 0;                        //전체 클라이언트 수를 구함
char message[30];                          //메세지 최대길이는 30
char password[30];                         //메세지 최대 길이가 30이므로 패스워드도 30
struct sockaddr_in client_addrs[10];       //client sockets와 배열크기가 같음
struct sockaddr_in serv_addr;              //서버는 하나만 있어도 됨
pthread_mutex_t mutex;                     //한번에 여러곳에서 전역변수를 사용하는 것을 막기위해 사용

//함수들
void setSocket();                          //서버소켓 초기화 함수
void *client_func(void* client_number);    //클라이언트용 쓰레드 함수
void change_position(int num);             //접속종료시 위치변환 함수

int main(int argc, char* argv[]){
    int client_size;                       //잠시 클라이언트 크기를 담음
    int client_socket;                     //전역변수로 옮기기 전에 임시저장소
    int num = 0;                           
    int i;
    int recv_retn;                         
    int client_number = 0;                 //몇번으로 접속했는지 알려줌
    int thread_return;                     
    char checkMessage[32];                 
    struct sockaddr_in client_addr;        //전역변수로 옮기기 전에 임시저장소
    pthread_t client_thread[10];           //클라이언트와 엮어줄 쓰레드(최대 10명)

    if(argc != 3){      // 입력값이 충분하지 않을때
        printf(" Usage : ./<filename> <PORT> <PASSWORD> \n");
        printf(" password is less than 32 digits\n");
        return 0;
    }
    //자신의 패스워드를 전역변수에 저장
    pthread_mutex_lock(&mutex);
    strncpy(password, argv[2],sizeof(argv[2]));
    pthread_mutex_unlock(&mutex);
    //소켓 기초작업을 해줄 함수
    setSocket();
    printf("Server Start....\n");
    //클라이언트 접속을 기다리는 방
    if(listen(serv_socket, 10) == -1){
        perror("listen");
        exit(1);
    }
    
    while(1){
        client_size = sizeof(client_addr);
        printf("///////////////////////");
        //클라이언트 접속을 받아줌. 접속이 올때까지 대기
        if((client_socket = accept(serv_socket,(struct sockaddr *)&client_addr,&client_size)) == -1){
            perror("accept");
            exit(1);
        }
        //비밀번호 체그문
        recv(client_socket,checkMessage,sizeof(checkMessage),0);
        printf("check Message = %s\n", checkMessage);

        if(strncmp(checkMessage,password,sizeof(password)) != 0){
            printf("Wrong Password\n");
            strcpy(checkMessage,"wrong");
            send(client_socket,checkMessage,sizeof(checkMessage),0);
            close(client_socket);
        }
        else send(client_socket,"connected to server", 60,0);
        
        //if문이 하나더 있어야 할거 같음 | for문이랑 연계해야함 -> 해결
        for(i=0;i<10;i++){
            if(client_sockets[i] != 0) continue;
            else{
                printf("client [ %s ] accept\n", inet_ntoa(client_addr.sin_addr));
                pthread_mutex_lock(&mutex);                     //클라이언트 소켓배열로 넘겨주기
                client_sockets[i] = client_socket;
                client_addrs[i] = client_addr;
                printf("client_num = %d\n",client_num);
                client_num++;
                pthread_mutex_unlock(&mutex);
                
                if(client_num < 10){        //인원은 최대 10명만
                    client_number = i;
                    pthread_create(&client_thread[client_number],NULL,client_func,(void *)&client_number);      // client가 접속해올때 마다 쓰레드 할당
                    pthread_detach(client_thread[client_number]);       
                    i++;
                }
                break;
            }
        }
    }
    return 0;
}

void setSocket(){           //전역변수에 있는 소켓 초기화.
    pthread_mutex_lock(&mutex);
    
    if((serv_socket = socket(AF_INET , SOCK_STREAM , 0)) == -1){
        perror("socket");
        exit(1);
    }
    
    memset(&serv_addr,'\0',sizeof(serv_addr));
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);        // htonl(INADDR_ANY) = 자기주소를 구해서 집어넣을 수 있다.
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT_NUM);

    if(bind(serv_socket,(struct sockaddr*)&serv_addr,sizeof(serv_addr)) == -1){
        perror("bind");
        exit(1);
    }
    pthread_mutex_unlock(&mutex);
}

void *client_func(void* client_number){                 //메세지를 보내고 받는부분. 서버가 메세지를 받고 전역에 뿌려준다.
    int num = *((int*)client_number);
    printf("num -- %d\n", num);         
    int i;
    int recv_retn;
    char sendMessage[60];
    char checkMessage[60];
    /*  password 체크하기.  지금 client로 안넘어감. 고로 먼저 넘겨준 후에 비번이 다르면 취소하기로 -> 그냥 메인에서 해결해도 되므로 메인으로 옮긴다*/
    printf("client_num = %d\n", client_sockets[num]);
    while(1){
        if((recv_retn = recv(client_sockets[num],message,sizeof(message),0)) == -1) continue;
        
        else{
            if(strncmp(message,"quit",4) == 0){     //quit이면 나가기.
                change_position(num);
                /*여기에 클라이언트 소켓 바꾸는거 넣기. 인자값은 num*/
                /*바꾸지말고 그곳만 빼놓기.*/
                break;
            }   
            sprintf(sendMessage," %s : %s", inet_ntoa(client_addrs[num].sin_addr),message); //자신의 아이피를 앞에 붙여서 보내준다.
            sendMessage[sizeof(sendMessage)] = '\0';
            printf(" %s\n", sendMessage);
            for(i = 0; i < 10; i++){            //broadcasting 방식. 전체에게 send메세지를 보낸다. 
                send(client_sockets[i], sendMessage,sizeof(sendMessage),0);
            }   
        }
    }
    printf("finished\n");
    return NULL;   
}

void change_position(int num){                                  //방식을 바꿈. change_position으로 빠진곳이 있으면 한칸씩 앞당기는 거였는데
    close(client_sockets[num]);                                 //지금은 그상태로 비워두고 새로운 클라이언트가 들어오면 그자리에 할당하는 방식으로 바꿈
    memset(&client_addrs[num],'\0',sizeof(client_addrs[num]));  //비우는 걸 아는 방법은 메인에서 검사
    printf("client_sockets[num] = %d", client_sockets[num]);
    client_sockets[num] = 0;
    pthread_mutex_lock(&mutex);
    client_num--;
    pthread_mutex_unlock(&mutex);
}

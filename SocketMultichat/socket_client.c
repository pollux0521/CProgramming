#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#define MAX_LENGTH 30

int main(int argc, char* argv[]){
    int client_socket;
    pid_t fork_return;
    struct sockaddr_in serv;
    char sendMessage[30];           //서버와 같이 맞춰준다
    char buf[30];
    char recvMessage[60];           //이것도 서버와 크기를 맞춘다/
    char *checkpass = argv[3];      //패스워드를 체크하는 곳이다.
    char checkMessage[32];      
    char _quit[4] = "quit";

    if(argc != 4){          //인자가 불충분할 때
        printf(" Usage = ./<filename> <IP> <PORT> <PASSWORD>");
        return 0;
    }


    if((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1){    //소켓만들기
        perror("socket");
        exit(1);
    }

    memset(&serv, '\0', sizeof(serv));
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = inet_addr(argv[1]);
    serv.sin_port = htons(atoi(argv[2]));

    if(connect(client_socket, (struct sockaddr*)&serv, sizeof(serv)) == -1){
        perror("connect");
        exit(1);
    }
    printf("client socket = [%d]\n\n",client_socket);
    /*수정중인 곳 -> 비밀번호 확인  (수정완료)*/
    checkpass[sizeof(checkpass)] = '\0';
    send(client_socket,checkpass,sizeof(checkpass),0);
    recv(client_socket,checkMessage,sizeof(checkMessage),0);
    if(strncmp(checkMessage,"wrong",5) == 0){
        printf("Wrong Password!");
        close(client_socket);
        return 0;
    }
    else printf("%s\n", checkMessage);
    //fork로 나눠 parent는 메세지를 보내고 child는 메세지를 받는다 parent에서 quit이 나올 때 child를 죽이고 시스템이 끝난다.
    fork_return = fork(); 
    if(fork_return > 0){
        while(1){
            fgets(sendMessage,sizeof(sendMessage),stdin);
            sendMessage[sizeof(sendMessage)] = '\0';
            strncpy(buf,sendMessage,30);
            send(client_socket,buf, sizeof(buf), 0);
            if(strncmp(buf,_quit,4) == 0){
                printf("quit\n");
                close(client_socket);
                kill(fork_return,SIGINT);
                break;
            }
        }
    }
    else if(fork_return == 0){
        while(1){
            recv(client_socket,recvMessage,sizeof(recvMessage),0);
            if(strncmp(recvMessage,_quit,4) == 0)   break;        
            printf("%s", recvMessage);
        }
    }
    close(client_socket);
    return 0;
}
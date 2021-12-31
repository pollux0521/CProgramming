#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode{									//구조체 이름 
	char data[4];
	struct ListNode* link;									//노드의 링크점 
}listNode;

typedef struct{
	listNode* head;											//링크드 리스트의 첫 부분을 가리킴 
}linkedList_h;

linkedList_h* createLinkedList_h(void){						//링크드리스트를 만들기 위해 빈보드를 만듬 
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));		//linkedList_h의 크기만근 메모리 할당 
	L->head = NULL;											//공백 리스트이므로 NULL 
	return L;
}

void freeLinkedList_h(linkedList_h* L){						//링크드리스트가 할당하고 있는 메모리를 헤제함 
	listNode*p;
	while(L->head != NULL){									//링크드리스트 첫부분을 바로 삭제하면 안되므로 
		p = L->head;										//그 다음 부분을 머리로 설정 한후 해제 
		L->head = L->head->link;
		free(p);
	}
}

void printList(linkedList_h* L){							//모든 노드 출력 
	listNode* p;
	printf("L = (");
	p = L->head;											//진짜 링크드리스트 값이 바뀌면 안되므로 p로 넘겨줌 
	while(p != NULL){										//p가 NULL이 아닐때까지 p의 데이터값 출력	
		printf("%s", p->data);
		p = p->link;										
		if(p!=NULL) printf(",");						
	}
	printf(") \n");
}

void insertFirstNode(linkedList_h* L, char *x){				//첫번째 노드를 집어넣는데 사용할 함수 
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = L->head;								//자기밖에 없으므로 head값이 자기 자신을 가르키게 함 
	L->head = newNode;
}

void insertMiddleNode(linkedList_h* L, listNode *pre, char *x){ // 두번째 노드를 집어넣는데 사용할 함수 
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if(L==NULL){												//L의 head값이 없으면
		newNode->link = NULL;									//newNode의 link값을 초기화하고 newNode가 head가 되게 만듬 
		L->head = newNode;
	}
	else if(pre == NULL){										//만약 이전노드가 없으면  
		L->head = newNode;										//newNode가 head가 되게만 함 
	}
	else{														//그렇지 않으면  newNode->link값 = pre->link값으로 설정하고 
		newNode->link = pre->link;								//pre->link값을 =newNode로 바꿈 
		pre->link = newNode;
	}
}

void insertLastNode(linkedList_h* L, char* x){					//마지막에 노드를 삽입할때 사용할 함수 
	listNode* newNode;
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data , x);
	newNode->link = NULL;
	if(L->head == NULL){										//head값이 비었으면 
		L->head = newNode;										//newNode를 head값으로 설정 
		return;
	}
	temp = L->head;												//진짜 head값이 변하면 안되므로 temp에 넘겨줌 
	while(temp->link != NULL)temp = temp->link;					//다음값이 없을때까지 temp를 temp->link 값으로 넘겨줌 
	temp->link = newNode;										//다넘겨준 다음 마지막에 temp->link를 newNode로 설정 
}

int main(){
	linkedList_h* L;											//리스트 헤드 선언 
	L = createLinkedList_h();									//리스트 초기화 
	printf("(1) 공백 리스트 생성하기\n");
	printList(L); getchar();									//리스트 생성됨을 보여줌 
	printf("(2) 리스트에 [수]노드 삽입하기\n");
	insertFirstNode(L, "수");									//리스트 데이터에 '수'를 집어넣고 출력 
	printList(L); getchar();
	
	printf("(3) 리스트에 마지막 노트 [금]노드 삽입하기\n");
	insertLastNode(L, "금");									//리스트의 마지막 데이터에 '금'을 집어넣고 출력 
	printList(L); getchar();
	
	printf("(4) 리스트 첫번째에 [월]노드 삽입하기\n");			//리스트의 head의 데이터에 '월'을 집어넣고 출력 
	insertFirstNode(L, "월");
	printList(L); getchar();
	
	printf("(5) 리스트 공간을 해제하여 공백 리스트 만들기\n");	//free를 사용해 리스트에 할당된 메모리를 해제시킴 
	freeLinkedList_h(L);
	printList(L); 
	
	getchar(); 
	
	return 0;
}

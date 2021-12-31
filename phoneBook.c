#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//구조체 링크드리스트 정의 
typedef struct ListNode
{
	char data[20];
	struct ListNode* next;
}ListNode;
// 헤드,테일노드가 들어있는 구조체 정의 
typedef struct __list
{
	struct __list *cur;
	struct __list *head;
	struct __list *tail;
}linkedList;

//노드 추가 
void Add(linkedList* L,char tdata[])
{
	int i;
	ListNode *p_node = NULL;
	ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));	
	for(i=0;i<20;i++)
	{	
	newNode->data[i] = tdata[i];								
	}
	newNode->next = NULL;									
	if(L->head == NULL)
	{ 
		L->head =newNode; 									 
	}
	else
	{
		p_node = L->head;
		while(p_node->nextn !=NULL)							
		{												   
			p_node = p_node->next; 
		}
		p_node->next=newNode;
	}
}
void printNodes(linkedList *L)
{
	ListNode *p = L->head;
	while(p != NULL)
	{
		printf("%s" , p->data);
		p = p->next;
		printf("\n");
	}
}
 
void Search(linkedList* L)
{
	ListNode* Node = (ListNode *)malloc(sizeof(ListNode));  
	int i=1;	
	printf("   전화번호목록\n");
	printf("--------------------\n");
	if(L->head == NULL)
	{
		printf("비어있네요!\n");
		exit(1);
	}
	else
	{
		Node = L->head;
		while(Node->data != NULL)
		{

			printf("%d. %s\n" , i, Node->data);
			Node = Node->next;								
			i++;
		} 
	}
	printf("--------------------\n");
	
}
void Delete(linkedList *L, char tdata[])
{
	int i;
	int x;
	ListNode* deleteNode = L->head;
	ListNode* Node = tdata[20];								
	if(L->head == NULL)
	{
		printf("Not Data im \n");
	}
	while(deleteNode != NULL)
	{
		x = 0;
		for(i=0;i<20;i++)
		{
				if(deleteNode->data[i] != tdata[i])	
				{									
					x++;
				}
		}
		
		
		if(x == 0)								
		{
			Node->next = deleteNode->next;
			
			free(deleteNode);
			break;
		}
		Node = deleteNode;
		deleteNode = deleteNode->next;
		
	}
	
}
int main()
{
	int x,i;
	char phone_number[20];

	linkedList *L = (linkedList *)malloc(sizeof(linkedList));
	L->cur=NULL;												
	L->head=NULL;
	L->tail=NULL;
	
	int a=0;
	char tdata[20]=
	{
		"******************"
	};
	ListNode *p_node = NULL;
	
	ListNode *newnewNode = (ListNode*)malloc(sizeof(ListNode));
	for(a=0;a<20;a++)
	{
		newnewNode->data[i]= tdata[20];
	}
	newnewNode->next=NULL;
		if(L->head == NULL)
	{ 
		L->head =newnewNode; 									
	}
	else
	{
		p_node = L->head;
		while(p_node->next !=NULL)								
		{													   
			p_node = p_node->next; 
		}
		p_node->next=newnewNode;
	}
	
	while(1)
	{
		printf("  ==*전화번호부 관리 프로그램*==\n");
		printf(" ∥1. 전화번호부 추가           ∥\n");
		printf(" ∥2. 모든 전화번호부 출력      ∥\n");
		printf(" ∥3. 전화번호 삭제             ∥\n");
		printf(" ∥4. 종료하기                  ∥\n");
		printf("  ===============================\n");
		printf("  ====> 입력:");
		scanf(" %d" , &x);										 

		if(x==1)
		{

			printf("전화번호와 이름을 입력하시오:\n");				
			printf("ex)홍길동_01012345678\n");
			scanf(" %s" , phone_number);
			printf(" %s\n" , phone_number);
			Add(L , phone_number);	
		}  
	    if(x==2)
		{
			Search(L);										
		}
		if(x==3)
		{
			printf("지우고 싶은 전화번호와 이름을 입력하시오:\n");
			printf("ex)홍길동_01012345678\n");
			scanf(" %s" , phone_number);
			Delete(L , phone_number);
			printf(" %s가 삭제되었습니다.\n" , phone_number);
		
		}
		if(x==4)
		{
			printf("프로그램을 종료합니다.");
			return 0; 
		}
	}	
	return 0;
}

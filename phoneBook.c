#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//����ü ��ũ�帮��Ʈ ���� 
typedef struct ListNode
{
	char data[20];
	struct ListNode* next;
}ListNode;
// ���,���ϳ�尡 ����ִ� ����ü ���� 
typedef struct __list
{
	struct __list *cur;
	struct __list *head;
	struct __list *tail;
}linkedList;

//��� �߰� 
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
	printf("   ��ȭ��ȣ���\n");
	printf("--------------------\n");
	if(L->head == NULL)
	{
		printf("����ֳ׿�!\n");
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
		printf("  ==*��ȭ��ȣ�� ���� ���α׷�*==\n");
		printf(" ��1. ��ȭ��ȣ�� �߰�           ��\n");
		printf(" ��2. ��� ��ȭ��ȣ�� ���      ��\n");
		printf(" ��3. ��ȭ��ȣ ����             ��\n");
		printf(" ��4. �����ϱ�                  ��\n");
		printf("  ===============================\n");
		printf("  ====> �Է�:");
		scanf(" %d" , &x);										 

		if(x==1)
		{

			printf("��ȭ��ȣ�� �̸��� �Է��Ͻÿ�:\n");				
			printf("ex)ȫ�浿_01012345678\n");
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
			printf("����� ���� ��ȭ��ȣ�� �̸��� �Է��Ͻÿ�:\n");
			printf("ex)ȫ�浿_01012345678\n");
			scanf(" %s" , phone_number);
			Delete(L , phone_number);
			printf(" %s�� �����Ǿ����ϴ�.\n" , phone_number);
		
		}
		if(x==4)
		{
			printf("���α׷��� �����մϴ�.");
			return 0; 
		}
	}	
	return 0;
}

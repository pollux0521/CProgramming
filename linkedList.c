#include <stdio.h>
#include <stdlib.h>
 
typedef struct __list
{
	struct __node *cur;
	struct __node *head;
	struct __node *tail;
}linkedList;

typedef struct __node
{
	char data[15];
	struct __node * next;
}node;

void createNode(linkedList *L , char tdata[])
{
	int i;
	node *p_node = NULL;
	node *newnode = (node*)malloc(sizeof(node));
		  for(i = 0; i < 15; i++)
		  {
		  newnode->data[i] = tdata[i];
		  }
		  newnode->next = NULL;
	if(L->head == NULL) {
		L->head = newnode;
	}
		
	else
	{
		p_node = L->head;
		while( p_node->next != NULL) {
			p_node = p_node->next;
		} 
		p_node->next = newnode;
	}
 }
  
void printNodes(linkedList *L)
{
	node *p = L->head;
	while(p != NULL)
	{
		printf("%s" , p->data);
		p = p->next;
		printf("\n");
	}
}



int main()
{
	int x,i;
	char phone_number[15];
	linkedList *L = (linkedList *)malloc(sizeof(linkedList));
	L->cur=NULL;
	L->head=NULL;
	L->tail=NULL;
	while(1)
	{
	printf("번호를 입력하시오");
	scanf(" %d" , &x); 
	
		if(x == 1)
		{
		printf("입력:");
		
		scanf(" %s" , phone_number);
		
		printf(" %s\n" , phone_number);
		
		createNode(L , phone_number);
		}
		else 
		{
		printNodes(L);
		}
	}
	return 0;
} 


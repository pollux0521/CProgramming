#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode{									//����ü �̸� 
	char data[4];
	struct ListNode* link;									//����� ��ũ�� 
}listNode;

typedef struct{
	listNode* head;											//��ũ�� ����Ʈ�� ù �κ��� ����Ŵ 
}linkedList_h;

linkedList_h* createLinkedList_h(void){						//��ũ�帮��Ʈ�� ����� ���� �󺸵带 ���� 
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));		//linkedList_h�� ũ�⸸�� �޸� �Ҵ� 
	L->head = NULL;											//���� ����Ʈ�̹Ƿ� NULL 
	return L;
}

void freeLinkedList_h(linkedList_h* L){						//��ũ�帮��Ʈ�� �Ҵ��ϰ� �ִ� �޸𸮸� ������ 
	listNode*p;
	while(L->head != NULL){									//��ũ�帮��Ʈ ù�κ��� �ٷ� �����ϸ� �ȵǹǷ� 
		p = L->head;										//�� ���� �κ��� �Ӹ��� ���� ���� ���� 
		L->head = L->head->link;
		free(p);
	}
}

void printList(linkedList_h* L){							//��� ��� ��� 
	listNode* p;
	printf("L = (");
	p = L->head;											//��¥ ��ũ�帮��Ʈ ���� �ٲ�� �ȵǹǷ� p�� �Ѱ��� 
	while(p != NULL){										//p�� NULL�� �ƴҶ����� p�� �����Ͱ� ���	
		printf("%s", p->data);
		p = p->link;										
		if(p!=NULL) printf(",");						
	}
	printf(") \n");
}

void insertFirstNode(linkedList_h* L, char *x){				//ù��° ��带 ����ִµ� ����� �Լ� 
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = L->head;								//�ڱ�ۿ� �����Ƿ� head���� �ڱ� �ڽ��� ����Ű�� �� 
	L->head = newNode;
}

void insertMiddleNode(linkedList_h* L, listNode *pre, char *x){ // �ι�° ��带 ����ִµ� ����� �Լ� 
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if(L==NULL){												//L�� head���� ������
		newNode->link = NULL;									//newNode�� link���� �ʱ�ȭ�ϰ� newNode�� head�� �ǰ� ���� 
		L->head = newNode;
	}
	else if(pre == NULL){										//���� ������尡 ������  
		L->head = newNode;										//newNode�� head�� �ǰԸ� �� 
	}
	else{														//�׷��� ������  newNode->link�� = pre->link������ �����ϰ� 
		newNode->link = pre->link;								//pre->link���� =newNode�� �ٲ� 
		pre->link = newNode;
	}
}

void insertLastNode(linkedList_h* L, char* x){					//�������� ��带 �����Ҷ� ����� �Լ� 
	listNode* newNode;
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data , x);
	newNode->link = NULL;
	if(L->head == NULL){										//head���� ������� 
		L->head = newNode;										//newNode�� head������ ���� 
		return;
	}
	temp = L->head;												//��¥ head���� ���ϸ� �ȵǹǷ� temp�� �Ѱ��� 
	while(temp->link != NULL)temp = temp->link;					//�������� ���������� temp�� temp->link ������ �Ѱ��� 
	temp->link = newNode;										//�ٳѰ��� ���� �������� temp->link�� newNode�� ���� 
}

int main(){
	linkedList_h* L;											//����Ʈ ��� ���� 
	L = createLinkedList_h();									//����Ʈ �ʱ�ȭ 
	printf("(1) ���� ����Ʈ �����ϱ�\n");
	printList(L); getchar();									//����Ʈ �������� ������ 
	printf("(2) ����Ʈ�� [��]��� �����ϱ�\n");
	insertFirstNode(L, "��");									//����Ʈ �����Ϳ� '��'�� ����ְ� ��� 
	printList(L); getchar();
	
	printf("(3) ����Ʈ�� ������ ��Ʈ [��]��� �����ϱ�\n");
	insertLastNode(L, "��");									//����Ʈ�� ������ �����Ϳ� '��'�� ����ְ� ��� 
	printList(L); getchar();
	
	printf("(4) ����Ʈ ù��°�� [��]��� �����ϱ�\n");			//����Ʈ�� head�� �����Ϳ� '��'�� ����ְ� ��� 
	insertFirstNode(L, "��");
	printList(L); getchar();
	
	printf("(5) ����Ʈ ������ �����Ͽ� ���� ����Ʈ �����\n");	//free�� ����� ����Ʈ�� �Ҵ�� �޸𸮸� ������Ŵ 
	freeLinkedList_h(L);
	printList(L); 
	
	getchar(); 
	
	return 0;
}

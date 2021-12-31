#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��弱��
typedef struct tagNode{
	char data;
	int degree;
	struct tagNode *child;
}Node; 
//Ʈ������
typedef struct tagTree{
	Node *root;
}Tree;

Node* newNode(char data); 						//���(���� , �ڽ�������)���� 
Tree* newTree();								//Ʈ��(���� , ���������� ��Ʈ)���� 
void PrintChild(Node *p);						//�ֵ� ���(�ڱ� �ٷ� �ؿ� �ִ� �͵�) 
void PreorderNode(Node* p);						//�ڽ��� �ֵ��� �ֵ����� ��� 
void PreorderTree(Tree* t);						//��Ʈ���� ���� ��� 
void NodeChangeData(Node* p, char data);		//
void ParentInsertChild(Node* p, char data);		//
void ParentDeleteChild(Node* p, char data);		//
void DeleteAllchild(Node* p);					//
//������
int main(void){
	char data = 'a';
	Node* node = NULL;
	Tree* tree = NULL;
	
	tree = newTree();
	node = newNode(data);
	PrintChild(node);
	return 0;	
}
Node* newNode(char data){
	Node* returnNode = (Node*)malloc(sizeof(Node));
	returnNode->data = data;
	returnNode->degree = 0;
	returnNode->child = NULL;
	return returnNode;
} 

Tree* newTree() {
	Tree* returnTree = (Tree*)malloc(sizeof(Tree));
	returnTree->root = NULL;
	return returnTree;
}
//���� ����� �ڽ��� ����� ����� �μ��ϴ� �ڵ� 
void PrintChild(Node *p){
	int i;
	
	if(p == NULL) { printf("��尡 �����ϴ�\n"); }
	else if (p->child == NULL) { printf("�ڽ� ��尡 �����ϴ�.\n"); }
	else{
		for(i=0; i < p->degree; i++) { 
		printf("%c" , p->child[i].data); 
		printf("\n");
		}
	}
}

void PreorderNode(Node *p){
	int i;
	
	if(p == NULL) { return;	}
	printf("%c" , p->data);
	for(i=0; i < p->degree; i++) { PreorderNode(&p->child[i]); }
}

void PreorderTree(Tree* t){
	printf("�������� ����\n");
	PreorderNode(t->root);
	printf("�������� ��\n");
}
//���� 
void NodeChangeData(Node *p, char data){
	p->data = data;
}
//����
void ParentInsertChild(Node *p, char data){
	p->child = (Node*)realloc(p->child , sizeof(Node) * (p->degree + 1));
	p->child[p->degree].data = data;
	p->child[p->degree].degree = 0;
	p->child[p->degree].child = NULL;
	p->degree++;
} 
//����

void DeleteAllchild(Node* p){
	int i;
	
	if(p == NULL) { return; }
	for(i=0; i < p->degree; i++) { DeleteAllChild(&(p->child)[i]); }
	free(p->child);
	p->degree = 0;
	p->child = NULL;
} 

void ParentDeleteChild(Node* p, char data){
	int i,j;
	
	for(i=0; i < p->degree; i++) { if(p->child[i].data == data) { break; } }
	if( i == p->degree){
		printf("�ڽ� �� ã�� �����Ͱ� �����ϴ�.\n");
		return ;
	}
	DeleteAllChild(&(p->child)[i]);
	for(j=i; j < p->degree -1; j++){
		p->child[j].child = p->child[j+1].child;
		p->child[j].data = p->child[j+1].data;
		p->child[j].degree = p->child[j+1].degree;
	}
	p->child = (Node*)realloc(p->child , sizeof(Node) * (p->degree - 1));
	p->degree--;
}


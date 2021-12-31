#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//노드선언
typedef struct tagNode{
	char data;
	int degree;
	struct tagNode *child;
}Node; 
//트리선언
typedef struct tagTree{
	Node *root;
}Tree;

Node* newNode(char data); 						//노드(공간 , 박스같은거)생성 
Tree* newTree();								//트리(나무 , 리눅스에선 루트)생성 
void PrintChild(Node *p);						//애들 출력(자기 바로 밑에 있는 것들) 
void PreorderNode(Node* p);						//자신의 애들의 애들들까지 출력 
void PreorderTree(Tree* t);						//루트부터 전부 출력 
void NodeChangeData(Node* p, char data);		//
void ParentInsertChild(Node* p, char data);		//
void ParentDeleteChild(Node* p, char data);		//
void DeleteAllchild(Node* p);					//
//생성자
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
//전위 운행과 자식의 노드의 목록을 인쇄하는 코드 
void PrintChild(Node *p){
	int i;
	
	if(p == NULL) { printf("노드가 없습니다\n"); }
	else if (p->child == NULL) { printf("자식 노드가 없습니다.\n"); }
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
	printf("전위운행 시작\n");
	PreorderNode(t->root);
	printf("전위운행 끝\n");
}
//갱신 
void NodeChangeData(Node *p, char data){
	p->data = data;
}
//삽입
void ParentInsertChild(Node *p, char data){
	p->child = (Node*)realloc(p->child , sizeof(Node) * (p->degree + 1));
	p->child[p->degree].data = data;
	p->child[p->degree].degree = 0;
	p->child[p->degree].child = NULL;
	p->degree++;
} 
//삭제

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
		printf("자식 중 찾는 데이터가 없습니다.\n");
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


#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node * lchild;
	struct node * rchild;
}BinTree;

BinTree * create(){
	BinTree * t;
	char ch;
	ch = getchar();
	if(ch!='0'){
		t = (BinTree *)malloc(sizeof(BinTree));
		t->data = ch;
		t->lchild = create();
		t->rchild = create();
	}
	else{
		t = NULL;
	}
	return t;
}

void listBinTree(BinTree * t){
	if(t!=NULL){
		printf("%c",t->data);
		if(t->lchild != NULL || t->rchild != NULL){
			printf("(");
			listBinTree(t->lchild);
			if(t->rchild != NULL){
				printf(",");
			}
			listBinTree(t->rchild);
			printf(")");
		}
	}
}

int main(){
	BinTree * t = NULL;
	printf("输入树\n");
	t = create();
	printf("广义表输出:\n");
	listBinTree(t);
	printf("\n");
	return 0;
}

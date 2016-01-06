#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define MAX 100


typedef struct node{
	char data;
	struct node * lchild;
	struct node * rchild;
}BinTree;

//计数
int count=0;


BinTree * create(){
	BinTree * t;
	char c;
	c = getchar();
	if(c == '0'){
		t = NULL;
	}
	else{
		t = (BinTree *)malloc(sizeof(BinTree));
		t->data = c;
		t->lchild = create();
		t->rchild = create();
	}

	return t;
}


//以广义表方式输出
void listBinTree(BinTree * t){
	if(t != NULL){
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


//先序
void preOrder(BinTree * t){
	if(t != NULL){
		printf("%3c",t->data);
		preOrder(t->lchild);
		preOrder(t->rchild);
	}
}


//中序
void inOrder(BinTree * t){
	if(t != NULL){
		inOrder(t->lchild);
		printf("%3c",t->data);
		inOrder(t->rchild);
	}
}


//后序
void lastOrder(BinTree * t){
	if(t != NULL){
		lastOrder(t->lchild);
		lastOrder(t->rchild);
		printf("%3c",t->data);
	}
}


//层次遍历,借助队列实现
void levelOrder(BinTree * t){
	BinTree * queue[MAX];		//指针数组
	int front=-1;
	int rear=0;
	if(t == NULL){
		return;
	}
	else{
		queue[rear] = t;			//表示队尾
		while(front != rear){		//当front==rear时队列结束
			front++;
			printf("%3c",queue[front]->data);		//输出队头指针所指向的数据,整个队列数据的读取都靠这句
			if(queue[rear]->lchild != NULL){		//当左子树不为空
				rear++;
				queue[rear] = queue[front]->lchild;
			}
			if(queue[rear]->rchild != NULL){		//当右子树不为空
				rear++;
				queue[rear] = queue[front]->rchild;
			}
		}
	}
}


//查找值为data的节点
void search(BinTree * t,int data){
	BinTree * p = t;
	if(p){
		if(p->data==data){
			printf("节点存在!\n");
		}
		else{
			search(p->lchild,data);
			search(p->rchild,data);
		}
	}
}


//求该二叉树的节点数
void leafWholeNum(BinTree * t){
	if(t!=NULL){
		count++;
		leafWholeNum(t->lchild);
		leafWholeNum(t->rchild); 
	}
}


//求该二叉树的叶子节点
void leafNodeNum(BinTree * t){
	if(t!=NULL){
		//当该节点没有后继时，该节点便为叶子节点
		if(t->lchild==NULL&&t->rchild==NULL){
			count++;
		}
		leafNodeNum(t->lchild);
		leafNodeNum(t->rchild);
	}
} 


//求该二叉树的深度
int  treeDepth(BinTree * t){
	int ldp,rdp;
	if(t==NULL){
		return 0;
	}
	else{
		ldp = treeDepth(t->lchild);
		rdp = treeDepth(t->rchild);
		if(ldp>rdp){
			count = ldp+1;
		}
		else{
			count = rdp+1;
		}
	}
}


int main(){
	BinTree * t = NULL;
	int data;
	int wholeLeaves;

	printf("请输入数据来初始化树，以广义表形式输出:\n");
	t = create();
	printf("初始值:\n");
	listBinTree(t);
	printf("\n");

	printf("先序:\n");
	preOrder(t);
	printf("\n");

	printf("中序:\n");
	inOrder(t);
	printf("\n");

	printf("后序:\n");
	lastOrder(t);
	printf("\n");
	
	printf("层次遍历:\n");
	levelOrder(t);
	printf("\n");

	printf("输入您要查找的数据:\n");
	scanf("%d",&data);
	search(t,data);
	printf("\n");

	leafWholeNum(t);
	printf("节点总个数:%d\n",count);

	count = 0;
	leafNodeNum(t);
	printf("叶子节点个数:%d\n",count);

	
	count = treeDepth(t);
	printf("该树的深度为:%d\n",count);

	return 0;
}

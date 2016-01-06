#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MAX 100

//表节点
typedef struct adjnode{
	//领接顶点域
	int adjvex;
	//指针域
	struct adjnode * next;
}ARCNODE;

//定义头节点
typedef struct headnode{
	//顶点域
	int vertex;
	//边表头指针
	ARCNODE * firstarc;
}VEXNODE;

//定义一个头节点数组
VEXNODE vexnum[MAX];

//建立领接表
int create(){
	ARCNODE * ptr;
	int vexnums,arcnums,v1,v2,i;
	printf("请输入顶点,边数:\n");
	scanf("%d,%d",&vexnums,&arcnums);
	//初始化边节点
	for(i=0; i<vexnums; i++){
		vexnum[i].firstarc = NULL;
	}
	for(i=0; i<arcnums; i++){
		printf("请输入v1,v2:\n");
		scanf("%d,%d",&v1,&v2);
		//分配表节点的空间
		ptr = (ARCNODE *)malloc(sizeof(ARCNODE));
		//将顶点v2插入到链表内
		ptr->adjvex = v2;
		ptr->next = vexnum[v1].firstarc;
		vexnum[v1].firstarc = ptr;
	}
	return vexnums;
}

int main(){
	int i,n;
	ARCNODE * p;
	//获得顶点数
	n = create();
	printf("所建的领接表为:\n");
	for(i=0; i<n; i++){
		printf("%d=>",i);
		p = vexnum[i].firstarc;
		while(p!=NULL){
			printf("--->%d",p->adjvex);
			p = p->next;
		}
		//每循环一次回车一行
		printf("\n");
	}
	return 0;
}


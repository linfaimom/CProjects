#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100


typedef int ElemType;

typedef struct{  //建立一个线性表结构体 
	ElemType elem[MAXSIZE];
	int len;
}SeqList;

void main(){
	int l;  //用于接收表长度 
	int position;  //插入位置 
	int data;  //插入数据 
	int i;
	SeqList * seq;
	int InsertSeqlist(SeqList * seq, int position, ElemType data);
	seq = (SeqList *)malloc(sizeof(SeqList));
	printf("请输入表的长度:\n");
	scanf("%d",&l);
	seq->len=l;
	printf("请初始化表中的值:\n");
	for(i=1;i<=seq->len;i++){
		scanf("%d",&seq->elem[i]);
	}
	printf("请输入你要插入的位置:\n");
	scanf("%d",&position);
	printf("请输入你要插入的数据:\n");
	scanf("%d",&data);
	InsertSeqlist(seq,position,data); 
	for(i=1;i<=seq->len;i++){  //此处弃用elem[0] 
		printf("%d\t",seq->elem[i]);
	}
	printf("\n");
}

int InsertSeqlist(SeqList * seq, int position, int data){
	int j;
	
	//判断插入是否合法
	if((position<1)||(position>seq->len+1)){
		printf("插入位置不合法！");
		return 0; 
	}
	if(seq->len>=MAXSIZE-1){
		printf("表已满无法插入!");
		return 0;
	}
	
	for(j=seq->len;j>=position;j--){
		seq->elem[j+1]=seq->elem[j];  //向后移动数据，腾出要插入的空位 
	}
	seq->elem[j+1]=data;
	(seq->len)++;  //表长加1 
	return 1;
}

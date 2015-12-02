#include <stdio.h>
#define MAXSIZE 100
#define ERROR 0
#define OK 1

typedef int ElemType;
typedef struct{
	ElemType data[MAXSIZE];
	int front,rear;  								//定义队头和队尾指针 
}SeqQueue;

SeqQueue InitQueue(){
	SeqQueue q;
	q.front=-1;
	q.rear=-1;
	return q;
}

int InQueue(SeqQueue * q, ElemType data){			//入队 
	if(q->rear>=MAXSIZE-1){
		printf("队列已满，无法插入!\n");
		return ERROR;
	}
	else{
 		q->rear++;
		(q->data)[q->rear]=data;
		return OK;
	}
}

int OutQueue(SeqQueue * q, ElemType * showData){	//出队 
	if(q->front==q->rear){
		printf("队列无元素!\n");
		return ERROR;
	}
	else{
		q->front++;
		*showData=(q->data)[q->front];
		return OK;
	}
} 

int isEmpty(SeqQueue * q){							//判空 
	return (q->front==q->rear);
}

void print(SeqQueue * q){
	int i;
	if(q->front==q->rear){
		printf("队列为空！\n");
	}
	else{
		printf("队列中的元素为:\n");
		for(i=q->front+1;i<=q->rear;i++){
			printf("%d\t",q->data[i]);
		}
	}
	printf("\n");
}

int main(){
	SeqQueue q;
	int data,showData,size,num,i; 
	q=InitQueue();
	printf("请输入队列大小:\n");
	scanf("%d",&size);
	printf("请输入队列中的值:\n");
	for(i=1;i<=size;i++){
		scanf("%d",&data);
		InQueue(&q,data);
	}
	print(&q);
	//printf("队首元素为:\n");
	//OutQueue(&q,&showData);
	//printf("%d\n",showData);
	printf("请输入要出队的个数:\n");
	scanf("%d",&num);
	printf("出队的元素为:\n");
	for(i=0;i<num;i++){
		OutQueue(&q,&showData);
		printf("%d\t",q.data[i]);
	}
	printf("\n");
	print(&q);
} 
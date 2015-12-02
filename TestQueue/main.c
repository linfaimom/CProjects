#include <stdio.h>
#define MAXSIZE 100
#define ERROR 0
#define OK 1

typedef int ElemType;
typedef struct{
	ElemType data[MAXSIZE];
	int front,rear;  								//�����ͷ�Ͷ�βָ�� 
}SeqQueue;

SeqQueue InitQueue(){
	SeqQueue q;
	q.front=-1;
	q.rear=-1;
	return q;
}

int InQueue(SeqQueue * q, ElemType data){			//��� 
	if(q->rear>=MAXSIZE-1){
		printf("�����������޷�����!\n");
		return ERROR;
	}
	else{
 		q->rear++;
		(q->data)[q->rear]=data;
		return OK;
	}
}

int OutQueue(SeqQueue * q, ElemType * showData){	//���� 
	if(q->front==q->rear){
		printf("������Ԫ��!\n");
		return ERROR;
	}
	else{
		q->front++;
		*showData=(q->data)[q->front];
		return OK;
	}
} 

int isEmpty(SeqQueue * q){							//�п� 
	return (q->front==q->rear);
}

void print(SeqQueue * q){
	int i;
	if(q->front==q->rear){
		printf("����Ϊ�գ�\n");
	}
	else{
		printf("�����е�Ԫ��Ϊ:\n");
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
	printf("��������д�С:\n");
	scanf("%d",&size);
	printf("����������е�ֵ:\n");
	for(i=1;i<=size;i++){
		scanf("%d",&data);
		InQueue(&q,data);
	}
	print(&q);
	//printf("����Ԫ��Ϊ:\n");
	//OutQueue(&q,&showData);
	//printf("%d\n",showData);
	printf("������Ҫ���ӵĸ���:\n");
	scanf("%d",&num);
	printf("���ӵ�Ԫ��Ϊ:\n");
	for(i=0;i<num;i++){
		OutQueue(&q,&showData);
		printf("%d\t",q.data[i]);
	}
	printf("\n");
	print(&q);
} 
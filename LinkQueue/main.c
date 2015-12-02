#include <stdio.h>
#define OK 1
#define ERROR 0

typedef int ElemType;

typedef struct Node{
	ElemType data;
	struct Node * next;
}Node;

typedef struct{
	Node * front;
	Node * rear; 
}LinkQueue;

int InitQueue(LinkQueue * q){
	q->front=(Node*)malloc(sizeof(Node));
	if(q->front!=NULL){
		q->rear=q->front;
		q->front->next=NULL;
		return OK;
	}
	else{
		return ERROR;
	}
}

int InQueue(LinkQueue * q, ElemType	data){
	Node * current;
	current=(Node*)malloc(sizeof(Node));
	if(current!=NULL){
		current->data=data;
		q->rear->next=current;
		q->rear=current;
		return OK;
	}
	else{
		return ERROR;
	}
}

int isEmpty(LinkQueue * q){
	if(q->front==q->rear){
		return OK;
	}
	else{
		return ERROR;
	}
}

int OutQueue(LinkQueue * q, ElemType * showData){
	Node * temp;
	if(q->front==q->rear){
		return ERROR;
	}
	else{
		temp=q->front->next;
		q->front->next=temp->next;
		if(q->rear==temp){							//�������ֻ��һ��Ԫ��,���ø�Ԫ�س��Ӻ󣬸öӱ�ɿն� 
			q->rear=q->front;
		}
		*showData=temp->data;
		free(temp);
		return OK; 
	}
} 

void print(LinkQueue * q){
	while(q->front!=q->rear){
		printf("%d\t",q->front->next->data);
		q->front=q->front->next;
	}
} 

int main(int argc, char *argv[])
{
	int i,num;
	ElemType data,showData;
	LinkQueue queue;
	InitQueue(&queue);
	printf("������Ҫ��ӵ�Ԫ�ظ���:\n");
	scanf("%d",&num);
	printf("������Ҫ��ӵ�Ԫ��:\n");
	for(i=1;i<=num;i++){
		scanf("%d",&data);
		InQueue(&queue,data);
	}
	print(&queue);
} 
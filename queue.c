#include <stdio.h>
#include <stdlib.h>
#define OK 0
#define ERROR 1
#define MAX 100

typedef int ElemType;

typedef struct Queue{
	ElemType data[MAX];
	int head;
	int tail;
}Queue;

Queue initQueue(){
	Queue init;
	init.head = -1;
	init.tail = -1;
	return init;
}

int create(Queue * current){
	int n,data;
	printf("输入队列长度:\n");
	scanf("%d",&n);
	while(n){
		scanf("%d",&data);
		current->data[current->tail+1] = data;
		(current->tail)++;
		n--;
	}
	return OK;
}

int main(){
	Queue queue;
	int i;
	queue = initQueue();
	create(&queue);
	if(queue.head!=queue.tail){
		for(i=queue.head+1;i<=queue.tail;i++){
			printf("%d\n",queue.data[i]);
		}
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define OK 0
#define ERROR 1

typedef int ElemType;

typedef struct Stack{
	ElemType data;
	struct Stack * next;
}Stack;

Stack * create(){
	Stack * current,*top;
	top = NULL;
	int n,data;
	printf("输入个数:\n");
	scanf("%d",&n);
	while(n){
		current = (Stack *)malloc(sizeof(Stack));
		scanf("%d",&data);
		current->data = data;
		current->next = top;
		top = current;
		n--;
	}
	return top;
}

int main(){
	Stack * pointer;
	Stack * create();
	pointer = create();
	pointer = pointer->next;
	while(pointer!=NULL){
		printf("%d\n",pointer->data);
		pointer = pointer->next;
	}
	return 0;
}

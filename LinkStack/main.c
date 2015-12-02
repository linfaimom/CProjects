#include <stdio.h>
#define TRUE 1
#define FALSE 0


typedef int DataType;
typedef struct StackNode{
	DataType data;
	struct StackNode * next;
}StackNode;

StackNode * Create(){
	StackNode * top, * current;
	int num,i;
	int data;
	top=NULL;
	printf("请输入链栈元素个数：\n");
	scanf("%d",&num);
	printf("请输入链栈中的%d个元素:\n",num); 
	for(i=1;i<=num;i++){
		scanf("%d",&data);
		current=(StackNode *)malloc(sizeof(StackNode));
		current->data=data;
		current->next=top;
		top=current;
	}
	
	return (top);
}

StackNode * Push(StackNode * top, DataType data){
	StackNode * current;
	current=(StackNode *)malloc(sizeof(StackNode));
	current->data=data;
	current->next=top;
	top=current;
	
	return (top);
}

StackNode * Pop(StackNode * top, DataType * data){
	StackNode * temp;
	temp=top;
	*data=top->data;
	top=top->next;
	free(temp);
	
	return (top);
}

void print(StackNode * top){
	StackNode * current;
	current=top;
	if(current!=NULL){
		printf("输出链栈中的数据:\n");
		while(current!=NULL){
			printf("%d\t",current->data);
			current=current->next;
		}
	}
	else{
		printf("链栈为空！\n");
	}
	printf("\n");
}

int main(){
	StackNode * stack;
	int data,showData;
	stack=Create();  //接收了函数返还的top指针
	print(stack); 
	printf("请输入要入栈的数据:\n");
	scanf("%d",&data);
	stack=Push(stack,data);
	print(stack);
	printf("取出栈顶元素:\n"); 
	stack=Pop(stack,&showData);
	printf("栈顶元素为:%d\n",showData);
	printf("当前栈内元素为:\n");
	print(stack);
}
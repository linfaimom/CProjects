#include <stdio.h>
#include <stdlib.h> 
#define MAXSIZE 10
#define TRUE 1;
#define FALSE 0; 

typedef int DataType;
typedef struct Stack{
	DataType stack[MAXSIZE];
	int top;
}SeqStack;

void InitStack(SeqStack * s){
	s->top=-1;
}

int isEmpty(SeqStack * s){
	if(s->top<=-1){
		return TRUE;
	}
	else{
		return FALSE;
	}
}

int Push(SeqStack * s, DataType data){
	if(s->top>=MAXSIZE-1){
		printf("栈已满无法插入");
		return FALSE;
	}
	else{
		s->top++;
		s->stack[s->top]=data;
		return TRUE;
	}
}

int Pop(SeqStack * s, DataType * data){
	if(s->top<=-1){
		printf("栈已空，没有数据可取\n");
		return FALSE;
	}
	else{
		*data = s->stack[s->top];
		s->top--;
		return TRUE;
	}
}

int getTop(SeqStack * s, DataType * data){
	if(s->top<=-1){
		printf("栈已空，没有数据可取\n");
		return FALSE;
	}
	else{
		data = s->stack[s->top];
		return TRUE;
	}
}

void print(SeqStack	* s){
	int i;
	if(s->top==-1){
		printf("栈为空！\n");
	}
	else{
		printf("你输入的数据为:\n");
		for(i=0;i<=s->top;i++){
			printf("%d\t",s->stack[i]);
		}
	}
} 

int main(){
	//创建一个栈 (不能为SeqStack * stack,因为没有具体的指向，亲测！)
	SeqStack stack;
	//初始化栈
	InitStack(&stack);
	printf("%d\n",stack.top);
	int i,data,outputData;
	if(isEmpty(&stack)==1){
		printf("栈为空！\n"); 
	}
	else{
		printf("栈非空！\n");
	}
	printf("请输入栈中的5个数据:\n");
	for(i=1;i<=5;i++){
		scanf("%d",&data);
		Push(&stack,data);
	}
	print(&stack);
	printf("\n");
	printf("当前top位置:");
	printf("%d\n",stack.top);
	printf("取出栈中的3个数据:\n");
	for(i=1;i<=3;i++){
		Pop(&stack,&outputData);
		printf("%d\t",outputData);
	}
	printf("\n");
    printf("当前top位置:");
	printf("%d\n",stack.top);
	printf("再取出栈中的2个数据:\n");
	for(i=1;i<=2;i++){
		Pop(&stack,&outputData);
		printf("%d\t",outputData);
	}
	printf("\n");
	printf("当前top位置:");
	printf("%d\n",stack.top);
	//再次尝试输出栈数据，栈内数据已全部输出，top为-1,栈为空
	print(&stack); 
}
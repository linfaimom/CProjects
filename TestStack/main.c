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
		printf("ջ�����޷�����");
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
		printf("ջ�ѿգ�û�����ݿ�ȡ\n");
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
		printf("ջ�ѿգ�û�����ݿ�ȡ\n");
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
		printf("ջΪ�գ�\n");
	}
	else{
		printf("�����������Ϊ:\n");
		for(i=0;i<=s->top;i++){
			printf("%d\t",s->stack[i]);
		}
	}
} 

int main(){
	//����һ��ջ (����ΪSeqStack * stack,��Ϊû�о����ָ���ײ⣡)
	SeqStack stack;
	//��ʼ��ջ
	InitStack(&stack);
	printf("%d\n",stack.top);
	int i,data,outputData;
	if(isEmpty(&stack)==1){
		printf("ջΪ�գ�\n"); 
	}
	else{
		printf("ջ�ǿգ�\n");
	}
	printf("������ջ�е�5������:\n");
	for(i=1;i<=5;i++){
		scanf("%d",&data);
		Push(&stack,data);
	}
	print(&stack);
	printf("\n");
	printf("��ǰtopλ��:");
	printf("%d\n",stack.top);
	printf("ȡ��ջ�е�3������:\n");
	for(i=1;i<=3;i++){
		Pop(&stack,&outputData);
		printf("%d\t",outputData);
	}
	printf("\n");
    printf("��ǰtopλ��:");
	printf("%d\n",stack.top);
	printf("��ȡ��ջ�е�2������:\n");
	for(i=1;i<=2;i++){
		Pop(&stack,&outputData);
		printf("%d\t",outputData);
	}
	printf("\n");
	printf("��ǰtopλ��:");
	printf("%d\n",stack.top);
	//�ٴγ������ջ���ݣ�ջ��������ȫ�������topΪ-1,ջΪ��
	print(&stack); 
}
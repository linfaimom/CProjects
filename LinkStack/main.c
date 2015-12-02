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
	printf("��������ջԪ�ظ�����\n");
	scanf("%d",&num);
	printf("��������ջ�е�%d��Ԫ��:\n",num); 
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
		printf("�����ջ�е�����:\n");
		while(current!=NULL){
			printf("%d\t",current->data);
			current=current->next;
		}
	}
	else{
		printf("��ջΪ�գ�\n");
	}
	printf("\n");
}

int main(){
	StackNode * stack;
	int data,showData;
	stack=Create();  //�����˺���������topָ��
	print(stack); 
	printf("������Ҫ��ջ������:\n");
	scanf("%d",&data);
	stack=Push(stack,data);
	print(stack);
	printf("ȡ��ջ��Ԫ��:\n"); 
	stack=Pop(stack,&showData);
	printf("ջ��Ԫ��Ϊ:%d\n",showData);
	printf("��ǰջ��Ԫ��Ϊ:\n");
	print(stack);
}
/*ʹ��β�巨�������ò�����ŵķ�ʽ����ֵ*/ 

#include <stdio.h>

typedef int ElemType;

typedef struct Node{
	ElemType data;
	struct Node * next;
}Node;

int main(int argc, char *argv[])
{
	//���������Ӻ��� 
	Node * create();
	Node * find(Node * head, int number);
	Node * a, * b;
	int number;
	printf("�����������е�ֵ:\n");
	a=create();  //�����Ӻ���������headָ�� 
	//a=a->next;	
	printf("��������Ҫ���ҵ���ֵ�����:\n");
	scanf("%d",&number);
	b=find(a,number);
	if(b!=NULL){
		printf("�ҵ���Ԫ��Ϊ:\n");
		printf("%5d\n",b->data);
	}
	else{
		printf("��û�д�Ԫ��\n");
	}
}

Node * create(){
	Node * head, * previous, * current;
	int a;
	char ch='!';
	head = (Node *)malloc(sizeof(Node));
	previous=head;
	while(ch!='#'){
		scanf("%d",&a);
		current = (Node *)malloc(sizeof(Node));
		current->data=a;
		previous->next=current;
		previous=current;
		ch=getchar();
	}
	previous->next=NULL;
	return (head);
}

Node * find(Node * head, int number){
	int i=1;
	Node * p;
	p=head->next;
	while((p!=NULL)&&(i<number)){
		p=p->next;
		i++;
	}
	
	return (p);
} 
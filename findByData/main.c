/*ʹ��β�巨�������ò���ֵ�ķ�ʽ�������*/ 

#include <stdio.h>

typedef int ElemType;

typedef struct Node{
	ElemType data;
	struct Node * next;
}Node;

int main(int argc, char *argv[])
{
	//�����ĸ��Ӻ��� 
	Node * InsertData(Node * head, int position, int data);
	void Delete(Node * head, int data);
	Node * create(int n);
	Node * find(Node * head, int data);
	Node * a, * b;
	int data;
	int n;
	printf("������������:\n");
	scanf("%d",&n);
	printf("�����������е�ֵ:\n");
	a=create(n);  //�����Ӻ���������headָ�� 
	//a=a->next;  //ָ���һ���ڵ�
	
	//���Ҳ���	
	/*
	printf("��������Ҫ���ҵ���ֵ:\n");
	scanf("%d",&data);
	b=find(a,data);
	if(b!=NULL){
		printf("�ҵ���Ԫ��Ϊ:\n");
		printf("%5d\n",b->data);
	}
	else{
		printf("��û�д�Ԫ��\n");
	}
	*/
	
	
	printf("\n");
	
	
	//ɾ������
	/* 
	printf("��������Ҫɾ��������:\n");
	scanf("%d",&data);
	Delete(a,data);
	printf("ɾ���������Ϊ:\n");
	b=a;
	while(b!=NULL){
		printf("%d\t",b->data);
		b=b->next;
	}
	*/
	
	
	printf("\n");
	
	//�������
	b=InsertData(a,5,10);
	b=b->next;
	printf("����������Ϊ:\n");
	while(b!=NULL){
		printf("%d\t",b->data);
		b=b->next;
	} 
	
	
	printf("\n");
	
}

Node * create(int n){
	Node * head, * previous, * current;
	int a;
	int i=0;
	char ch='!';
	head = (Node *)malloc(sizeof(Node));
	previous=head;
	while(i<n){
		scanf("%d",&a);
		current = (Node *)malloc(sizeof(Node));
		current->data=a;
		previous->next=current;
		previous=current;
		i++;
	}
	previous->next=NULL;
	return (head);
}

Node * find(Node * head, int data){
	Node * p;
	p=head->next;
	while((p!=NULL)&&(p->data!=data)){
		p=p->next;
	}
	return (p);
} 

void Delete(Node * head, int data){
	Node * previous, * current, * temp;
	previous=head;
	current=previous->next;
	while((current!=NULL)&&(current->data!=data)){
		previous=current;
		current=current->next;
	}
	if(current==NULL){
		printf("%d������.\n",data);
	}
	else{
		temp = current;
		previous->next=current->next;  //��������ɾ���ڵ�
		free(temp);   //�ͷ��ڴ� 
	}
	
} 

Node * InsertData(Node * head, int position, int data){
	int j=1;
	Node * previous, * temp;
	previous=head;
	while((j!=position)&&(previous->next!=NULL)){
		previous=previous->next;
		j++;
	}
	temp = (Node *)malloc(sizeof(Node));
	temp->data=data;
	temp->next=previous->next;
	previous->next=temp;
	return (head);
}
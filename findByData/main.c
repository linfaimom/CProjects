/*使用尾插法建表，利用查找值的方式查找序号*/ 

#include <stdio.h>

typedef int ElemType;

typedef struct Node{
	ElemType data;
	struct Node * next;
}Node;

int main(int argc, char *argv[])
{
	//声明四个子函数 
	Node * InsertData(Node * head, int position, int data);
	void Delete(Node * head, int data);
	Node * create(int n);
	Node * find(Node * head, int data);
	Node * a, * b;
	int data;
	int n;
	printf("请输入链表长度:\n");
	scanf("%d",&n);
	printf("请输入链表中的值:\n");
	a=create(n);  //接受子函数返还的head指针 
	//a=a->next;  //指向第一个节点
	
	//查找操作	
	/*
	printf("请输入你要查找的数值:\n");
	scanf("%d",&data);
	b=find(a,data);
	if(b!=NULL){
		printf("找到的元素为:\n");
		printf("%5d\n",b->data);
	}
	else{
		printf("并没有此元素\n");
	}
	*/
	
	
	printf("\n");
	
	
	//删除操作
	/* 
	printf("请输入你要删除的数据:\n");
	scanf("%d",&data);
	Delete(a,data);
	printf("删除后的链表为:\n");
	b=a;
	while(b!=NULL){
		printf("%d\t",b->data);
		b=b->next;
	}
	*/
	
	
	printf("\n");
	
	//插入操作
	b=InsertData(a,5,10);
	b=b->next;
	printf("插入后的链表为:\n");
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
		printf("%d不存在.\n",data);
	}
	else{
		temp = current;
		previous->next=current->next;  //跳过，即删除节点
		free(temp);   //释放内存 
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
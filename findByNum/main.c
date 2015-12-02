/*使用尾插法建表，利用查找序号的方式查找值*/ 

#include <stdio.h>

typedef int ElemType;

typedef struct Node{
	ElemType data;
	struct Node * next;
}Node;

int main(int argc, char *argv[])
{
	//声明两个子函数 
	Node * create();
	Node * find(Node * head, int number);
	Node * a, * b;
	int number;
	printf("请输入链表中的值:\n");
	a=create();  //接受子函数返还的head指针 
	//a=a->next;	
	printf("请输入你要查找的数值的序号:\n");
	scanf("%d",&number);
	b=find(a,number);
	if(b!=NULL){
		printf("找到的元素为:\n");
		printf("%5d\n",b->data);
	}
	else{
		printf("并没有此元素\n");
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
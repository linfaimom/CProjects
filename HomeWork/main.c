#include <stdio.h>
#define OK 0
#define ERROR 1;

typedef struct Node{
	int data;
	struct Node * next;
	
}Node,*LinkList;

int main(){
	//½¨Á¢¿ÕÁ´±í 
	LinkList H;
	H = (LinkList)malloc(sizeof(Node));
	H->next=NULL;
	
	void CreateFromHead(LinkList H);
	CreateFromHead(H);
	
}

void CreateFromHead(LinkList H){
	LinkList s;
	char c;
	while(c=getchar()!='$'){
		s = (LinkList)malloc(sizeof(Node));
		s->data=c;
		s->next=H->next;
		H->next=s;
	}
	
}
#include <stdio.h>
#include <stdlib.h>

//定义结构体 
struct Student{
	int num;
	int score;
	struct Student * next;
};

int main(){

	struct Student * create(void);
	struct Student * pt;
	
	//查询第一个学生的数据
	pt = create(); 
	printf("%d,%d\n",pt->num,pt->score); 
	
	return 0;
}	

//定义返回指针的函数 
struct Student * create(void){
	struct Student * head,* p1,* p2;
    int n=0;
	p1=p2=(struct Student *)malloc(sizeof(struct Student));  //开辟一个新单元,返回一个结构体指针值
 	printf("请输入学生的数据,以逗号隔开:\n");
	scanf("%d,%d",&p1->num,&p1->score);
	head = NULL;
	
	//学号为0时结束输入 
	while(p1->num!=0){  
	    n=n+1;
		if(n==1){
		  head=p1;  //把p1所指的结点作为头结点 
		}
		else
		  p2->next=p1;  //把p1所指的结点连接到表尾 
		p2=p1;  //p2移动到表尾
		
		p1=(struct Student *)malloc(sizeof(struct Student));  //再开辟一个动态空间，把起始地址赋给p1 
		scanf("%d,%d",&p1->num,&p1->score);
	}
		
	p2->next=NULL;  //到达表尾
	
	return head;
}
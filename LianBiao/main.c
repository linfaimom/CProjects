#include <stdio.h>
#include <stdlib.h>

//����ṹ�� 
struct Student{
	int num;
	int score;
	struct Student * next;
};

int main(){

	struct Student * create(void);
	struct Student * pt;
	
	//��ѯ��һ��ѧ��������
	pt = create(); 
	printf("%d,%d\n",pt->num,pt->score); 
	
	return 0;
}	

//���巵��ָ��ĺ��� 
struct Student * create(void){
	struct Student * head,* p1,* p2;
    int n=0;
	p1=p2=(struct Student *)malloc(sizeof(struct Student));  //����һ���µ�Ԫ,����һ���ṹ��ָ��ֵ
 	printf("������ѧ��������,�Զ��Ÿ���:\n");
	scanf("%d,%d",&p1->num,&p1->score);
	head = NULL;
	
	//ѧ��Ϊ0ʱ�������� 
	while(p1->num!=0){  
	    n=n+1;
		if(n==1){
		  head=p1;  //��p1��ָ�Ľ����Ϊͷ��� 
		}
		else
		  p2->next=p1;  //��p1��ָ�Ľ�����ӵ���β 
		p2=p1;  //p2�ƶ�����β
		
		p1=(struct Student *)malloc(sizeof(struct Student));  //�ٿ���һ����̬�ռ䣬����ʼ��ַ����p1 
		scanf("%d,%d",&p1->num,&p1->score);
	}
		
	p2->next=NULL;  //�����β
	
	return head;
}
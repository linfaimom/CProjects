/*
 * =====================================================================================
 *
 *       Filename:  headInsertList.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年12月16日 16时52分29秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TRUE 0
#define FALSE 1

typedef int ElemType;

typedef struct Node{
	ElemType data;
	struct Node * next;
}Node;

Node * create(){
	Node *head,*pre,*current;
	int n,data;
	printf("请输入个数:\n");
	scanf("%d",&n);
	head = (Node *)malloc(sizeof(Node));
	head->next = NULL;
	pre = NULL;
	while(n){
		current = (Node *)malloc(sizeof(Node));
		scanf("%d",&data);
		current->data = data;
		//将头指针移到当前位置
		head->next = current;
		//下面这两步得以让链表串在一起
		current->next = pre;
		pre = current; 
		n--;
	}
	//返还头指针
	return head;
}

int main(){
	Node * point;
	Node * create();
	point = create();
	point = point->next;
	while(point!=NULL){
		printf("%d\n",point->data);
		point = point->next;
	}
	return 0;
}

/*
 * =====================================================================================
 *
 *       Filename:  tailInsertList.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年12月16日 17时29分32秒
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
	pre = head;
	while(n){
		current = (Node *)malloc(sizeof(Node));
		scanf("%d",&data);
		current->data = data;
		pre->next = current;
		pre = current;
		n--;
	}
	pre->next = NULL;
	return head;
}

int main(){
	Node * create();
	Node * point;
	point = create();
	point = point->next;
	while(point!=NULL){
		printf("%d\n",point->data);
		point = point->next;
	}
	return 0;
}

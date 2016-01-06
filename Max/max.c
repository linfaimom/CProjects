/*
 * =====================================================================================
 *
 *       Filename:  max.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年12月14日 18时48分55秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

int main(){
	int a;
	int b;
	int c;
	int max(int x,int y);
	printf("请输入a:\n");
	scanf("%d",&a);
	printf("请输入b:\n");
	scanf("%d",&b);
	c = max(a,b);
	printf("最大值为:%d\n",c);
	return 0;
}

int max(int x,int y){
	return x > y ? x : y;
}

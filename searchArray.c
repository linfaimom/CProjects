#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 100

int len;

int search(int * array, int key){
	int i=len;
	array[0] = key;			//空着array[０]不用,作为监视哨
	while(array[i]!=key){
		i--;
	}
	return i;				//返回位置
}

int main(){
	int result;				//用于保存结果
	int i,key;
	int array[MAXLEN];
	printf("请输入数组长度:\n");
	scanf("%d",&len);
	printf("输入数组元素:\n");
	for(i=1; i<=len; i++){
		scanf("%d",&array[i]);
	}
	printf("输入要查询的数据:\n");
	scanf("%d",&key);
	result = search(array,key);
	if(result==0){
		printf("无此数据:\n");
	}
	else{
		printf("该数据的位置为%d\n",result);
	}

	return 0;
}

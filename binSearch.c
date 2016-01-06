#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
#define MAX 100

int len;

int binSearch(int * array, int key){
	int low,high,mid;
	low = 1;
	high = len;
	while(low <= high){
		mid = (low + high) / 2;
		if(key < array[mid]){		//若要查找的数据小于中间位置的值则继续向左半区查询
			high = mid - 1;
		}
		else{
			if(key > array[mid]){
				low = mid + 1;
			}
			else 
				break;				//即当key==array[mid]时，也就是找到了，则退出循环
		}
	}
	if(low > high){
		return ERROR;
	}
	else{
		return mid;					//返回找到的位置
	}
}

int main(){
	int i,key,result;
	int array[MAX];
	int binSearch(int * array, int key);

	printf("请输入长度,小于100:\n");
	scanf("%d",&len);
	if(len > MAX){
		printf("错误!\n");
	}
	else{
		printf("请输入数据:\n");
		for(i=1; i<=len; i++){
			scanf("%d",&array[i]);
		}
		printf("请输入要查找的数据:\n");
		scanf("%d",&key);
		result = binSearch(array,key);
		if(result==0){
			printf("无此数据:\n");
		}
		else{
			printf("此数据所在的位置为:%d\n",result);
		}
	}
	return 0;
}

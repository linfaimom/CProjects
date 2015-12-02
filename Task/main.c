#include <stdio.h>
#define OK 0
#define ERROR 1
#define MAXSIZE 30 

typedef int ElemType;

typedef struct{
	int last;
	ElemType elem[MAXSIZE];
}SeqList;

int main(){
	SeqList L1,L2,L3;  //L1，L2,L3创建静态链表 
	int i,j,k;
	
 	L1.elem[0]=2;
	L1.elem[1]=2;
	L1.elem[2]=3;
	L1.last=3;
	L2.elem[0]=1;
	L2.elem[1]=3;
	L2.elem[2]=3;
	L2.elem[3]=4;
	L2.last=4;

	//对L1,L2链表进行比较，按增序排入L3链表
	i=0;j=0;k=0;
	while(i<=L1.last&&j<=L2.last){  //当两个链表都未到尾部
		if(L1.elem[i]<=L2.elem[j]){
			L3.elem[k]=L1.elem[i];
			i++;
			k++;
		}
		else{
			L3.elem[k]=L2.elem[j];
			j++;
			k++;
		}
	}
	
	while(i<=L1.last){  //当表L1有剩余元素的时候,把剩余元素都赋给L3 
		L3.elem[k]=L1.elem[i];
		i++;
		k++;	
	}
	
	while(j<=L2.last){  //当表L2有剩余元素的时候,把剩余元素都赋给L3 
		L3.elem[k]=L2.elem[j];
		j++;
		k++;	
	}
	
	L3.last=L1.last+L2.last;
	
	printf("合并后结果为:\n");
	for(k=0;k<L3.last;k++){
		printf("%d\t",L3.elem[k]);
	}
	
	printf("\n");
}


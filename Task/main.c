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
	SeqList L1,L2,L3;  //L1��L2,L3������̬���� 
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

	//��L1,L2������бȽϣ�����������L3����
	i=0;j=0;k=0;
	while(i<=L1.last&&j<=L2.last){  //����������δ��β��
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
	
	while(i<=L1.last){  //����L1��ʣ��Ԫ�ص�ʱ��,��ʣ��Ԫ�ض�����L3 
		L3.elem[k]=L1.elem[i];
		i++;
		k++;	
	}
	
	while(j<=L2.last){  //����L2��ʣ��Ԫ�ص�ʱ��,��ʣ��Ԫ�ض�����L3 
		L3.elem[k]=L2.elem[j];
		j++;
		k++;	
	}
	
	L3.last=L1.last+L2.last;
	
	printf("�ϲ�����Ϊ:\n");
	for(k=0;k<L3.last;k++){
		printf("%d\t",L3.elem[k]);
	}
	
	printf("\n");
}


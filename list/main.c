#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100


typedef int ElemType;

typedef struct{  //����һ�����Ա�ṹ�� 
	ElemType elem[MAXSIZE];
	int len;
}SeqList;

void main(){
	int l;  //���ڽ��ձ��� 
	int position;  //����λ�� 
	int data;  //�������� 
	int i;
	SeqList * seq;
	int InsertSeqlist(SeqList * seq, int position, ElemType data);
	seq = (SeqList *)malloc(sizeof(SeqList));
	printf("�������ĳ���:\n");
	scanf("%d",&l);
	seq->len=l;
	printf("���ʼ�����е�ֵ:\n");
	for(i=1;i<=seq->len;i++){
		scanf("%d",&seq->elem[i]);
	}
	printf("��������Ҫ�����λ��:\n");
	scanf("%d",&position);
	printf("��������Ҫ���������:\n");
	scanf("%d",&data);
	InsertSeqlist(seq,position,data); 
	for(i=1;i<=seq->len;i++){  //�˴�����elem[0] 
		printf("%d\t",seq->elem[i]);
	}
	printf("\n");
}

int InsertSeqlist(SeqList * seq, int position, int data){
	int j;
	
	//�жϲ����Ƿ�Ϸ�
	if((position<1)||(position>seq->len+1)){
		printf("����λ�ò��Ϸ���");
		return 0; 
	}
	if(seq->len>=MAXSIZE-1){
		printf("�������޷�����!");
		return 0;
	}
	
	for(j=seq->len;j>=position;j--){
		seq->elem[j+1]=seq->elem[j];  //����ƶ����ݣ��ڳ�Ҫ����Ŀ�λ 
	}
	seq->elem[j+1]=data;
	(seq->len)++;  //����1 
	return 1;
}

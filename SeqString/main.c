#include <stdio.h>
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0

typedef struct{
	char ch[MAXSIZE];
	int len;
}SeqString;

int isEmpty(SeqString s){
	if(s.len==0){
		return TRUE;
	}
	else{
		return FALSE;
	}
}

int InsertString(SeqString * s, int pos, SeqString t){
	int i;
	if(pos<0||pos>s->len){
		return FALSE;
	}
	if(s->len+t.len<=MAXSIZE){
		for(i=s->len+t.len-1;i>=t.len+pos;i--){
			s->ch[i]=s->ch[i-t.len];
		}
		for(i=0;i<t.len;i++){
			s->ch[i+pos]=t.ch[i];
		}
		s->len+=t.len;	
	}
	else if(pos+t.len<=MAXSIZE){
		//����󴮳�>MAXSIZE������t���ַ����п���ȫ�����룬������������ƵĲ�������
		for(i=MAXSIZE-1;i>t.len+pos-1;i++){
			s->ch[i]=s->ch[i-t.len];
		} 
		for(i=0;i<t.len;i++){
			s->ch[i+pos]=t.ch[i];
		}
		s->len=MAXSIZE;
	}
	else{
		//��t�е��ַ�����һ����Ҫ������ 
		for(i=0;i<MAXSIZE-pos;i++){
			s->ch[i+pos]=t.ch[i];
		}
		s->len=MAXSIZE;
	}
	printf("�����:\n");
	puts(s->ch);
	return TRUE;
}

int main(){
	SeqString s,t;
	int i;
	int pos;
	s.len=0;
	t.len=0;
	printf("�������ַ���s:\n");
	gets(s.ch);
	for(i=0;s.ch[i]!='\0';i++){
		s.len++;
	}
	printf("�ַ���s����Ϊ:%d\n",s.len);
	printf("������Ҫ������ַ���t:\n");
	gets(t.ch);
	for(i=0;t.ch[i]!='\0';i++){
		t.len++;
	}
	printf("�ַ���t�ĳ���Ϊ:%d\n",t.len);
	printf("������Ҫ�����λ��:\n");
	scanf("%d",&pos);
	InsertString(&s,pos,t);
} 
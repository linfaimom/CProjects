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
		//插入后串长>MAXSIZE，但串t的字符序列可以全部插入，即舍弃向后推移的部分数据
		for(i=MAXSIZE-1;i>t.len+pos-1;i++){
			s->ch[i]=s->ch[i-t.len];
		} 
		for(i=0;i<t.len;i++){
			s->ch[i+pos]=t.ch[i];
		}
		s->len=MAXSIZE;
	}
	else{
		//串t中的字符后面一部分要舍弃掉 
		for(i=0;i<MAXSIZE-pos;i++){
			s->ch[i+pos]=t.ch[i];
		}
		s->len=MAXSIZE;
	}
	printf("插入后:\n");
	puts(s->ch);
	return TRUE;
}

int main(){
	SeqString s,t;
	int i;
	int pos;
	s.len=0;
	t.len=0;
	printf("请输入字符串s:\n");
	gets(s.ch);
	for(i=0;s.ch[i]!='\0';i++){
		s.len++;
	}
	printf("字符串s长度为:%d\n",s.len);
	printf("请输入要插入的字符串t:\n");
	gets(t.ch);
	for(i=0;t.ch[i]!='\0';i++){
		t.len++;
	}
	printf("字符串t的长度为:%d\n",t.len);
	printf("请输入要插入的位置:\n");
	scanf("%d",&pos);
	InsertString(&s,pos,t);
} 
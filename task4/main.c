#include <stdio.h>
#define OK 1
#define ERROR 0

typedef struct{
	char * ch;
	int len;
}HString;

//初始化
void InitStr(HString * s){
	s->ch=NULL;
	s->len=0;
} 

//求串长 
int StrLen(HString s){
	return (s.len);
}

//判空 
int StrEmpty(HString s){
	if(s.len==0){
		return OK;
	}
	else{
		return ERROR;
	}
}

//串赋值 
int StrAssign(HString * s, char * t){
	int len;
	int i=0;
	if(s->ch!=NULL){
		free(s->ch);
	}
	while(t[i]!='\0'){
		i++;
	}
	len=i;  //保存输入的字符串t的长度
	if(len){
		s->ch=(char *)malloc(len);
		if(s->ch==NULL){
			return ERROR;
		}
		else{
			for(i=0;i<len;i++){
				s->ch[i]=t[i];
			}
		}
	}
	else{
		s->ch==NULL;
	} 
	s->len=len;  //当前堆串的长度
	return OK; 
}

//串连接 
int StrCat(HString * s, HString t){
	int i;
	char * temp;
	temp=(char *)malloc(s->len+t.len);
	if(temp==NULL){
		return ERROR;
	}
	else{
		//分别把s、t两个串放到temp里 
		for(i=0;i<s->len;i++){
			temp[i]=s->ch[i];
		}
		for(i=s->len;i<s->len+t.len;i++){
			temp[i]=t.ch[i-s->len];
		}
		s->len+=t.len;
		free(s->ch);
		s->ch=temp;
		return OK;
	}
}

//串比较 
int StrCompare(HString s, HString t){
	int i;
	for(i=0;i<s.len&&i<t.len;i++){
		if(s.ch[i]!=t.ch[i]){
			return (s.ch[i]-t.ch[i]);
		}
		else{
			return (s.len-t.len);
		}
	}
}

//串替代 
int StrReplace(HString s, HString t, HString v){
	
}

//串插入 
int StrInsert(HString * s, int pos, HString t){
	char * temp;
	int i;
	//检测插入位置是否合法 
	if(pos<0||pos>s->len||s->len==0){
		return ERROR;
	}
	else{
		temp=(char *)malloc(s->len+t.len);
		if(temp!=NULL){
			for(i=0;i<pos;i++){
				temp[i]=s->ch[i];
			}
			for(i=pos;i<pos+t.len;i++){
				temp[i]=t.ch[i-pos];
			}
			for(i=pos;i<s->len;i++){
				temp[i+t.len]=s->ch[i];
			}
			s->len+=t.len;
			free(s->ch);
			s->ch=temp;
			return OK;
		}
		else{
			return ERROR;
		}
	}
}



int main(){
	HString s;
	HString t;
	int len;
	int i;
	int pos; 
	char ch[100];
	char th[100];
	
	
	//连接字符串
	printf("\n");
	printf("测试字符串的连接\n");
	printf("----------------------------------\n");
	InitStr(&s);
	InitStr(&t);
	printf("输入串s:\n");
	scanf("%s",ch);
	StrAssign(&s,ch);
	printf("输入串t:\n");
	scanf("%s",th);
	StrAssign(&t,th); 
	StrCat(&s,t);
	len=StrLen(s);
	printf("连接后字符串长度为:%d\n",len);
	printf("连接后的字符串为:");
	puts(s.ch);
	printf("\n");
	printf("----------------------------------\n");
	
	//测试插入字符
	printf("\n");
	printf("测试字符串的插入\n");
	printf("----------------------------------\n"); 
	InitStr(&s);
	InitStr(&t);
	printf("输入串s:\n");
	scanf("%s",ch);
	StrAssign(&s,ch);
	printf("输入串t:\n");
	scanf("%s",th);
	StrAssign(&t,th);
	printf("输入要插入的位置:\n");
	scanf("%d",&pos);
	StrInsert(&s,pos,t);
	printf("插入后的结果为:\n");
	puts(s.ch);
	printf("----------------------------------\n");
	
	//测试串比较
	printf("测试字符串比较，只比较首元素，长度需相同\n");
	InitStr(&s); 
	InitStr(&t);
	printf("输入串s:\n");
	scanf("%s",ch);
	StrAssign(&s,ch);
	printf("输入串t:\n");
	scanf("%s",th);
	StrAssign(&t,th);
	int result = StrCompare(s,t);
	if(result==0){
		printf("两字符串相等\n");
	}
	else{
		printf("两字符串不等，相差:%d\n",result);
	}
	printf("----------------------------------\n");
	
	return 0;
}
#include <stdio.h>
#define OK 1
#define ERROR 0

typedef struct{
	char * ch;
	int len;
}HString;

//��ʼ��
void InitStr(HString * s){
	s->ch=NULL;
	s->len=0;
} 

//�󴮳� 
int StrLen(HString s){
	return (s.len);
}

//�п� 
int StrEmpty(HString s){
	if(s.len==0){
		return OK;
	}
	else{
		return ERROR;
	}
}

//����ֵ 
int StrAssign(HString * s, char * t){
	int len;
	int i=0;
	if(s->ch!=NULL){
		free(s->ch);
	}
	while(t[i]!='\0'){
		i++;
	}
	len=i;  //����������ַ���t�ĳ���
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
	s->len=len;  //��ǰ�Ѵ��ĳ���
	return OK; 
}

//������ 
int StrCat(HString * s, HString t){
	int i;
	char * temp;
	temp=(char *)malloc(s->len+t.len);
	if(temp==NULL){
		return ERROR;
	}
	else{
		//�ֱ��s��t�������ŵ�temp�� 
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

//���Ƚ� 
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

//����� 
int StrReplace(HString s, HString t, HString v){
	
}

//������ 
int StrInsert(HString * s, int pos, HString t){
	char * temp;
	int i;
	//������λ���Ƿ�Ϸ� 
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
	
	
	//�����ַ���
	printf("\n");
	printf("�����ַ���������\n");
	printf("----------------------------------\n");
	InitStr(&s);
	InitStr(&t);
	printf("���봮s:\n");
	scanf("%s",ch);
	StrAssign(&s,ch);
	printf("���봮t:\n");
	scanf("%s",th);
	StrAssign(&t,th); 
	StrCat(&s,t);
	len=StrLen(s);
	printf("���Ӻ��ַ�������Ϊ:%d\n",len);
	printf("���Ӻ���ַ���Ϊ:");
	puts(s.ch);
	printf("\n");
	printf("----------------------------------\n");
	
	//���Բ����ַ�
	printf("\n");
	printf("�����ַ����Ĳ���\n");
	printf("----------------------------------\n"); 
	InitStr(&s);
	InitStr(&t);
	printf("���봮s:\n");
	scanf("%s",ch);
	StrAssign(&s,ch);
	printf("���봮t:\n");
	scanf("%s",th);
	StrAssign(&t,th);
	printf("����Ҫ�����λ��:\n");
	scanf("%d",&pos);
	StrInsert(&s,pos,t);
	printf("�����Ľ��Ϊ:\n");
	puts(s.ch);
	printf("----------------------------------\n");
	
	//���Դ��Ƚ�
	printf("�����ַ����Ƚϣ�ֻ�Ƚ���Ԫ�أ���������ͬ\n");
	InitStr(&s); 
	InitStr(&t);
	printf("���봮s:\n");
	scanf("%s",ch);
	StrAssign(&s,ch);
	printf("���봮t:\n");
	scanf("%s",th);
	StrAssign(&t,th);
	int result = StrCompare(s,t);
	if(result==0){
		printf("���ַ������\n");
	}
	else{
		printf("���ַ������ȣ����:%d\n",result);
	}
	printf("----------------------------------\n");
	
	return 0;
}
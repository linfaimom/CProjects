#include <stdio.h>

int main(){
	int n;
	int i;
	int s=0;
	int fac(int n);  //采用递归 
	void fac1(int n);  //采用循环 
	scanf("%d",&n);
	//printf("%d\n",fac(n));
	//fac1(n);
	printf("1！+3！+5！+......+%d!= ",n);
	for(i=1;i<=n;i=i+2){
		s=s+fac(i);
	}
	printf("%d\n",s); 
}

int fac(int n){
	int i;
	
	if(n==1){
		return 1;
	}
	
	else{
		return (n*fac(n-1));
	}
}

void fac1(int n){
	int i;
	if(n==1){
		i=1;
	}
	else{
		for(i=1;n>1;n--){
			i=i*n;
		}
	}
	printf("%d\n",i);
}
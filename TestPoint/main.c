#include <stdio.h>

int main(int argc, char *argv[]){
	int * p;
	int i;
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	p = a;
	for (i=0;i<10;i++,p++){
		printf("%d\n",*p);
	}
}

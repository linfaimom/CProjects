#include <stdio.h>

int main(){
	struct Student{
		int age;
		int height;
		char name[20]; 
	};
	
	struct Student student={20,168,"�ַ���"};
	
	printf("%d,%d,%s\n",student.age,student.height,student.name);
	
	return 0;
}

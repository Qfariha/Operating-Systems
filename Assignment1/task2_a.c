#include <stdio.h>
int main(){
	int a,b,var;
	printf("Enter first number:");
	scanf("%d",&a);  //scanf => & => memory address
	printf("Enter second number:");
	scanf("%d",&b);
	
	if (a>b)
	{ 
	var=a-b;
	printf("Subtraction result:%d\n",var);
	}
	else if (a<b)
	{ 
	var=a+b;
	printf("Addition result:%d\n",var);
	}
	else
	{
	var=a*b;
	printf("Multiplication result:%d\n",var);
	}
	return 0;
}

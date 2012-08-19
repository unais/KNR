#include<stdio.h>

void printd(int n);
main()
{
	int dec;
	scanf("%d",&dec);
	printd(dec);
	printf("\n");
}


void printd(int n)
{
	if(n<0){
		putchar('-');
		n = -n;	
	}
	
	if(n/10)
		printd(n/10);
	putchar(n % 10 + '0');
}

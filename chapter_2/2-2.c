
/*************************************************************
 code eqlnt to i<lim-1 && (c = getchar()) != '\n' && c != EOF
*************************************************************/

#include<stdio.h>
main()
{
	int a = 1,i = 0,lim,c;
	while(a){
		if(i<lim-1)
		if(c != '\n')
		if(c != EOF){
			a = 1;
			c = getchar();
			putchar(c);
			}
		else a=0;
	}
}

/***********************************************************
     program to determine the ranges of char,short,int 
************************************************************/


#include<stdio.h>
#include<limits.h>
main()
{
	printf("min value of char \t= \t%11.0d\n",CHAR_MIN);
	printf("max value of char \t= \t%11.0d\n",CHAR_MAX);
	printf("min value of shor \t= \t%11.0d\n",SHRT_MIN);
	printf("max value of char \t= \t%11.0d\n",SHRT_MAX);
	printf("min value of int \t= \t%11.0d\n",INT_MIN);
	printf("max value of char \t= \t%11.0d\n",INT_MAX);
	printf("min value of long \t= \t%11.0ld\n",LONG_MIN);
	printf("man value of char \t= \t%11.0ld\n",LONG_MAX);
}

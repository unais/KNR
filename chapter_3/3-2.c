/**********************************************************************
program that converts characters like newline and tab into
visible escape sequences like \n and \t as it copies the string t to s
******************************************************************/


#include<stdio.h>
main()
{
	int c;

	while ((c = getchar()) != EOF){
		switch (c){
		case '\n':
			printf("\\n");
			break;
		case '\t':
			printf("\\t");
			break;
		default:
			putchar(c);
			break;
		}
	}
}

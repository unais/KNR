/***********************************************
very optimised code for reversing a string
***********************************************/

#include<stdio.h>
#include<string.h>

main()
{
	int i, j, c;
	char s[50] = "This is the reversed data";
	printf("Input data:\n%s\n",s);
	
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;
	
	printf("Reverced data:\n%s\n",s);
}

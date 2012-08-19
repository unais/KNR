#include<stdio.h>


void strcat1(char *s,char *t)
{
	while( *s++ != '\0');
	*s--;
	while( *s++ = *t++);
}
main()
{
	char s1[20] = "Hello" ,s2[20] = " World!";
	
	strcat1(s1,s2);
	printf("%s\n",s1);	
}


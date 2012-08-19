/********************************************************************************************
Exercise 5-4. Write the function strend(s,t), which returns 1 if the string t occurs at the
end of the string s, and zero otherwise.

**********************************************************************************************/

#include<stdio.h>

int strend1(char *s, char *t)
{
	char *bs = s, *bt = t;
	
	while(*s++)
		;
	while(*t++)
		;
	
	while(*s-- == *t--)
		if(t == bt || s == bs)
			break;
	if(*s == *t && t == bt	&& s != '\0')
		return 1;
	else
		return 0;	
}



main()
{
	char s1[20] = "Hello World", s2[20] = "World";
	
	if(strend1(s1,s2))
		printf("OK\n");
	else
		printf("No\n");
	
}



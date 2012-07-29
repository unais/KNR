#include<stdio.h>
main()
{
	char a[20];
	scanf("%s",a);
	printf("%s \n",squeeze(a,'c'));       	
}

void squeeze(char [], int c)
{
	int i, j;
	
	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}

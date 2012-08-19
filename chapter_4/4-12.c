/***********************************************************************************************
Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa; that is, convert
an integer into a string by calling a recursive routine.
************************************************************************************************/


#include<stdio.h>
#include<math.h>

void itoa(int n, char s[]);

main()
{
	int n;
	char s[20];
	
	scanf("%d",&n);
	itoa(n,s);
	printf("%s\n",s);
}

void itoa(int n, char s[])
{
	static int i;

	if(n/10)
		itoa(n/10,s);
	else{
		i = 0;
		if(n < 0)
			s[i++] = '-';
	}
	s[i++] = abs(n) % 10 + '0';
	s[i] = '\0';
}

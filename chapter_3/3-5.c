#include<stdio.h>
#include<string.h>
void itob(int n, char s[], int b);
void reverse(char s[]);

main()
{
	int n, b;
	char num[50] ;

	printf("n\tb\n");
	scanf("%d%d", &n, &b);
	itob(n, num, b);
	printf("Result\t:\t%s\n", num);
	
}

void itob(int n, char s[], int b)
{
	int i, j, sign;
	
	if( (sign =n) < 0)
		n = -n;
	i = 0;
	do {
		j = n % b;
		s[i++] = (j <= 9) ? j + '0': j + 'A' -10;
	} while( (n /= b) > 0);
	
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}


void reverse(char s[])
{
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}


#include<stdio.h>
main()
{
	int c, j = 0, i, n = 0;

	for (i = 0; (c = getchar()) != EOF; i++){
		if (c == 'a' + n)
			++j;
		histogram(j);
		if ('a' + n <= 'z')
			++n;
	}
}

	
void histogram(int k)
{
	while (k--)
		putchar('*');
	printf("\n");
}

#include<stdio.h>
main()
{
	int i, n=20, a[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12, 13};
	for (i = 0; i < n; i++)
		printf("%6d%c", a[i], (i%10==9 || i==n-1) ? '\n' : ' ');
}

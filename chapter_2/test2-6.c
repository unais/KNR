#include<stdio.h>
main()
{
	unsigned int x, y;
	int p, n;
	printf ("x\ty\tp\tn\t\n");
	scanf ("%u%u%d%d", &x, &y, &p, &n);

	printf ( "Result\t=\t%u\n", ((x & ((~0 << (p+1)) | ~(~0 << (p+1-n)))) | 
					((y & ~(~0 << n)) << (p+1-n))));
}

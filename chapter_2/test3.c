#include<stdio.h>
main()
{
	unsigned int x;
	int p, n;
	printf("x-----p-----n\n");
	scanf( "%u%d%d", &x, &p, &n);
	printf ("value\t=%u\n",(x >> (p+1-n)) & ~(~0 << n) );
}

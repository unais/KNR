#include<stdio.h>
main()
{
	unsigned int x;
	
	printf("The value of x = \n");
	scanf("%u", &x);
	printf("count 1 bits in x\t=\t%u\n", bitcount(x));
}
	
int bitcount (unsigned x)
{
	int b;

	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;
	return b;
}

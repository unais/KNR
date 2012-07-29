#include<stdio.h>
main()
{
        unsigned int x;
        int p, n;
        printf ("x\tp\tn\t\n");
        scanf ("%u%d%d", &x, &p, &n);

        printf ( "Result\t=\t%u\n", x ^ ~((~0 << (p+1) | ~(~0 << (p+1-n)))));
}

#include<stdio.h>
/*count charecters in input*/
main()
{	
	long nc;
	nc = 0;
while ( getchar() != EOF )
		++nc;
	printf(" \n %ld \n ",nc);
}

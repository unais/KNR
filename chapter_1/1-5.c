#include<stdio.h>
main()
{
	int far;
	for(far=300;far>=0;far=far-20)
	printf("%3d \t %6.1f \n", far , 5.0/9.0*(far-32));
}

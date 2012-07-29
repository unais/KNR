#include<stdio.h>
main()
{
int far;
for(far=0;far<=300;far=far+20)
	printf("\t %3d \t %6.1f\n",far,5.0/9.0*(far-32));
}

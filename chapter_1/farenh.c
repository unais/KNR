#include<stdio.h>
main()
{
	float far , celc;
	
	int start = 0,step = 20,stop = 300;
	celc = start;
	printf("\t cel to far conversion\n");
	while(celc <= stop){
		far = 9.0/5.0*celc+32;
		printf("\t %3.0f \t %6.1f \n",celc,far);
		celc += step;
	}
}


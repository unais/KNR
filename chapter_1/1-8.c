#include<stdio.h>
main()
{
	int c, nb = 0,nt = 0,nl = 0;
	while((c=getchar()) != EOF){
		if(c == ' ')
			++nb;
		if(c == '\t')
			++nt;
		if(c == '\n')
			++nl;
	}
	printf("blank = %d \t tab = %d \t line = %d\n",nb,nt,nl);
}

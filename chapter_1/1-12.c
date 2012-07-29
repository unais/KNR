#include<stdio.h>
main(){
	int c;
	while((c = getchar()) != EOF){
		if((c != ' ')&&(c != '\n')&&(c != '\t'))
			putchar(c);
		else
			printf("\n");
	}
}

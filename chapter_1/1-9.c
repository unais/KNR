#include<stdio.h>
#define NONBLANK 'a'
main(){
	int c,prev;
	prev = NONBLANK;	
	while((c = getchar()) != EOF ){
		if(c != ' ')
			putchar(c);	
		if(c == ' ')
			if(prev != ' ')
				putchar(c);
		prev = c;	
	}
}

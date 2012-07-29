#include<stdio.h>
#define INITIAL 0
#define FINAL 300
#define STEP 20
main(){
	int i;
	for(i=INITIAL ; i <= FINAL ; i = i+STEP)
		printf("%d F \t = \t %d C\n",i,far(i));	
}

int far(i){
	int c;
	c = 5*(i-32)/9;
	return c;
	
}



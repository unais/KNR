#include<stdio.h>
#define MAXLINE 1000

int getlines(char s[], int lim);
/* longest input line */

main(){
	int len;
	int max;
	char line[MAXLINE];
	

	max = 0;
	while((len  = getlines(line,MAXLINE)) > 80 )
		printf("%s",line);
	return 0;
}
		

int getlines(char s[] , int lim){
	int c , i;
	for(i=0 ; i<lim-1 && (c = getchar()) != EOF && c != '\n' ; ++i)
		s[i] = c;
	if(c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

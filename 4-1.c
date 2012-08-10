#include<stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getlines(char s[], int lim);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";  //pattern to search for

main()
{
	char line[MAXLINE];
	
	while (getlines(line, MAXLINE) > 0)
		printf("The position rightmost occur\t=\t%d\n",strrindex(line, pattern));
}

/*getline: get line into s, return length*/
int getlines(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/*strrindex: return the position of extreme right occurance of the pattern*/
int strrindex(char s[], char t[])
{
	int i, j, k, pos;
	pos = -1;
	
	for (i = 0; s[i] != '\0'; i++){
		for(j=i, k=0; t[k] != '\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			pos = i;
	}
	return pos;
}


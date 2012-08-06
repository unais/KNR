#include<stdio.h>
#define MAX_LINE 100

int reverse(char s[]);

main()
{

	char line[MAX_LINE] = "This is the reverced data";
	printf("Data given:\n%s\n",line);
	reverse(line);
	printf("Reveced Data:\n%s\n",line);
//	printf("o/p data:\n\t%c\n",reverse(line));
	
	//for (i = 0;reverce(line) != '/0' )
}

int reverse(char s[])
{
	char ch;
	int i, j;

	for(j = 0; s[j] != '\0'; j++);
	--j;

  	for(i = 0; i < j; i++){
    		ch   = s[i];
    		s[i] = s[j];
    		s[j] = ch;
    		--j;
  	}
  	return 0;
}


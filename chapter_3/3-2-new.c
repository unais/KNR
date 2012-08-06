#include<stdio.h>
void escape(char s[], char t[]);
void unescape(char s[], char t[]);


main()
{
	char text1[50] = "one \n\ttwo\n\t\tthree\n\t\t\twow...its working\n";
	char text2[51];
	
	printf("input data:\n%s\n",text1);
	escape(text2,text1);
	printf("escape o/p:\n%s\n",text2);
	unescape(text1,text2);
	printf("unescape o/p:\n%s\n",text1);
}


void escape(char s[], char t[])
{
	int i, j;
	for(i = j = 0; t[i] != '\0'; i++)
		switch (t[i]){
		case '\n':
			s[j++] = '\\';
			s[j++] = 'n';
			break;
		case '\t':
			s[j++] = '\\';
			s[j++] = 't';
			break;	
		default:
			s [j++] = t[i];
			break;
		}
	s[j++] = '\0';
	
}


void unescape(char s[], char t[])
{
	int i, j;
	for(i = j = 0; t[i] != '\0'; i++){
		if (t[i] == '\\'){
			i=i+1;
			switch (t[i]){
			case 'n':
				s[j++] = '\n';
				break;
			case 't':
				s[j++] = '\t';
				break;
			}
			}
		else
			s[j++] = t[i];
	}
	s[j++] = '\0';	
}

/***********************************************************************************************
Exercise 4-13. Write a recursive version of the function reverse(s), which reverses the
string s in place.
**********************************************************************************************/
#include<stdio.h>
#include<string.h>

void reverse(char s[]);

main()
{
	char s[30] = "This is the Reversed Data";
	reverse(s);
	printf("%s\n",s);	
}


void reverse(char s[])
{
	void reverser(char s[], int i, int len);

	reverser(s, 0, strlen(s));
}

void reverser(char s[], int i, int len)
{
	int temp, j;
	j = (len - (i+1));	//un reversed last charecter
	
	if(i < j){
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		reverser(s, ++i, len);
	}
}

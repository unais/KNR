/****************************************************************************************
Exercise 5-1. As written, getint treats a + or - not followed by a digit as a valid
representation of zero. Fix it to push such a character back on the input.
*****************************************************************************************/


#include<stdio.h>
#define SIZE	100 

main()
{
	int n, array[SIZE], getint (int *);
	
	for (n = 0; n < SIZE; n++)
		array[n] = 0;
	
	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
		printf("%d\n",array[n]);

}



#include<ctype.h>

int getch(void);
void ungetch(int);

int getint(int *pn)
{
	int c, sign, d;

	while(isspace(c = getch()))
		;
	if (!isdigit(c) && c!= EOF && c != '+' && c != '-'){
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-'){
		d = c;
		if (!isdigit(c = getch())){
			if (c != EOF)
				ungetch(c);
			ungetch(d);
			return c;
		}
	}
	for (*pn = 0; isdigit(c) ; c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}


#define BUFSIZE 100

char buf[BUFSIZE];  		//buffer for ungetch
int bufp = 0;			//next free position in buf

int getch(void)	//get a possibly pushed-back character
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

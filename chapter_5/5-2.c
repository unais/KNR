/****************************************************************************************
Exercise 5-1. As written, getint treats a + or - not followed by a digit as a valid
representation of zero. Fix it to push such a character back on the input.
*****************************************************************************************/


#include<stdio.h>
#define SIZE	100 


int getfloat(float *pn);


main()
{
	int n;
	float array[SIZE];
	
	for (n = 0; n < SIZE; n++)
		array[n] = 0;
	
	for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
		printf("%f\n",array[n]);

}



#include<ctype.h>

int getch(void);
void ungetch(int);

int getfloat(float *pn)
{
	int c, sign;
	float pow;

	while(isspace(c = getch()))
		;
	if (!isdigit(c) && c!= EOF && c != '+' && c != '-'){
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	for (*pn = 0.0; isdigit(c) ; c = getch())
		*pn = 10.0 * *pn + (c - '0');
	if (c == '.')
		c = getch();
	for (pow = 1.0; isdigit(c); c = getch()){
		*pn = 10.0 * *pn + (c - '0');
		pow *= 10.0;
	}
	*pn *= sign / pow;
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

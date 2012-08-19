/*********************************************************************************
Exercise 4-11. Modify getop so that it doesn't need to use ungetch. Hint: use an internal
static variable.

*********************************************************************************/



#include<stdio.h>
#include<stdlib.h>	//including atof



#define MAXOP 100 // max size of operator or operant
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);


/*******************************************************
********Reverse Polish Calculator***********************
********************************************************
Eg : for (1-2)*(4+5) we give data like this
		1 2 - 4 5 + *
o/p		Result : 9
********************************************************/

main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF){
		switch (type){
		case NUMBER:
			push(atof (s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if(op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '\n':
			printf("\tResult\t=\t%.8g\n", pop());
			break;
		default:
			printf("error: unknwn command %s\n", s);
			break;
		}
	}


	return 0;
}



#define MAXVAL 100		//maximum depth of val stack

int sp = 0;
double val[MAXVAL];	//value stack

/*********************************************************
*********push: push f onto value stack********************
*********************************************************/
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full,can't push %g\n", f);
}

/*********************************************************
********pop: pop and return top value from stack**********
*********************************************************/
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else{
		printf("error: stack empty\n");
		return 0.0;
	}
}

#include<stdio.h>
#include<string.h>
#include<ctype.h>


int getch(void);

/********************************************************
*****getop: get next character or numeric operand********
********************************************************/
int getop(char s[])
{
	int i, c;
	static lastc = 0;

	if(lastc == 0)
		c = getch();
	else{
		c = lastc;
		lastc = 0;
	}
	while ((s[0] = c) == ' ' || c =='\t')
		c = getch();
	s[1] = '\0';

	if (!isdigit(c) && c != '.')
		return c;			//not a number
	i = 0;
	if (isdigit (c))			//collect integer part
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')	//colletc fractional part
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		lastc = c;
	return NUMBER;
	
}


#define BUFSIZE 100

char buf[BUFSIZE];  		//buffer for ungetch
int bufp = 0;			//next free position in buf

int getch(void)	//get a possibly pushed-back character
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}


/*********************************************************************************
Qn : 4-3 (page 79

Given the basic framework, it's straightforward to extend the calculator. Add the
modulus (%) operator and provisions for negative numbers.


*********************************************************************************/



#include<stdio.h>
#include<math.h>	//for including fmod
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
		case '%':
			op2 = pop();
			if(op2 != 0.0)
				push(fmod(pop(), op2));
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
void ungetch(int c);

/********************************************************
*****getop: get next character or numeric operand********
********************************************************/
int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c =='\t')
		;
	s[1] = '\0';
	i = 0;
	if (!isdigit(c) && c != '.' && c != '-')
		return c;			//not a number
	if (c == '-')	
		if(isdigit(c = getch()) || c == '.')
			s[++i] == c;
		else{
			if (c != EOF)
				ungetch(c);
			return '-';
		}
	if (isdigit (c))			//collect integer part
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')	//colletc fractional part
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
	
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

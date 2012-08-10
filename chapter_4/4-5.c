/*********************************************************************************
Exercise 4-5. Add access to library functions like sin, exp, and pow. See <math.h> in
Appendix B, Section 4.
*********************************************************************************/



#include<stdio.h>
#include<math.h>	//for including fmod and sin exp pow
#include<stdlib.h>	//including atof



#define MAXOP 100 // max size of operator or operant
#define NUMBER '0'		//identifieng nos
#define NAME 'n'		//indentifing math functions

int getop(char []);
void push(double);
double pop(void);
void clear(void);
void mathfunction(char s[]);


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
	double op2,temp;
	char s[MAXOP];

	while ((type = getop(s)) != EOF){
		switch (type){
		case NUMBER:
			push(atof (s));
			break;
		case NAME:
			mathfunction(s);
			break;
		case 't':
			op2 = pop();
			printf("The top element = %.8g",op2);
			push(op2);
			break;
		case 's':
			op2 = pop();
			temp = pop();
			push(op2);
			push(temp);
			break;
		case 'c':			//clear
			clear();
			break;
		case 'd':		//dublicating
			op2 = pop();
			push(op2);
			push(op2);
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


/********************************************************************
**************** math fuctions calculation***************************
*********************************************************************/

#include<string.h>

void mathfunction(char s[])
{
	int op2;

	if(strcmp(s,"sin") == 0)
		push(sin(pop()));
	else if(strcmp(s,"cos") == 0)
		push(cos(pop()));
	else if(strcmp(s,"exp") == 0)
		push(exp(pop()));
	else if(strcmp(s,"pow") == 0){
		op2 = pop();		
		push(pow(pop(),op2));
	}
	else
		printf("Error..%s.Not a math function\n",s);
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

/****************** for clearing stack*******************/
void clear(void)
{
	sp = 0;
}


#include<stdio.h>
#include<string.h>
#include<ctype.h>


int getch(void);
void ungetch(int c);

/********************************************************
******getop: get next character or numeric operand********
********************************************************/
int getop(char s[])
{
	int i = 0, c, next;
 
   
   	while((s[0] = c = getch()) == ' ' || c == '\t')		//skip white space
      		;
   	s[1] = '\0';
   
   	if(isalpha(c)){
      		i = 0;
      		while(isalpha(s[i++] = c ))
         		c = getch();     
      		s[i-1] = '\0';
      		if(c != EOF)
        		ungetch(c);
      		return NAME;
   	}	
   
   	if(!isdigit(c) && c != '.')
     		return c;                 
   
      	c = getch();

   	while(isdigit(s[++i] = c))
      		c = getch();
		
   	if(c == '.')                 /* Collect fraction part. */
      		while(isdigit(s[++i] = c = getch()))
         		;
      	s[i] = '\0';
      	if(c != EOF)
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

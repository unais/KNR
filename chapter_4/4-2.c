#include<stdio.h>
#define MAXLINE 100



int getlines(char s[], int lim);
double atof (char s[]);

main()
{
	double atof(char []);
	char line[MAXLINE];
	int getlines(char line[], int max);
	while(getlines(line,MAXLINE) > 0)
		printf("\t%g\n", atof(line));
	return 0;		
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



#include<ctype.h>
/* atof that handles scientific notation of the form 123.45e-6*/
double atof (char s[])
{
	double val, power, exp_power;
	int i, sign, exp_sign, exp_val;
	
	for (i = 0; isspace(s[i]); i++);	//skip white space
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit (s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit (s[i]); i++){
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	val = sign * val / power;
	if (s[i] == 'e' || s[i] == 'E'){
		i++;				//skip e or E
		exp_sign = (s[i] == '-') ? 2: 1;
		if (s[i] == '-' || s[i] == '+')
			i++;
		for (exp_val = 0; isdigit (s[i]); i++)
			exp_val = 10 * exp_val + (s[i] - '0');	//getting the digits of exponent
		for (exp_power = 1; exp_val >= 1; exp_val--)
			exp_power *= 10 ;
	//	(exp_sign < 0) ? val /= exp_power : val *= exp_power; 
		if (exp_sign == 2)
			val = val/exp_power;
		else
			val = val*exp_power;
		
	}
	return val;
}

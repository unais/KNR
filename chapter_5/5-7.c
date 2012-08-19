/*****************************************************************************************
Exercise 5-7. Rewrite readlines to store lines in an array supplied by main, rather than
calling alloc to maintain storage. How much faster is the program?

*****************************************************************************************/



#include<stdio.h>
#include<string.h>


#define MAXLINE 5000	//max no of lines to be sorted
#define MAXSTOR 5000

char *lineptr[MAXLINE];	//pointers to text lines
char linestor[MAXSTOR];

int readlines(char *lineptr[], char *linestor, int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);


main()
{
	int nlines;

	if ((nlines = readlines(lineptr, linestor, MAXLINE)) >= 0){
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	}else{
		printf("error: input to big to sort\n");
		return 1;
	}
	
}

#define MAXLEN 1000	//max len of any input line

//int getline(char *, int);

/*getline: read a line in to s, return length*/
int getline1(char *s, int lim)
{
	int c;
	char *t = s;

	while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*s++ = c;
	if (c == '\n')
		*s++ = c;
	*s = '\0';
	return s - t;
}


int readlines(char *lineptr[], char *linestor, int maxlines)
{
	int len, nlines;
	char line[MAXLEN];
	char *p = linestor;
	char *linestop = linestor + MAXSTOR;

	nlines = 0;
	while((len = getline1(line,MAXLEN)) > 0)
		if (nlines >= maxlines || p + len >= linestop)
			return -1;
		else{
			line[len -1] ='\0'; //delete newline
			strcpy(p, line);
			lineptr[nlines++] = p;
			p += len;
		}
	return nlines;
}


/* writelines : write output lines */
void writelines(char *lineptr[], int nlines)
{
	int i;

	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}




/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);

	if (left >= right)			 // do nothing if array contains 
		return;				// fewer than two elements 
	swap(v, left, (left + right)/2);
	last = left;

	for (i = left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
	char *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}


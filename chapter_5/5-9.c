/***********************************************************************************8*
Exercise 5-9. Rewrite the routines day_of_year and month_day with pointers instead of
indexing.
******************************************************************************************/


#include<stdio.h>

#define NON_LEAP 365
#define LEAP 366


static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};


/* day_of_year: set day of year from month 7 day */

int day_of_year(int year, int month, int day)
{
	int leap;
	char *p;
	
	if(month <= 0 || month > 12)
		return -1;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	if(day <=0 || day > daytab[leap][month])
		return -1;
	p = daytab[leap];
	
	while(--month)
		day += *++p;
	return day;

}

/*month_day: set month, day from day of year*/

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	char *p;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	p = daytab[leap];
	
	if( yearday <= 0 || year < 1){
		*pmonth = -1;
		*pday = -1;
		return;
		}
	else if	(leap)
		if(yearday > LEAP){
			*pmonth = -1;
			*pday = -1;
			}
	else if (leap == 0)
		if(yearday > NON_LEAP){
				*pmonth = -1;
				*pday = -1;
			}
	else{	
		while( yearday > *++p)
			yearday -= *p;
		*pmonth = p - *(daytab + leap);
		*pday = yearday;
	}
}




main()
{
	int year, month, yearday, day;

	year = 2000;
	month = 3;
	day = 1;
	printf("The date is: %d-%02d-%02d\n", year, month, day);
	printf("day_of_year: %d\n", day_of_year(year, month, day));

	yearday = 61;
	month_day(year, yearday, &month, &day);
	printf("yearday : %d\n",yearday);
	printf("The date is: %d-%02d-%02d\n", year, month, day);

}

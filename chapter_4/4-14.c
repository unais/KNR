/***********************************************************************
Exercise 4-14. Define a macro swap(t,x,y) that interchanges two arguments of type t.
(Block structure will help.)
****************************************************************************/

#include<stdio.h>

#define swap(t,x,y) {	t _z;	 \
			_z = y;	\
			 y = x; \
			x = _z; }


main()
{
	int x = 6, y = 7;

	printf("Unswapped:\t x %d\ty %d\n",x,y);	
	swap(int,x,y);
	printf("Swapped:\t x %d\ty %d\n",x,y);	
}
			

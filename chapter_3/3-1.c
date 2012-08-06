#include<stdio.h>

int binsearch(int x, int v[], int n);
main()
{
	int x, v[100], n, i;
	
	printf ("No of elements : n =\t");
	scanf("%d",&n);
	printf ("elements...:");
	for (i = 0; i < n; i++)
		scanf("%d", &v[i]);
	printf("which element is need tosearch\tx\t=\t");
	scanf("%d",&x);
	printf ("\nThe posishion of search :\t=\t%d\n",binsearch(x, v, n));
}



int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n-1;
	mid = (low + high) / 2;
	while (low <= high && x != v[mid]){
		if (x < v[mid])
			high = mid - 1;
		else 
			low = mid + 1;
		mid = (low + high) / 2;
	}
	if ( x == v[mid])
		return mid;
	else
		return -1;
}

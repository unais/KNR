#include<stdio.h>

main()
{
	int i;
	int v[8] = {4, 2, 6, 5, 3, 7, 8, 1};
	
	void qsort(int v[], int left, int right);
	qsort(v, 0, 7);
	
	for(i = 0; i<8; i++)
		printf("%d\t",v[i]);
	printf("\n");
}


void qsort( int v[], int left, int right)
{
	int i, last;
	void swap(int v[], int i, int j);

	if (left >= right)
		return;		//do nothing if array contains fewer than two elements
	
	swap(v, left, (left+right)/2);	// move partition element to v[0]
	last = left;

	for (i = left + 1; i <= right; i++)		//partition
		if (v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last);

	for(i = 0; i<8; i++)
		printf("%d\t",v[i]);
	printf("\n");

	qsort(v, left, last-1);
	qsort(v,last+1,right);
}

void swap(int v[], int i, int j)
{
	int temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

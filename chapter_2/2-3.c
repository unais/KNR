/************************************************************************************* 
  converts string of hexadecimal digits to eqlnt integer value
*************************************************************************************/
#include<stdio.h>
main()
{
	char a[10];
	scanf("%s",a);
	printf("%d \n",htoi(a));
	
}


int htoi( char s[])
{
	int i, n;
	
	n = 0;
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
		for (i = 2; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f') || 
							(s[i] >= 'A' && s[i] <= 'F');i++){
			if (s[i] >= '0' && s[i] <= '9')
				n = 16 * n + (s[i] - '0');
			else if ( s[i] >= 'a' && s[i] <= 'f')
				n = 16 * n + (s[i] - 'a' + 10);
			else if ( s[i] >= 'A' && s[i] <= 'F')
				n = 16 * n + (s[i] - 'A' + 10);
		}	
	return n;
}

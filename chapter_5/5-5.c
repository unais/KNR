#include<stdio.h>


char strncpy1(char *s, char *ct, int n)
{

		for( ; n >= 0; n--)
			*s++ = *ct++;
		*s = '\0';
	
} 


char strncat1(char *s,char *t, int n)
{
	while( *s++ != '\0');
	*s--;
	
	for( ; n >= 0; n--)
		*s++ = *t++;
	*s ='\0';
	
}

int strncmp1(char *cs, char *ct, int n)
{
	for( ; (*cs == *ct ) ; cs++, ct++, n--)
		if( n == 0)
			return 0;
	return *cs - *ct ;
	
}

main()
{
	char s1[50] = "This is the 5-5th excecise ";
	char s2[50] = "of KNR The c programming languge";
	char s3[50] = "of";
	char s4[50];
	char s5[50];
	char s6[50] = "This is my program";
	
	strncpy1(s4,s1,10);
		
	printf("Result of strncpy case1 : %s\n",s4);

	strncpy1(s5,s3,6);
	
	printf("Result of strncpy case2 : %s\n",s5);

	strncat1(s1,s2,6);
	
	printf("Result of strncat  : %s\n",s1);

	if (strncmp1(s1, s6, 7) == 0)
		printf("The two parts are eaqual case 1\n");
	else
		printf("The two parts not are eaqual case1\n");

	if (strncmp1(s1, s6, 15) == 0)
		printf("The two parts are eaqual case 2\n");
	else
		printf("The two parts not are eaqual case 2\n");
	
		
}

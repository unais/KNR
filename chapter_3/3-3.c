#include<stdio.h>

void expand (char s1[], char s2[]);

main()
{	
	char text1[50] = "expand a-k,1-9,a-b-c,and -z and p- for testing....";
	char text2[100];
	
	printf("Input data:\n%s\n",text1);
	expand(text1, text2);
	printf("Expanded data:\n%s\n",text2);
	
}


void expand (char s1[], char s2[])
{
	char c;
	int i, j;

	i = j = 0;
	while((c = s1[i++]) != '\0'){
		if( s1[i] == '-' && s1[i+1] >= c && s1[i-1] != ' ' && s1[i+1] != ' '){
			i++;
			while (c < s1[i])
				s2[j++] = c++;
		}
		else
			s2[j++] = c;
	}
	s2[j] = '\0';
}
/*{
	int i, j, expan;

	for (i = 0; s1[i] != '\0'; i++){
		if (s1[i] == '-' && s1[i-1] != ' ' && s1[i+1] != ' '){		//checking whether - symbol is for expantion
			for( expan = s1[i-1]; expan <= s1[i+1]; expan++)	//getting the range of expantion
				s2[j++] = expan;				//expanding...........
			}	
		else
			s2[j++] = s1[i];					//non expanded data
	}
//	s2[j++] = '\0';
//}*/


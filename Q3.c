/* reverse words that do not have vowels */
#include <stdio.h>

int main()
{
	FIlE *input, *output;
	input  = fopen("a.txt", "r");
	output = fopen("b.txt", "w");

	char buffer[50];
	fscanf(input,"%s",buffer);
	int i,flag;
	flag = 0; // means no vowel

	while( feof(input) )
	{
		for (i=0; i<50; i++)
		{
			if ( buffer[i] == "a") // aeiou 
			{
				flag = 1;
				break;
			}
		}

		if (flag == 0)
		{
			// print the exact same word

		}
		else if (flag == 1)
		{
			flag = 0;
			// print in reverse
		}

	}

	fclose(input);
	fclose(output);

	return 0;
}
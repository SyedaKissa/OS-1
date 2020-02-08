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
			if ( buffer[i] == "a" || buffer[i] == "e" || buffer[i] == "i" || buffer[i] == "o" || buffer[i] == "u" || 
			     buffer[i] == "A" || buffer[i] == "E" || buffer[i] == "I" || buffer[i] == "O" || buffer[i] == "U")
			{
				flag = 1;
				break;
			}
		}

		if (flag == 0)
		{
			// print the exact the same


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
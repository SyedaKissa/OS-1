/* reverse words that do not have vowels */
#include <stdio.h>
#include <string.h>

int main()
{
	FIlE *input,*output;
	input  = fopen("a.txt", "r");
	output = fopen("b.txt", "w");

	char buffer[50];
	char reverse[50];

    //Cleaning the Buffers        
    memset(buffer,'\0',sizeof(buffer));
    memset(reverse,'\0',sizeof(reverse));

	//fscanf(input,"%s",buffer);
	int i,j,length,flag;
	flag = 0; // means no vowel

	while( fscanf(input,"%s",buffer) != EOF )
	{
		for (i=0; i<50; i++)
		{
			if ( buffer[i] == 'a' || buffer[i] == 'e' || buffer[i] == 'i' || buffer[i] == 'o' || buffer[i] == 'u' || 
			     buffer[i] == 'A' || buffer[i] == 'E' || buffer[i] == 'I' || buffer[i] == 'O' || buffer[i] == 'U')
			{
				flag = 1;
				break;
			}
		}

		if (flag == 0)
		{
			// print the exact the same
			fputs(buffer, output);
		}
		else if (flag == 1)
		{
			flag = 0;
			// print in reverse
			length = strlen(buffer); // strlen() function doesn't count the null character \0 while calculating the length
            i = 0;
			for (j=length-1; j>=0; j--)
			{
				reverse[j] = buffer[i];
				i++;
			}
			reverse[length] = '\0';
			fputs(reverse, output);		
		}

		//Cleaning the Buffers        
        memset(buffer,'\0',sizeof(buffer));
        memset(reverse,'\0',sizeof(reverse));

        //fscanf(input,"%s",buffer);
	}

	fclose(input);
	fclose(output);

	return 0;
}
/* reverse words that do not have vowels */
#include <stdio.h>
#include <string.h>

int main(int argc, char* arg[])
{
	FILE *input,*output;

	if( *arg[1] == 'a')
	{
		input = fopen ("q3_a.txt","r");
	}
	else if( *arg[1] == 'b')
	{
		input = fopen ("q3_b.txt","r");
	}
	else
	{
		printf("Incorrect arguement \n");
		exit(0);
	}

	//input  = fopen("a.txt", "r");
	output = fopen("output.txt", "w");

	char buffer[25];
	char reverse[25];

    //Cleaning the Buffers        
    memset(buffer,'\0',sizeof(buffer));
    memset(reverse,'\0',sizeof(reverse));

	int i,j,length,flag;
	flag = 0; // means no vowel

	while( fscanf(input,"%s",buffer) != EOF )
	{
		printf("buffer: %s\n ", buffer);
		for (i=0; i<25; i++)
		{
			printf("character : %c\n ", buffer[i]);
			
			if ( buffer[i] == 'a' || buffer[i] == 'e' || buffer[i] == 'i' || buffer[i] == 'o' || buffer[i] == 'u' || 
			     buffer[i] == 'A' || buffer[i] == 'E' || buffer[i] == 'I' || buffer[i] == 'O' || buffer[i] == 'U'){
				
				printf("character inside if : %c\n ", buffer[i]);
				flag = 1;
				break;
			}
		}

		length = strlen(buffer); // strlen() function doesn't count the null character \0 while calculating the length
 
		if (flag == 1) // have vowels so print same
		{	
		    flag = 0;		
            buffer[length] = ' ';
			fputs(buffer, output);			
		}
		else if (flag == 0) // have no vowels so print in reverse
		{					
			i = 0;
			for (j=length-1; j>=0; j--)
			{
				reverse[j] = buffer[i];
				i++;
			}
			reverse[length] = ' ';
			reverse[length+1] = '\0';
			fputs(reverse, output);					
		}

		//Cleaning the Buffers        
        memset(buffer,'\0',sizeof(buffer));
        memset(reverse,'\0',sizeof(reverse));
	}

	fclose(input);
	fclose(output);

	return 0;
}
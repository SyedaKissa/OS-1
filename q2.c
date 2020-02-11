#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{	
	FILE *output;	
	output = fopen("b.txt", "a+");

	int option = 0;
	int total_record = -1; // keeping track of the total records of students
	int find_record = -1; // the record number students types in option 2
	
	int j,counter;
	
	char Name[50];
	char Rollnumber[9];
	char email[50];

	char buffer[50];
	char buffer2[50];
	char c;

	//Cleaning the Buffers
	
	memset(buffer,'\0',sizeof(buffer)); 
	memset(buffer2,'\0',sizeof(buffer2));       
    memset(Name,'\0',sizeof(Name));
    memset(Rollnumber,'\0',sizeof(Rollnumber));
    memset(email,'\0',sizeof(email));

while (1) 
{    
    printf("%s\n", "1) Add a new student" );
	printf("%s\n", "2) Read student record ");
	printf("%s\n", "3) Delete student record");
	printf("%s\n", "4) Exit");
	printf("%s\n", "Please select one of the options as (1 or 2 or 3 or 4)");

	scanf("%d",&option); // & is added with scanf when dealing with integers

	if (option == 4) 
	{ 
		printf("%s\n", "Exiting the whole program");
		break; 
	}
	else if (option == 1)
	{
		output = fopen("b.txt", "a+");

		printf("%s\n", "Please type in Name of the student");
		scanf("%s",Name); // & is added with scanf
		printf("%s\n", "Please type in Roll Number of the student");
		scanf("%s",Rollnumber); // & is added with scanf
		printf("%s\n", "Please type in Email of the student");
		scanf("%s",email); // & is added with scanf

		fprintf(output, "Name: %s Roll No: %s Email: %s\n", Name, Rollnumber, email);
		total_record = total_record+1;
		
		fclose(output); // necessary to close file after ever option in it 
	}
	else if (option == 2)
	{
		output = fopen("b.txt", "r");

		printf("%s\n", "Please type in the record number");
		scanf("%d",&find_record); // & is added with scanf		

		if (find_record <0 || find_record > total_record) { printf("%s\n", "This record is not available" ); }
		else
		{
			counter = 0;
			while ( (c=fgetc(output)) != EOF )
			{
				if ( c == '\n' && counter >= (find_record-1))
				{
					printf(" \n");
					break;
				}
				if ( counter == (find_record-1))
				{					
					printf("%c", c);
				}
				if ( c == '\0' && counter < (find_record-1))
				{
					counter++;
				}								
			}
		}
		
		find_record = -1;
		fclose(output);
	}
	else if (option == 3)
	{
		output = fopen("b.txt", "a+");

		printf("%s\n", "Please type in the record number to delete");
		scanf("%d",&find_record); // & is added with scanf

		if (find_record <0 || find_record > total_record) { printf("%s\n", "This record is not available" ); }
		else
		{
			counter = 1;
			while(1)
			{   
			    if (counter < find_record || counter > find_record)	
			    {
			    	if (fgets(buffer,100,output) != EOF )
			    	{
			    		strcat(buffer2, buffer);
			    	    counter++;
			    	    printf("Buffer 2%s\n", buffer2);
			    	}			    	
			    }			    
			}
		}
		
		find_record = -1;
		fclose(output);
	}
	else 
	{
		printf("%s\n", "Please type in the correct option");
	}

	option = 0;

    //Cleaning the Buffers	
	memset(buffer,'\0',sizeof(buffer));       
    memset(Name,'\0',sizeof(Name));
    memset(Rollnumber,'\0',sizeof(Rollnumber));
    memset(email,'\0',sizeof(email));	
}
    fclose(output);
	return 0;
}
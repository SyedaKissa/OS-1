#include <stdio.h>
#include <string.h>

int main()
{	
	FILE *output;	
	output = fopen("b.txt", "a+");

	int option = 0;
	int record = -1;

	char Name[50];
	char Rollnumber[9];
	char email[50];

	//Cleaning the Buffers        
    memset(Name,'\0',sizeof(Name));
    memset(Rollnumber,'\0',sizeof(Rollnumber));
    memset(email,'\0',sizeof(email));

while (option != 4) 
{
	printf("%s\n", "1) Add a new student" );
	printf("%s\n", "2) Read student record ");
	printf("%s\n", "3) Delete student record");
	printf("%s\n", "4) Exit");
	printf("%s\n", "Please select one of the options as (1 or 2 or 3 or 4)");

	scanf("%d",&option); // & is added with scanf when dealing with integers

	if (option == 4) { break; }
	else if (option == 1)
	{
		printf("%s\n", "Please type in Name of the student");
		scanf("%s",Name); // & is added with scanf
		printf("%s\n", "Please type in Roll Number of the student");
		scanf("%s",Rollnumber); // & is added with scanf
		printf("%s\n", "Please type in Email of the student");
		scanf("%s",email); // & is added with scanf

		printf("Name : %s\n", Name);
		printf("Roll number : %s\n", Rollnumber);
		printf("Email : %s\n", email);

		record++;

		fprintf(output, "Name: %s  Roll No: %s Email: %s \n", Name, Rollnumber, email);
		//fprintf(output, "Name: %s R ", Name);
		fclose(output); // necessary to close file after ever option in it 
	}
	else if (option == 2)
	{

	}
	else if (option == 3)
	{

	}
	else 
	{
		printf("%s\n", "Please type in the correct option");
	}

	option = 0;
	//Cleaning the Buffers        
    memset(Name,'\0',sizeof(Name));
    memset(Rollnumber,'\0',sizeof(Rollnumber));
    memset(email,'\0',sizeof(email));	
}
    fclose(output);
	return 0;
}
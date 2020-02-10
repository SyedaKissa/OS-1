#include <stdio.h>
#include <string.h>

int main()
{
	FILE *output;	
	output = fopen("b.txt", "w");

	char c[2];
	int option = 0;

while (option == 4) 
{
	printf("%s\n", "1) Add a new student" );
	printf("%s\n", "2) Read student record ");
	printf("%s\n", "3) Delete student record");
	printf("%s\n", "4) Exit");
	printf("%s\n", "Please select one of the options as (1 or 2 or 3 or 4)" );

	scanf("%d",&option); // & is added with scanf

	if (option == 4)
	{
		break;
	}
	else if (option == 1)
	{

	}
	else if (option == 2)
	{

	}
	else if (option == 3)
	{

	}
	else 
	{

	}
	option = 0;	
}

	return 0;
}
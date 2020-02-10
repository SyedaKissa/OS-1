#include <stdio.h>
#include <string.h>

int main()
{
	FILE *output;	
	output = fopen("b.txt", "w");

	printf("%s\n", "Please select one of the options as (1 or 2 or 3)" );
	printf("%s\n", "1) Add a new student" );
	printf("%s\n", "2) Read student record ");
	printf("%s\n", "3) Delete student record");
	return 0;
}
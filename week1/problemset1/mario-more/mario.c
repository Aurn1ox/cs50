#include <cs50.h>
#include <stdio.h>

int main(void) 
{
	// get input from 1-8
	// for loop 1 to n, ... and fill space for n-i times
	// add hashes i times
	
	int size;
	do
	{
		size = get_int("Size: ");
	}
	while ( size < 1 || size > 8);



	for ( int i=1; i<=size; i++ )
	{
		// left pyramid
		for ( int j = 1; j<=size-i; j++ )
		{
			printf(" ");
		}
		for ( int j = 1; j<=i; j++ )
		{
			printf("#");
		}
		printf(" ");

		// right pyramid ( reversed code )
		for ( int j = 1; j<=i; j++ )
		{
			printf("#");
		}
		for ( int j = 1; j<=size-i; j++ )
		{
			printf(" ");
		}

		printf("\n");
	}
    
}

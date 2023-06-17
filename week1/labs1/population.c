#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
	// greater than 9
	int start_size, ending_size;

	do
	{
		start_size = get_int("Start Size: ");
	}
	while (start_size < 9);

    // TODO: Prompt for end size
	// greatert than start size
	do
	{
		ending_size = get_int("End Size: ");
	}
	while (ending_size < start_size);

    // TODO: Calculate number of years until we reach threshold
	int n = start_size;
	int years = 0;
	while (n < ending_size)
	{
		n = n + (n/3) - (n/4);
		years++;
	}

    // TODO: Print number of years
	printf("%i Years\n", years);
}

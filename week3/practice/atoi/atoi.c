#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO
	int num = 0;
	
	if (strlen(input) == 0)
	{
		return 0;
	}

	int lastchar = strlen(input) - 1;
	int digit = input[lastchar] - '0';
	input[lastchar] = '\0';
	num = convert(input);

	num = num * 10 + digit; 

	return num;
}

#include <cs50.h>
#include <stdio.h>

int factorial(int number);

int main(void)
{
	int number;

	do
	{
		number = get_int("Enter the number: ");
	} while (number < 1);

	printf("The factorial of %i is: %i\n", number, factorial(number));
}

int factorial(int number)
{
	if (number == 1)
	{
		return number;
	}

	return number * factorial(number - 1);
}



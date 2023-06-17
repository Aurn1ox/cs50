#include <cs50.h>
#include <stdio.h>

int length(long);
long power_of_10(int);
int checksum_calculate(long);

int main(void) 
{
	const long CARD_NUMBER = get_long("Card Number: ");

	int total = checksum_calculate(CARD_NUMBER);

	if (total % 10 == 0 && length(CARD_NUMBER) != 0)
	{
		int first_two_digits = CARD_NUMBER / power_of_10(length(CARD_NUMBER)-2);
		int first_digit = CARD_NUMBER / power_of_10(length(CARD_NUMBER)-1);

		if (first_two_digits == 34 || first_two_digits == 37)
		{
			printf("AMEX\n");
		}
		else if (first_two_digits >= 51 && first_two_digits <= 55)
		{
			printf("MASTERCARD\n");
		}
		else if (first_digit == 4)
		{
			printf("VISA\n");
		}

	}
	else
	{
		printf("INVALID\n");
	}
}






// Calculating the checksum of the card
// returns total
int checksum_calculate(long card_number)
{
	int sum = 0;
	int digit1, digit2;
	while (card_number > 0)
	{

		digit1 = card_number % 10;
		sum += digit1;

		card_number /= 10;

		digit2 = (card_number % 10) * 2;

		sum += (digit2 % 10);
		if (digit2 > 10)
		{
			sum += (digit2/10 % 10);
		}
		
		card_number /= 10;
	}
	return sum;
}

// Power of 10 cus c doesnt have it
long power_of_10(int n)
{
	long power_of_10 = 1;
	for (int i=0; i<n; i++)
	{
		power_of_10 *= 10;
	}
	return power_of_10;
}

// Calculating length of number
int length(long number)
{
	// Greater than 16
	if (number >= 1* power_of_10(16))
	{
		return 0;
	}

	if (number >= 1 * power_of_10(15))
	{
		return 16;
	}
	if (number >= 1 * power_of_10(14))
	{
		return 15;
	}
	if (number >= 1 * power_of_10(13))
	{
		return 14;
	}
	if (number >= 1 * power_of_10(12))
	{
		return 13;
	}
	// Lesser than 13
	return 0;
}

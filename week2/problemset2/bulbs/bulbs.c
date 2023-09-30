#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
	// get string
	// convert string to binary 
	// iterate over each binary bit and print it
	//
	string message = get_string("Message: ");
	char character;

	int byte[BITS_IN_BYTE];

	for (int i = 0; i < strlen(message); i++)
	{
		character = message[i];

		for (int j = 7; j >= 0; j--)
		{
			if (character % 2 == 0)
			{
				byte[j] = 0;
			}
			else
			{
				byte[j] = 1;
			}

			character = character / 2;
		}

		for (int i = 0; i < BITS_IN_BYTE; i++)
		{
			print_bulb(byte[i]);
		}

		printf("\n");
	}

}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>

int length(string);
string replace(string);

int main(int argc, string argv[])
{
	if (argc < 2)
	{
		printf("Error, no arguments provided\n");
		return 1;
	}

	for (int i = 1; i < argc; i++)
	{
		printf("%s ", replace(argv[i]));
	}
	printf("\n");
}

int length(string string)
{
	int count = 0;
	
	while (string[count] != '\0')
	{
		count ++;
	}

	return count;
}

string replace(string word)
{
	for (int j = 0; j < length(word); j++)
	{
		if (word[j] == 'a')
		{
			word[j] = '6';
		}
		else if (word[j] == 'e')
		{
			word[j] = '3';
		}
		else if (word[j] == 'i')
		{
			word[j] = '1';
		}
		else if (word[j] == 'o')
		{
			word[j] = '0';
		}
	}
	return word;
}

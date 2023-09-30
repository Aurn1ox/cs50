#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]) 
{

	if (argc != 2)
	{
		printf("Usage: ./substitution <key>\n");
		return 1;
	}

	if (strlen(argv[1]) != 26)
	{
		printf("Key should be 26 characters long\n");
		return 1;
	}

	string plain_text = get_string("plaintext: ");
	string cypher = argv[1];

	int letterPos, difference;

	printf("cypher: ");
	
	for (int i = 0; i < strlen(plain_text); i++)
	{
		if (isalpha(plain_text[i]))
		{
			letterPos = toupper(plain_text[i]) - 65;
			difference = toupper(cypher[letterPos]) - toupper(plain_text[i]);
			printf("%c", plain_text[i] + difference);
		}
		else
		{
			printf("%c", plain_text[i]);
		}
	}

	printf("\n");



	// find difference between character and cypher character



}

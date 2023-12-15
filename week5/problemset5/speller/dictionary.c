// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Local function prototype
void free_node(node *ptr);

// TODO: Choose number of buckets in hash table
const unsigned int N = 26*LENGTH*LENGTH;

// Hash table
node *table[N];

// Word count
int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
	// Hash word to integer
	int word_hash = hash(word);

	// Check if node exists in index
	if (table[word_hash] == NULL)
	{
		return false;
	}

	// Check first node
	node *cursor = table[word_hash];
	if (strcasecmp(word, cursor->word) == 0)
	{
		return true;
	}
	
	// Traverse through linked list if nodes exist
	while (cursor->next != NULL)
	{
		cursor = cursor->next;
		if (strcasecmp(word, cursor->word) == 0)
		{
			return true;
		}
	}

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
	int sum = 0;
	int worlen = strlen(word);
    for (int i = 0; i < worlen ; i++)
	{
		if (word[i] != '\'')
		{
			sum += tolower(word[i]) - 'a';
		}
	}

	return sum * worlen;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
	FILE *dict = fopen(dictionary, "r");
	if (dict == NULL)
	{
		return false;
	}

	char *buffer;
	buffer = malloc(LENGTH + 1);
	if (buffer == NULL)
	{
		fclose(dict);
		printf("Error allocating memory.\n");
		return 1;
	}
	char c;
	int index = 0;

	while (fread(&c, 1, 1, dict) == 1)
	{
		if (c == '\n')
		{
			// Increment word counter
			word_count++;

			// Indicate end of string
			buffer[index] = '\0';
			index = 0;

			// Get hash of word
			int word_hash = hash(buffer);

			// Create node to store word
			node *word;
			word = malloc(sizeof(node));
			if (word == NULL)
			{
				fclose(dict);
				free(buffer);
				printf("Error allocating memory.\n");
				return 1;
			}

			strcpy(word->word, buffer);
			word->next = NULL;


			// Check if node exists in array;
			if (table[word_hash] == NULL)
			{
				table[word_hash] = word;
			}

			// Iterate till we find end node
			else
			{
				node *temp;
				temp = table[word_hash];
				while (temp->next != NULL)
				{
					temp = temp->next;
				}

				// Append word to the linked list
				temp->next = word;
			}
		}

		else
		{
			// Append character to word buffer
			buffer[index++] = c;
		}
	}

	free(buffer);
	fclose(dict);

	return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
	for (int i = 0; i < N; i++)
	{
		if (table[i] != NULL)
		{
			free_node(table[i]);
		}
	}
    return true;
}

void free_node(node *ptr)
{
	if (ptr->next != NULL)
	{
		free_node(ptr->next);
	}

	free(ptr);
}

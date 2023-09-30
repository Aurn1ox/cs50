#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int calculate_grade(string Text);
int count_letters(string Text);
int count_words(string Text);
int count_sentences(string Text);


int main(void) 
{
	string text = get_string("Enter the text: ");

	int grade = calculate_grade(text);

	if (grade < 1)
	{
		printf("Before Grade 1\n");
	}

	else if (grade > 16)
	{
		printf("Grade 16+\n");
	}

	else
	{
		printf("Grade %i\n", grade);
	}
}

int calculate_grade(string Text)
{
	int letters, words, sentences, grade = 0;

	letters = count_letters(Text);
	words = count_words(Text);
	sentences = count_sentences(Text);

	grade = 0.0588 * ((float) letters/words)*100 - 0.296 * ((float) sentences/words)*100 - 15.8;
	
	return round(grade);
}


int count_letters(string Text)
{
	int letters = 0;

	for (int i = 0; i < strlen(Text); i++)
	{
		if (isalpha(Text[i]))
		{
			letters++;
		}
	}

//	printf("Letters: %i\n", letters);

	return letters;
}

int count_words(string Text)
{
	int words = 0;

	for (int i = 0; i < strlen(Text); i++)
	{
		if (isspace(Text[i]))
		{
			words++;
		}
	}
	words++;

//	printf("Words: %i\n", words);

	return words;
}

int count_sentences(string Text)
{
	int sentences = 0;

	for (int i = 0; i < strlen(Text); i++)
	{
		if(Text[i] == '.' || Text[i] == '!' || Text[i] == '?')
		{
			sentences++;
		}
	}

//	printf("Sentences: %i\n", sentences);

	return sentences;
}	

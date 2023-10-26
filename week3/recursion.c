#include <stdio.h>
#include <cs50.h>

void draw(int size);


int main(void)
{
	int size = get_int("Size of pyramid: ");

	draw(size);
}

void draw(int size)
{
	if (size <= 0)
	{
		return;
	}

	draw(size - 1);

	for (int i = 0; i < size; i++)
	{
		printf("#");
	}

	printf("\n");
}

#include <cs50.h>
#include <stdio.h>

int get_size(void);
void print_grid(int size);

int main(void)
{
	int n = get_size();

	print_grid(n);
}


int get_size(void)
{
	int size;
	do
	{
		size = get_int("Size: ");
	}
	while (size < 1);

	return size;
}


void print_grid(int size)
{
	for (int i=0; i<size; i++)
	{
		for (int j=0; j<size; j++)
		{
			printf("#");
		}
		printf("\n");
	}
}

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int number;
	struct node *next;
}
node;

int main(int argc, char *argv[])
{
	node *list = NULL;

	for (int i = 1; i < argc; i++)
	{
		int number = atoi(argv[i]);

		// allocate new node
		node *n = malloc(sizeof(node));
		if (n == NULL)
		{
			return 1;
		}

		n->number = number;
		n->next = NULL;

		// point new node to beginning of list
		n->next = list;

		// update list to point at first node
		list = n;
	}

	node *ptr = list;

	while (ptr != NULL)
	{
		printf("%i\n", ptr->number);
		ptr = ptr->next;
	}

	ptr = list;

	while (ptr != NULL)
	{
		node *next = ptr->next;
		free(ptr);
		ptr = next;
	}
	
}

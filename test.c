#include<stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
printf("Can I remember how to print things? Let's find out.\n");

int pointer_counter = 0;

struct node {
	int value;
	struct node *next;
};

int count;

if (argc > 1)
{
	for (count = 1; count < argc; count ++)
	{
		printf("argv[%d] = %s\n", count, argv[count]);
	}
}

struct node *pointer = (struct node*) malloc(sizeof(struct node));

pointer->value=5;
pointer->next=NULL;


printf ("The location of the node is %d\n", pointer_counter);
printf ("The node contains: %d\n", pointer->value);
}


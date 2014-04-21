#include<stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
if (argc == 1){
printf("This takes a list of values to add to the nodes separated by spaces\n\n");
}

int pointer_counter = 0;

struct node {
	int value;
	struct node *next;
};

int count;

struct node *pointer;
struct node *head;

if (argc > 1)
{
	pointer = (struct node*) malloc(sizeof(struct node));
	head = pointer;
} else{
return 0;
}


for (count = 1; count < argc; count ++)
		{
			printf("argv[%d] = %s\n\n", count, argv[count]);
			pointer->value=atoi(argv[count]);
			pointer->next=(struct node*) malloc(sizeof(struct node));
			pointer=pointer->next;
		}

printf("This loops through the list\n");
pointer=head;

while (pointer->next != NULL)
{
	printf ("The location of the node is %d\n", pointer_counter);
	printf ("The node contains: %d\n", pointer->value);
	pointer_counter++;
	pointer=pointer->next;
}

}


#include<stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};


struct node *append_node(struct node * last, int value, int pos){
	if (last != NULL) {
		while (last->next!=NULL)
			{last=last->next;
		};
	};

	if (pos != 1){		
	last->next=(struct node*) malloc(sizeof(struct node));
	last=last->next;
	last->value=value;
	last->next=NULL;
	return (last);} 

	else if (pos == 1) {
		//This is the Head, don't create more!
		last->value=value;
		last->next=NULL;
		return (last);
	}
	printf("Something Failed\n");
	return (last);
}	

st

int main(int argc, char *argv[]){
if (argc == 1){
printf("This takes a list of values to add to the nodes separated by spaces\n\n");
}

int pointer_counter = 0;

int count;

struct node *pointer;
struct node *head;
struct node *tail;

if (argc > 1)
{
//Add in some organization
	pointer = (struct node*) malloc(sizeof(struct node));
	head = pointer;
	tail = pointer;
} else{
return 0;
}

//Move through the argument list skipping the program name (argv[0])
for (count = 1; count < argc; count ++)
		{
			printf("argv[%d] = %s\n\n", count, argv[count]);
			tail=append_node(tail, atoi(argv[count]), count);
		}




printf("This loops through the list\n");

//Final Checks
while (pointer != NULL)
{
	printf ("The location of the node is %d\n", pointer_counter);
	printf ("The node contains: %d\n", pointer->value);
	pointer_counter++;
	pointer=pointer->next;
}


}


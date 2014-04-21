#include<stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

int add_node(struct node *last, int value, int pos);


int main(int argc, char *argv[])
{
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
	pointer = (struct node*) malloc(sizeof(struct node));
	head = pointer;
	tail = pointer;
} else{
return 0;
}

//failling because tail already exist so it appends a new one
for (count = 1; count < argc; count ++)
		{
			printf("argv[%d] = %s\n\n", count, argv[count]);
			if (add_node(tail, atoi(argv[count]), count) == 1){ return 1;}; //failed to add
			printf("Will this reach the next statement?\n");
			tail=tail->next;
		}



printf("This loops through the list\n");

//Final Checks
//This fails on length of 1.
while (pointer->next != NULL)
{
	printf ("The location of the node is %d\n", pointer_counter);
	printf ("The node contains: %d\n", pointer->value);
	pointer_counter++;
	pointer=pointer->next;
}
}

int add_node(struct node *last, int value, int pos){
	//if (last->next != NULL) {
		//while (last->next!=NULL)
			//{last=last->next;
		//};
	//};

	if (pos != 1){		
	printf("calling malloc\n");


	//This fails here. I think it's because I'm trying to access memory in the main fuction
	last->next=(struct node*) malloc(sizeof(struct node));
	printf("moving forward\n");
	last=last->next;
	printf("assigning value\n");
	last->value=value;
	last->next=NULL;
	printf("returning\n");
	return 0;} 

	else {
		//this is the head as well
		last->value=value;
		last->next=NULL;
		return 0;
	}	
}


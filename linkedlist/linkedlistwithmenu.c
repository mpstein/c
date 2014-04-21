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

int main(int argc, char *argv[]){

int pointer_counter = 0;
int count;
struct node *pointer;
struct node *head;
struct node *tail;

printf("This is the menu of choices\n");
printf("--------------------------------------------------\n");
printf("Append Value:\t\t\t\t\t1\n");
printf("Add value as new Head:\t\t\t\t2\n");
printf("View List: \t\t\t\t\t3\n");
printf("View List starting a specific position:\t\t4\n");
printf("Remove value a specific position:\t\t5\n");
printf("--------------------------------------------------\n");
printf("Your choice? >> \t");
	
	switch(getchar() - '0')
	{
		case 1: 
			printf("This should 1\n");
			break;
		case 2: 
			printf("this should be 2\n");
			break;
		case 3: 
			printf("This should be 3\n");
			break;
		case 4: 
			printf("This should be 4\n");
			break;
		case 5: 
			printf("THis should be 5\n");
			break;
		default : printf("You suck at menus.");
	}



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


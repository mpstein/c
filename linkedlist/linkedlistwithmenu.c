#include<stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};


struct node *append_node(struct node * last){
//Loop for Values struct node *append_node(struct node * last, int value, int pos){
	if (last != NULL) {
		while (last->next!=NULL)
			{last=last->next;
		};
	};
do{
	printf("Keep entering numbers until you're done. Please hit enter after each value. \n");
	printf("Enter a value: ");
	int value = getchar() - '0';

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

struct node * new_head(struct node * head, int value){}
void view_list_from_head(struct node * head){}
void view_list_from_postition(struct node * head, int pos){}
struct node * remove_value(struct node * head, int pos){}

char menu(){
printf("This is the menu of choices\n");
printf("--------------------------------------------------\n");
printf("Append Value:\t\t\t\t\t1\n");
printf("Add value as new Head:\t\t\t\t2\n");
printf("View List: \t\t\t\t\t3\n");
printf("View List starting a specific position:\t\t4\n");
printf("Remove value a specific position:\t\t5\n");
printf("Quit this stupid demo program:   \t\t6\n");
printf("--------------------------------------------------\n");
printf("Your choice? >> \t");
	
	char value = getchar();
	switch(value)
	{
		case '1': 
		case '2': 
		case '3': 
		case '4': 
		case '5': 
			return value;
		default : 
			printf("You suck at menus, try again. \n\n\n");
			return '6';
	}	

}

int main(int argc, char *argv[]){

//Define Variables
int pointer_counter = 0;
int count;
struct node *pointer;
struct node *head;
struct node *tail;

char choice = menu();
	do{
		printf("%c\n\n\n", choice);

	switch (choice)
	{
		case 1:
			printf("Append a Value\n");
			
			//check if new list:
			if (head == NULL || pointer = NULL)
			{
				pointer = (struct node*) malloc(sizeof(struct node));
				head = pointer;
				tail = pointer;
			}
			
			//Please don't lose the head in this!
			//Need to Refactor so it prompts for Values in Method
			tail = append_node()	
	}	


	int choice = menu();
	} while(choice != '6');
return 0;
}

	//Move through the argument list skipping the program name (argv[0])
/*	for (count = 1; count < argc; count ++)
			{
				printf("argv[%d] = %s\n\n", count, argv[count]);
				tail=append_node(tail, atoi(argv[count]), count);
			}
*/

/* Add this back in to the end of main to automatically pritn evernthing
	printf("This loops through the list\n");

	//Final Checks
	while (pointer != NULL)
	{
		printf ("The location of the node is %d\n", pointer_counter);
		printf ("The node contains: %d\n", pointer->value);
		pointer_counter++;
		pointer=pointer->next;
	}


*/
#include<stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};


struct node *append_node(struct node * last){

	//Get Input Value
	int value;
	printf("Please hit enter after the value. \n");
	printf("Enter a value: ");
	//I'm worried about scanf, I'm not limiting or type of input. This could really fail specatularly!
	scanf("%d", &value);

	//Make sure I'm at the tail
	if (last != NULL) {
		while (last->next!=NULL)
			{last=last->next;
		};
	};
	
	last->next=(struct node*) malloc(sizeof(struct node));
	last=last->next;
	last->value=value;
	last->next=NULL;
	printf("I made a tail with value %d\n\n", value);
	return (last); 
}	

struct node * new_head(struct node * head){
	//Get Input Value
	int value;
	printf("Please hit enter after the value. \n");
	printf("Enter a value: ");
	scanf("%d", &value);

	//Build the new head
	struct node *temp_head = (struct node*) malloc(sizeof(struct node));
	temp_head->value=value;
	temp_head->next=head;
	printf("I made a head with a value of %d \n\n", value);
	return temp_head;
}


void view_list_from_head(struct node * head)
{
	while (head != NULL)
	{
		printf ("The node contains: %d\n", head->value);
		head=head->next;
	}
}


void view_list_from_postition(struct node * head)
{
	//Get Input Value
	int counter;
	int value;
	printf("Please hit enter after the value. \n");
	printf("Enter a position to start from, 0 - indexed: ");
	scanf("%d", &value);
	if (value < 0) {
			printf("Why'd you go and do that?\n");
			exit(1);
	}


}
struct node * remove_value(struct node * head, int pos){}

int menu(){
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
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
	
	int value; 
	scanf("%d", &value);
	switch(value)
	{
		case 1: 
		case 2: 
		case 3: 
		case 4: 
		case 5:
			return value;
		default : 
			printf("You suck at menus, you're done. \n\n\n");
			return 6;
	}	

}

int main(int argc, char *argv[]){

//Define Structure
struct node *pointer = (struct node*) malloc(sizeof(struct node));
struct node *head = NULL;
struct node *tail = NULL;

int choice;
	do{
		choice = menu();
		switch (choice)	{
			case 1 : 
				printf("Append a Value\n\n");
							//check if new list:
				if (head == NULL)
				{
					//Sending the premade pointer is fucking with it
					head = new_head(head);
					pointer = head;
					tail = head->next;
				} else
				{
					pointer = append_node(pointer);
				};
				break;
			
			case 2 : 
				printf("Add a new Head!\n\n");
				head = new_head(head);
				break;
			
			case 3 : 
				printf("View the list!\n\n");
				view_list_from_head(head);
				break;

			case 4 :
				printf("View the list from a Specified Position!\n\n");
				view_list_from_postition(head);
				break;	

			default : return 0;
		}	

		} while(choice != 6);
	return 0;
}

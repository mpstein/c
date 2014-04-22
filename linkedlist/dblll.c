//Questions - why are any of these not voids?

#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *prev;
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
	last->next->prev=last;
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

	if (head != NULL)
	{
		head->prev=temp_head;
	}
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
	printf("Enter a position to remove, 0-indexed and inclusive: ");
	scanf("%d", &value);
	if (value < 0) {
			printf("Why'd you go and do that?\n");
			exit(1);
	}

	//Move through the list
	int count;
	for (count = 0; count < value; count ++) 
		{
			if (head->next != NULL){ head=head->next;}
			else
			{
				printf("Way to ruin the day\n");
				exit(1);
			}
		}
	
	//Actually print
	while (head != NULL)
	{
		printf ("The node contains: %d\n", head->value);
		head=head->next;
	}	
}

void view_list_from_end(struct node * ptr)
{

	//Make Sure List Exists
	if (ptr == NULL)
	{
		printf("You tried to get me to segfault");
		return;
	}

	//Make sure I'm at the tail
	if (ptr != NULL) {
		while (ptr->next!=NULL)
			{ptr=ptr->next;
		};
	};


	//Get Input Value
	int counter;
	int value;
	printf("Please hit enter after the value. \n");
	printf("Enter how many to count backwards from, 0-indexed and inclusive: ");
	scanf("%d", &value);
	if (value < 0) {
			printf("Why'd you go and do that?\n");
			exit(1);
	}

	int count;
	for (count = 0; count < value; count ++) 
		{
			if (ptr->prev != NULL){ ptr=ptr->prev;}
			else
			{
				printf("Way to ruin the day\n");
				exit(1);
			}
		}

	while (ptr != NULL)
	{
		printf ("The node contains: %d\n", ptr->value);
		ptr=ptr->next;
	}	

}


struct node * remove_value(struct node * head)
{
	//Get Input Value
	int counter;
	int value;
	printf("Please hit enter after the value. \n");
	printf("Enter a position to remove, 0-indexed and inclusive: ");
	scanf("%d", &value);
	if (value < 0) {
			printf("Why'd you go and do that?\n");
			exit(1);
	}
	
	//Remove the head
	if (value == 0)
	{
		printf("You're deleting the head: %d\n", head->value);
		if (head->next != NULL)
		{
			printf("head->next != NULL\n");
			head=head->next;
			head->prev=NULL;
			printf("The new value is: %i\n", head->value);
			return head;			
		} else 
		{
			printf("Deleting the First AND Last element.\n");
			return NULL;
		}
//		return NULL;

	}

	struct node * tmp = head;
	//Move through the list
	int count;
	for (count = 0; count < value -1; count ++) 
		{
			if (tmp->next != NULL)
			{
				tmp=tmp->next;

			} else
			{
				printf("Out of bounds, exiting");
				exit(1);
			}
		}

	printf("You just deleted this value: %i\n", tmp->next->value);

//TODO : CHeck if removing last element
	if (tmp->prev == NULL && tmp->next == NULL)
	{
		printf("I don't know what to do when removing the only element. Sorry \n");
		return head;
	}

	//Am I popping the tail?
	if (tmp->next->next != NULL)
	{
		tmp->next=tmp->next->next;
		tmp->next->prev=tmp;
		return head;
	} else
	{
		tmp->next = NULL;
		return head;
	}
}

struct node * add_at_spot(struct node * head)
{
	//Get Location
	int value;
	int count;
	printf("Please hit enter after the value. \n");
	printf("Enter a position to insert into, 0-indexed and inclusive: ");
	scanf("%d", &value);
	if (value < 0) {
			printf("Why'd you go and do that?\n");
			exit(1);
	}
	if (value == 0){
		printf("calling add new_head\n\n");
		struct node * tmp = new_head(head);
		return(tmp);
	} 
	
	struct node * tmp = head;
	struct node * newnode = (struct node*) malloc(sizeof(struct node));
	
	//Move into position
	for (count = 0; count < value -1; count ++) 
		{
			if (tmp->next != NULL){ tmp=tmp->next;}
			else
			{
				printf("Way to ruin the day\n");
				exit(1);
			}
		}

	int new_value;

	//Begin the insertion process
	if (tmp->next->next != NULL)
	{
		printf("Enter a value: ");
		scanf("%d", &new_value);
		
		newnode->value=value;
		newnode->next=tmp->next->next;
		newnode->prev=tmp;

		newnode->next->prev=newnode;
		
		return head;
	} else
	{
		return (append_node(tmp));
	}

}

struct node * remove_first_value(struct node * head)
{
	return head;
}


int menu(){
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
printf("This is the menu of choices\n");
printf("--------------------------------------------------\n");
printf("Append Value:\t\t\t\t\t1\n");
printf("Add value as new Head:\t\t\t\t2\n");
printf("View List: \t\t\t\t\t3\n");
printf("View List starting a specific position:\t\t4\n");
printf("Remove value a specific position:\t\t5\n");
printf("View List counting backwards from:   \t\t6\n");
printf("Insert element at specified location:\t\t7\n");
printf("Delete First time value appears:   \t\t8\n");
printf("Quit this stupid demo program:   \t\t9\n");
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
		case 6:
		case 7:
		case 8:
		case 9:
			return value;
		default : 
			printf("You suck at menus, you're done. \n\n\n");
			exit(0);
	}	

}

int main(int argc, char *argv[]){

//Define Structure
//struct node *pointer = (struct node*) malloc(sizeof(struct node));
struct node *pointer = NULL;
struct node *head = NULL;


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
			
			case 5:
				printf("Remove at a specific position!\n\n");
				head = remove_value(head);
				break;

			case 6:
				printf("Count Backwards from End!\n\n");
				view_list_from_end(head);
				break;

			case 7:
				printf("Insert at specified location!\n\n");
//This could break 
				head = add_at_spot(head);
				break;
			case 8:
				printf("Remove first occurence of value!\n\n");
				head = remove_first_value(head);
				break;

			default : exit(0);
		}	

		} while(choice != 6);
	return 0;
}

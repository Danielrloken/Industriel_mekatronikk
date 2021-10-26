#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

/*
Internal node type 
struct node {
	struct node *next; pointer to a structure of type node
	struct node *prev; pointer to a structure of type node
	int data;
};

 Internal data type representing list 
struct list {
	struct node *head; pointer to a structure of type node
	struct node *tail; pointer to a structure of type node
	int length;
};

// Abstract data type for lists 
typedef struct list *list_t;
*/

/* Create an empty list */
list_t list_create()
{
	/*
	struct node node; // Declare node of type node
	// node specification 
	node.next = NULL;
	node.prev = NULL;
	node.data = 0;
	*/
	struct list list; /* Declare list of type list */
	/* list specification */
	list.head = NULL;
	list.tail = NULL;
	list.length = 0;
}


/* Delete the list and all internal nodes */
void list_delete(list_t list)
{

	struct node *temp = list->head; // Creat temporary node like head

	while(temp != NULL){
		temp = temp->next; // Make temp point to the second node
		free(list->head); // Free header node
		list->head = temp; // Update the head pointer to the second node
	}
}
/* Insert data in list at index */
void list_insert(list_t list, int index, int data)
{
	struct node *new_node; // Declare pointer to new_node of type node

	new_node = (struct node *)malloc(sizeof(struct node)); // dynamically allocate memory with same size as node with data type "struct node" of the pointer
	if (new_node == NULL)
	{
		printf("Error. Allocation was unsuccessful. \n");
		return;
	}
	struct node *temp = list->head; // Declare temporary pointer to head


	for (int i = 0; i <= index; i++) // Iterate trough linked list
	{
		if (i == index)
		{
			new_node->next = temp->next;
			new_node->prev = temp->prev;
			new_node->data = data;
			temp->next= new_node;
			return;
		}
		temp = temp->next; // Change pointer to next node
	}
	
}
/* Append data to end of list */
void list_append(list_t list, int data)
{
	struct node *new_node; // Declare pointer to new_node of type node

	new_node = (struct node *)malloc(sizeof(struct node)); // dynamically allocate memory with same size as node with data type "struct node" of the pointer
	if (new_node == NULL)
	{
		printf("Error. Allocation was unsuccessful. \n");
		return;
	}

	new_node->next = NULL;
	new_node->data = data;
	new_node->prev = list->tail;
	list->tail->next = new_node;
	list->tail = new_node;


}
/* Print data of list in order */
void list_print(list_t list)
{
	struct node *temp = list->head; // Declare temporary pointer to head

	for (int i = 0; i < list->length; i++)
	{
		printf("%d", temp->data);
		temp = temp->next; // Change pointer to next node
	}
	
}
/* Get sum of all list elements */
long list_sum(list_t list)
{
	struct node *temp = list->head; // Declare temporary pointer to head
	int sum;

	for (int i = 0; i < list->length; i++)
	{
		sum = sum + temp->data;
		temp = temp->next; // Change pointer to next node
	}
	return sum;
	
}
/* Get data at index */
int list_get(list_t list, int index)
{
	struct node *temp = list->head; // Declare temporary pointer to head

	for (int i = 0; i <= index; i++)
	{
		temp = temp->next; // Change pointer to next node
	}
	return temp->data;
}
/* Extract data at index */
int list_extract(list_t list, int index)
{
	struct node *temp = list->head; // Creat temporary node like head

	for (int i = 0; i < index; i++)
	{
		temp = temp->next; // Change pointer to next node
	}
	struct node *next_next = temp->next->next;
	free(temp->next);
	temp->next = next_next;
}

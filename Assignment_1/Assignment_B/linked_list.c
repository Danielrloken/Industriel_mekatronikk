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
	list_t list;
	struct node *new_head; // Declare pointer to new_head of type node
	struct node *new_tail; // Declare pointer to new_tail of type node

	new_head = (struct node *)malloc(sizeof(struct node)); // dynamically allocate memory with same size as node with data type "struct node" of the pointer
	if (new_head == NULL)
	{
		printf("Error. Allocation was unsuccessful. \n");
	}

	new_tail = (struct node *)malloc(sizeof(struct node)); // dynamically allocate memory with same size as node with data type "struct node" of the pointer
	if (new_tail == NULL)
	{
		printf("Error. Allocation was unsuccessful. \n");
	}

	new_head->next = new_tail;
	new_head->data = 0;

	
	new_tail->prev = new_head;
	new_tail->data = 0;

	//struct list list; /* Declare list of type list */
	/* list specification */
	list->head = new_head;
	list->tail = new_tail;
	list->length = 0;
	return list;
}

/* Delete the list and all internal nodes */
void list_delete(list_t list)
{

	struct node *temp = list->head; // Creat temporary node like head

	while (temp != NULL)
	{
		temp = temp->next; // Make temp point to the second node
		free(list->head);  // Free header node
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

	for (int i = 0; i < index; i++) // Iterate trough linked list
	{
		temp = temp->next; // Change pointer to next node
	}
	list->length = list->length +1;
	new_node->next = temp->next;
	new_node->prev = temp->prev;
	new_node->data = data;
	temp->next = new_node;
	return;
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

	struct node *current = list->tail;
	
	if (current->prev != NULL)
	{	
		current = current->prev;
		current->next = new_node;
		new_node ->prev = current;
		new_node ->next = list->tail;
		list->tail->prev = new_node;
		list->length = list->length +1;
	} else
	{
		printf("Error. Tail not connected. \n");
		return;
	}
}
/* Print data of list in order */
void list_print(list_t list)
{
	struct node *temp = list->head->next; // Declare temporary pointer to head

	for (int i = 0; i < list->length; i++)
	{
		printf("%d ", temp->data);
		temp = temp->next; // Change pointer to next node
	}
	printf("\n");
}
/* Get sum of all list elements */
long list_sum(list_t list)
{
	struct node *temp = list->head->next; // Declare temporary pointer to head
	int sum = 0;

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
	int ret_val = temp->next->data;
	
	list->length = list->length -1;
	struct node *next_next = temp->next->next;
	next_next ->prev = temp;
	free(temp->next);
	temp->next = next_next;
	return ret_val;
}

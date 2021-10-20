#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

/*
Internal node type 
struct node {
	struct node *next;
	struct node *prev;
	int data;
};

 Internal data type representing list 
struct list {
	struct node *head;
	struct node *tail;
	int length;
};
*/

/* Create an empty list */
list_t list_create()
{
	struct node node; // Declare node of type node
	/* node specification */
	node.next = NULL;
	node.prev = NULL;
	node.data = 0;

	struct list list; /* Declare list of type list */
	/* list specification */
	list.head = (struct node *)malloc(sizeof(list)); // dynamically allocate memory with same size as list with data type "struct node" of the pointer
	if (list.head == NULL)
	{
		printf("Error. Allocation was unsuccessful. \n");
		return 1;
	}
	list.tail = NULL;
	list.length = 0;
}

/* Delete the list and all internal nodes */
void list_delete(list_t list)
{

	struct node *temp = list->head; // Creat temporary node like head

	while(temp != NULL){
		temp = temp->prev; // Make temp point to the second node
		free(head); // Free header node
		head = temp; // Update the head pointer to the second node
	}
}
/* Insert data in list at index */
void list_insert(list_t list, int index, int data)
{
}
/* Append data to end of list */
void list_append(list_t list, int data)
{
}
/* Print data of list in order */
void list_print(list_t list)
{
}
/* Get sum of all list elements */
long list_sum(list_t list)
{
}
/* Get data at index */
int list_get(list_t list, int index)
{
}
/* Extract data at index */
int list_extract(list_t list, int index)
{
}

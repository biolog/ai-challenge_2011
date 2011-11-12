#include <stdlib.h>
#include <assert.h>
#include "list.h"
/*----------------------------------------------------------------------------*/
/* PRIVATE FUNCTIONS                                                          */
/*----------------------------------------------------------------------------*/
struct list_node *List_GetNextNode (struct list *list)
{
struct list_node *node;
        node = list->current_node;
	if (node == NULL)
		return NULL;
        list->current_node = list->current_node->next;
        return node;
}
/*----------------------------------------------------------------------------*/
/* PUBLIC FUNCTIONS                                                           */
/*----------------------------------------------------------------------------*/
void List_Init (struct list *list)
{
        list->current_node = NULL;
        list->list.prev = NULL;
        list->list.next = NULL;
}
/*----------------------------------------------------------------------------*/
void List_Add (struct list *list, void *data)
{
struct list_node *node_new;
struct list_node *node_old;
	/* generating new node */
	node_new = (struct list_node *)malloc (sizeof(struct list_node));
	assert (node_new != NULL);
	node_new->data = data;
	/* adding node to list */
	node_old = list->list.next;
	if (NULL != node_old)
		node_old->prev = node_new;
	node_new->prev = NULL;
	node_new->next = node_old;
	list->list.next = node_new;
	list->current_node = node_new;
}
/*----------------------------------------------------------------------------*/
void List_ResetToFirst (struct list *list) {
        list->current_node = list->list.next;
}
/*----------------------------------------------------------------------------*/
void *List_GetNextData (struct list *list)
{
struct list_node *node;
        node = List_GetNextNode (list);
	if (node == NULL)
		return NULL;
        return node->data;
}
/*----------------------------------------------------------------------------*/
void List_Destroy (struct list *list)
{
struct list_node *node;
struct list_node *node_next;
        List_ResetToFirst (list);
       	node = List_GetNextNode (list);
	if (node == NULL)
		return;
        while (1) {
        	node_next = List_GetNextNode (list);
                free (node);
		if (node_next == NULL)
			break;
		else
			node = node_next;
        }
}


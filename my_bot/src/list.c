#include <stdlib.h>
#include <assert.h>
#include "list.h"
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
void List_Destroy (struct list *list, int destroy_data)
{
struct list_node *node;
void *data;	
        List_ResetToFirst (list);
        while (1) {
		node = list->current_node;
		if (node == NULL)
			break;
		/* free data block of node */
		if (destroy_data) {
			data = List_GetData(list);
			if (data != NULL)
				free (data);
		}
		/* switch to next node */
		List_SwitchToNext (list);
		/* free memory from node itself */
		free (node);
        }
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
void *List_GetData (struct list *list)
{
	if (list->current_node == NULL)
		return NULL;
        return list->current_node->data;
}
/*----------------------------------------------------------------------------*/
void List_ResetToFirst (struct list *list) {
        list->current_node = list->list.next;
}
/*----------------------------------------------------------------------------*/
void List_SwitchToNext (struct list *list)
{
	if (list->current_node != NULL)
		list->current_node = list->current_node->next;
}


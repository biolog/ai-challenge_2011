#include <stdlib.h>
#include <assert.h>
#include "list.h"
/*----------------------------------------------------------------------------*/
/* PRIVATE FUNCTIONS                                                          */
/*----------------------------------------------------------------------------*/
void *List_GetNextNode (struct list *list, int first)
{
struct list_node *node;
        assert (list->current_node != NULL);
        if (first)
                list->current_node = list->list.next;
        node = list->current_node.next;
        if (NULL == node)
                return NULL;
        list->current_node = node;
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

}
/*----------------------------------------------------------------------------*/
void *List_GetNextData (struct list *list, int first)
{
struct list_node *node;
        node List_GetNextNode (list, first);
        return node.data;
}
/*----------------------------------------------------------------------------*/
void List_Destroy (struct list *list)
{
struct list_node *node;
struct list_node *node_next;
        node = List_GetNextNode (list, 1);
        while (node != NULL) {
                free (node);
        }
}


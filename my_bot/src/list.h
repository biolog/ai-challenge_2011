#ifndef __LIST__
#define __LIST__
/*----------------------------------------------------------------------------*/
/* TYPES                                                                      */
/*----------------------------------------------------------------------------*/
/* 
 * @struct node of the list
 */
struct list_node {
        void             *data;
        struct list_node *next;
        struct list_node *prev;
};
/* 
 * @struct the main structure for list
 */
struct list {
        struct list_node *current_node;
        struct list_node list;
};
/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/

/* @brief Initialize list.
 * @param [in] list Pointer to list sructure.
 * @return Nothing.
 */
void List_Init (struct list *list);

/* @brief Add data to the list.
 * @param [in] list Pointer to list sructure.
 * @param [in] data Pointer to data to be added.
 * @return Nothing.
 */
void List_Add (struct list *list, void *data);

/* @brief Set internal list poinetr to first data item.
 * @param [in] list Pointer to list structure.
 * @return Nothing.
 */ 
void List_ResetToFirst (struct list *list);

/* @brief Get next data buffer in list.
 * @param [in] list Pointer to list structure.
 * @return Pointer to data in list.
 */
void *List_GetNextData (struct list *list);

/* @brief Destroy list structure. All data will NOT be destroyed, 
 *        because them may be referenced somethere else.
 * @param [in] list Pointer to list structure.
 * @return Nothing.
 */
void List_Destroy (struct list *list);

#endif

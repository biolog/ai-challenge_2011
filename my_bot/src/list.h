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

/* @brief Destroy list structure. All data will NOT be destroyed, 
 *        because them may be referenced somethere else.
 * @param [in] list Pointer to list structure.
 * @param [in] destroy_data Flag. If != 0 then free() for data fields will be called.
 * @return Nothing.
 */
void List_Destroy (struct list *list, int destroy_data);


/* @brief Add data to the list.
 * @param [in] list Pointer to list sructure.
 * @param [in] data Pointer to data to be added.
 * @return Nothing.
 */
void List_Add (struct list *list, void *data);

/* @brief Get data buffer of current element in list.
 * @param [in] list Pointer to list structure.
 * @return Pointer to data in list.
 */
void *List_GetData (struct list *list);


/* @brief Set internal list poinetr to first data item.
 * @param [in] list Pointer to list structure.
 * @return Nothing.
 */ 
void List_ResetToFirst (struct list *list);

/* @brief Switch to next element in list.
 * @param [in] list Pointer to list structure.
 * @return Nothing.
 */
void List_SwitchToNext (struct list *list);

/* @brief Delete current element of list.
 * @param [in] list Pointer to list structure.
 * @return Nothing.
 */
void List_DeleteCurrent (struct list *list);

#endif

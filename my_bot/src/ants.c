#include <stdlib.h>
#include <assert.h>
#include "ants.h"
#include "logger.h"
/*----------------------------------------------------------------------------*/
/* PRIVATE FUNCTIONS                                                          */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* PUBLIC FUNCTIONS                                                           */
/*----------------------------------------------------------------------------*/
void Ants_Init(struct ant *ants)
{
	// this is first ant, so we do not initialize internal data, 
	// it will be used by references only
	ants->next = NULL;
	ants->prev = NULL;
}
/*----------------------------------------------------------------------------*/
void Ants_Destroy(struct ant *ants)
{
struct ant *curr_ant;
struct ant *curr_ant_pointer;
	if (ants == NULL)
		return;
	curr_ant = ants->next;
	while (curr_ant != NULL) {
		curr_ant_pointer = curr_ant;
		curr_ant = curr_ant->next;
		free (curr_ant_pointer);
	}
}
/*----------------------------------------------------------------------------*/
void Ants_AddNewAnt (
	struct ant *ants, 
	unsigned int row, 
	unsigned int col
) {
struct ant *ant;
struct ant *ant_next;
	/* allocating memory for new ant */
	ant = (struct ant *) malloc (sizeof (struct ant));
	assert (ant != NULL);
	/* filling information fiels */
	ant->row = row;
	ant->col = col; 
	/* relink the list */
	ant_next = ants->next;
	ant->prev = ants;
	ant->next = ant_next;
	ants->next = ant;
	Logger_INFO ("Added new ant");
}
/*----------------------------------------------------------------------------*/
void Ants_RemoveDeadAnt (struct ant *dead_ant)
{
struct ant *d_prev;
struct ant *d_next;
	d_prev = dead_ant->prev;
	d_next = dead_ant->next;
	d_prev->next = d_next;
	d_next->prev = d_prev;
	free (dead_ant);
	Logger_INFO ("Removed ant");
}
/*----------------------------------------------------------------------------*/
struct ant *Ants_SearchByPos (
	struct ant *ants,
	unsigned int row,
	unsigned int col
) {
struct ant *ant_curr;
	if (NULL == ants)
		return NULL;
	ant_curr = ants->next;
	while (ant_curr != NULL) {
		if (ant_curr->row == row && 
		    ant_curr->col == col
 		)
			return ant_curr;
		ant_curr = ant_curr->next;
	}
	return NULL;
}
/*----------------------------------------------------------------------------*/
void Ants_MoveTo (
	struct ant *ant,
	enum ants_move_directions direction
) {
	switch (direction) {
	case ANT_NORTH:
		ant->row = ant->row - 1;
		break;
	case ANT_SOUTH:
		ant->row = ant->row + 1;
		break;
	case ANT_EAST:
		ant->col = ant->col - 1;
		break;
	case ANT_WEST:
		ant->col = ant->col + 1;
		break;
	default:
		Logger_ERROR ("Wrong direction");
	};
}


#include <stdio.h>
#include <stdlib.h>
#include "ants.h"
#include "ai.h"
#include "game.h"
/*----------------------------------------------------------------------------*/
/* PRIVATE FUNCTIONS                                                          */
/*----------------------------------------------------------------------------*/
void AI_RandomNextTurn (
	struct ants_ai *ai, 
	struct map *map
) {
struct ant *curr_ant;
enum ants_move_directions direction;
	curr_ant = map->ants.next;
	while (curr_ant != NULL) {
		direction = (enum ants_move_directions) rand() % ANT_TOTAL_DIRECTIONS;
		ai->MoveFunc (curr_ant->row, curr_ant->col, direction);
		Ants_MoveTo (curr_ant, direction);
		curr_ant = curr_ant->next;
	}
}
/*----------------------------------------------------------------------------*/
void AI_SetTaskFood (
	struct ants_ai *ai, 
	struct map *map
) {
struct map_cell *food;
struct ant  *ant;
int    visible;
	food = Map_GetNextFood (map);
	while (food != NULL) {
		ant = Ants_GetNearestFree (&map->ants, food->row, food->col);
		if (ant == NULL)
			/* no free ants avaliable */
			/* TODO: need some algorithm to reassign job of some ants */
			break;
		visible = Map_IsPointVisible (
			map,
			ant->row, ant->col,
			food->row, food->col
		);
		if (visible)
			Ants_SetTask (ant, food->row, food->col, ANT_CMD_GATHER_FOOD);
	} 
}
/*----------------------------------------------------------------------------*/
void AI_SetTasks (
	struct ants_ai *ai, 
	struct map *map
) {
	AI_SetTaskFood (ai, map);
}
/*----------------------------------------------------------------------------*/
/* PUBLIC FUNCTIONS                                                           */
/*----------------------------------------------------------------------------*/
void AI_Initialize(
	struct ants_ai *ai,
        void (*MoveFunc) (
                unsigned int pos_x,
                unsigned int pos_y,
                enum ants_move_directions direction
        )
) {
	ai->MoveFunc = MoveFunc;
}
/*----------------------------------------------------------------------------*/
void AI_Destroy(struct ants_ai *ai)
{
}
/*----------------------------------------------------------------------------*/
void AI_DoNextTurn (
	struct ants_ai *ai, 
	struct map *map
) {
struct ant *ant;
enum ants_move_directions direction;
	AI_SetTasks (ai, map);
	ant = &map->ants;
	while (ant != NULL) {
		direction = Ants_GetNextMove (ant);
		ai->MoveFunc (
			ant->row, 
			ant->col, 
			direction
		);
		ant = ant->next;
	}
}


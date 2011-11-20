#include <stdio.h>
#include <stdlib.h>
#include "ants.h"
#include "ai.h"
#include "game.h"
/*----------------------------------------------------------------------------*/
/* PRIVATE FUNCTIONS                                                          */
/*----------------------------------------------------------------------------*/
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
}


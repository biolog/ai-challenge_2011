#ifndef __AI_ENGINE__
#define __AI_ENGINE__
#include "map.h"
#include "ants.h"
/*----------------------------------------------------------------------------*/
/* TYPES                                                                      */
/*----------------------------------------------------------------------------*/
struct ants_ai {
        void (*MoveFunc) (
                unsigned int pos_x,
                unsigned int pos_y,
                enum ants_move_directions direction
        );
};
/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
void AI_Initialize(
	struct ants_ai *ai,
        void (*MoveFunc) (
                unsigned int pos_x,
                unsigned int pos_y,
                enum ants_move_directions direction
        );
);
void AI_Destroy(struct ants_ai *ai);
void AI_DoNextTurn (
	struct ants_ai *ai, 
	struct map *map
);
#endif

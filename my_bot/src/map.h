#ifndef __MAP__
#define __MAP__
#include "ants.h"
#include "game.h"
/*----------------------------------------------------------------------------*/
/* TYPES                                                                      */
/*----------------------------------------------------------------------------*/
enum cell_type {
	CT_WATER,
	CT_FOOD,
	CT_HILL,
	CT_LIVE_ANT,
	CT_DEAD_ANT,
	CT_UNKNOWN,
};
struct map_cell {
	/* content of cell */
	enum cell_type type;
	unsigned short owner; 
	unsigned int   row;
	unsigned int   col;
	/* links */
	struct map_cell *prev;
	struct map_cell *next;
};
struct map {
	struct map_cell water;
	struct map_cell food;
	struct map_cell hill;
	struct map_cell enemies;
	struct ant ants;
};
/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
void Map_Init (struct map *map, const struct game_info *info);
void Map_Destroy (struct map *map );
void Map_ParseMapStr (struct map *map, const char *message);
struct map_cell *Map_GetNextFood (struct map *map);
int Map_IsPointVisible (
	struct map *map,
	unsigned int p1_row, unsigned int p1_col,
	unsigned int p2_row, unsigned int p2_col
);
#endif

#ifndef __MAP__
#define __MAP__
#include "game.h"
/*----------------------------------------------------------------------------*/
/* TYPES                                                                      */
/*----------------------------------------------------------------------------*/
enum cell_type {
	CT_WATER,
	CT_FOOD,
	CT_LIVE_ANT,
	CT_HILL,
	CT_DEAD_ANT,
	CT_UNKNOWN,
};
struct map_cell {
	enum cell_type type;
	unsigned short owner; 
};
struct map {
	unsigned int rows;
	unsigned int cols;
	struct map_cell *data;
	size_t           data_length;
};
/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
void Map_Init (struct map *map, const struct game_info *info);
void Map_Destroy (struct map *map );
int Map_ParseMapStr (struct map *map, const char *message);
#endif

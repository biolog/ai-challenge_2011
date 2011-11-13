#ifndef __MAP__
#define __MAP__
#include "game.h"
#include "list.h"
/*----------------------------------------------------------------------------*/
/* TYPES                                                                      */
/*----------------------------------------------------------------------------*/
struct map {
	struct list water;
	struct list food;
	struct list hill;
	struct list enemies;
	struct list ants;
};
/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
void Map_Init (struct map *map);
void Map_Destroy (struct map *map );

void Map_ParseMapStr (struct map *map, const char *message);
#endif

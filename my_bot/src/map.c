#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "game.h"
#include "map.h"
#include "logger.h"
/*----------------------------------------------------------------------------*/
/* TYPES                                                                      */
/*----------------------------------------------------------------------------*/
enum map_errors {
	MAP_OK,
	MAP_CANT_PARSE
};
/*----------------------------------------------------------------------------*/
struct map_cell {
	/* content of cell */
	unsigned short owner; 
	unsigned int   row;
	unsigned int   col;
};
/*----------------------------------------------------------------------------*/
/* PRIVATE FUNCTIONS                                                          */
/*----------------------------------------------------------------------------*/
void Map_AddMyAnt (unsigned int row, unsigned int col)
{
	/* search for ant */
	/*TODO*/
}
/*----------------------------------------------------------------------------*/
void Map_AddEnemyAnt (unsigned int row, unsigned int col, unsigned short owner)
{
	/*TODO*/
}
/*----------------------------------------------------------------------------*/
int Map_ParseWaterStr (struct map *map, const char *message)
{
unsigned int row;
unsigned int col;
unsigned int scanned;
struct map_cell *cell;
	scanned = sscanf(message, "%d %d", &row, &col);
	if (scanned < 2)
		return -1;
	cell = (struct map_cell *) malloc (sizeof (struct map_cell));
	assert (cell != 0);
	cell->owner = 0;
	cell->row = row;
	cell->col = col;
	List_Add (&map->water, cell);
	return 0;
}
/*----------------------------------------------------------------------------*/
int Map_ParseFoodStr (struct map *map, const char *message)
{
unsigned int row;
unsigned int col;
unsigned int scanned;
struct map_cell *cell;
	scanned = sscanf(message, "%d %d", &row, &col);
	if (scanned < 2)
		return -1;
	cell = (struct map_cell *) malloc (sizeof (struct map_cell));
	assert (cell != 0);
	cell->owner = 0;
	cell->row = row;
	cell->col = col;
	List_Add (&map->food, cell);
	return 0;
}
/*----------------------------------------------------------------------------*/
int Map_ParseHillStr (struct map *map, const char *message)
{
unsigned int row;
unsigned int col;
unsigned int owner;
unsigned int scanned;
struct map_cell *cell;
	scanned = sscanf(message, "%d %d %d", &row, &col, &owner);
	if (scanned < 3)
		return -1;
	cell = (struct map_cell *) malloc (sizeof (struct map_cell));
	assert (cell != 0);
	cell->owner = (unsigned short) owner;
	cell->row = row;
	cell->col = col;
	List_Add (&map->hill, cell);
	return 0;
}
/*----------------------------------------------------------------------------*/
int Map_ParseAntLiveStr (struct map *map, const char *message)
{
unsigned int row;
unsigned int col;
unsigned int owner;
unsigned int scanned;
	scanned = sscanf(message, "%d %d %d", &row, &col, &owner);
	if (scanned < 3)
		return -1;
	if (owner == 0)
		/* this is my ant */
		Map_AddMyAnt (row, col);
	else
		/* enemy ant */
		Map_AddEnemyAnt (
			row, col, 
			(unsigned short)owner
		);
	return 0;
}
/*----------------------------------------------------------------------------*/
int Map_ParseAntDeadStr (struct map *map, const char *message)
{
unsigned int row;
unsigned int col;
unsigned int owner;
unsigned int scanned;
	scanned = sscanf(message, "%d %d %d", &row, &col, &owner);
	if (scanned < 3)
		return -1;
	if (owner == 0)
		/* this is my ant */
		Map_RemoveAnt (map, row, col);
	return 0;
}
/*----------------------------------------------------------------------------*/
/* PUBLIC FUNCTIONS                                                           */
/*----------------------------------------------------------------------------*/
void Map_Init (struct map *map)
{
	List_Init (&map->water);
	List_Init (&map->food);
	List_Init (&map->hill);
	List_Init (&map->enemies);
	List_Init (&map->ants);
}
/*----------------------------------------------------------------------------*/
void Map_Destroy (struct map *map )
{
	List_Destroy (&map->water, 1);
	List_Destroy (&map->food, 1);
	List_Destroy (&map->hill, 1);
	List_Destroy (&map->enemies, 1);
	List_Destroy (&map->ants, 1);
}
/*----------------------------------------------------------------------------*/
void Map_ParseMapStr (struct map *map, const char *message)
{
const char *message_body;
enum map_errors ret_code = MAP_CANT_PARSE;
	message_body = &message[2];
	switch (message[0]) {
	case LETTER_WATER:
		ret_code = Map_ParseWaterStr (map, message_body);
		break;
	case LETTER_FOOD:
		ret_code = Map_ParseFoodStr (map, message_body);
		break;
	case LETTER_HILL:
		ret_code = Map_ParseHillStr (map, message_body);
		break;
	case LETTER_ANT_LIVE:
		ret_code = Map_ParseAntLiveStr (map, message_body);
		break;
	case LETTER_ANT_DEAD:
		ret_code = Map_ParseAntDeadStr (map, message_body);
		break;
	default:
		Logger_ERROR ("Can't recognize type of map string");
	}
	if (MAP_OK != ret_code) {
		Logger_ERROR ("Can't understand map string");
	}
}

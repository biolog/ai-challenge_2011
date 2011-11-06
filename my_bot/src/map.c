#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "game.h"
#include "map.h"
#include "logger.h"
/*----------------------------------------------------------------------------*/
/* MAPCELL functions                                                          */
/*----------------------------------------------------------------------------*/
void MapCell_Init (struct map_cell *cell)
{
	cell->next = NULL;
	cell->prev = NULL;
	cell->type = CT_UNKNOWN;
}
/*----------------------------------------------------------------------------*/
/* PRIVATE FUNCTIONS                                                          */
/*----------------------------------------------------------------------------*/
int Map_ParseWaterStr (struct map *map, const char *message)
{
unsigned int row;
unsigned int col;
unsigned int scanned;
struct map_cell *cell;
struct map_cell *cell_next;
	scanned = sscanf(message, "%d %d", &row, &col);
	if (scanned < 2)
		return -1;
	cell = (struct map_cell *) malloc (sizeof (struct map_cell));
	assert (cell != 0);
	cell->type = CT_WATER;
	cell->owner = 0;
	cell->row = row;
	cell->col = col;
	/* relink the list */
	cell_next = map->water.next;
	cell_next->prev = cell;
	cell->next = cell_next;
	cell->prev = &map->water;
	map->water.next = cell;
	return 0;
}
/*----------------------------------------------------------------------------*/
int Map_ParseFoodStr (struct map *map, const char *message)
{
unsigned int row;
unsigned int col;
unsigned int scanned;
/* struct map_cell cell; */
	scanned = sscanf(message, "%d %d", &row, &col);
	if (scanned < 2)
		return -1;
	cell.type = CT_FOOD;
	cell.owner = 0;
/*	Map_SetCellType (map, row, col, &cell);*/
	return 0;
}
/*----------------------------------------------------------------------------*/
int Map_ParseHillStr (struct map *map, const char *message)
{
unsigned int row;
unsigned int col;
unsigned int owner;
unsigned int scanned;
/* struct map_cell cell; */
	scanned = sscanf(message, "%d %d %d", &row, &col, &owner);
	if (scanned < 3)
		return -1;
	cell.type = CT_HILL;
	cell.owner = (unsigned short)owner;
/*	Map_SetCellType (map, row, col, &cell);*/
	return 0;
}
/*----------------------------------------------------------------------------*/
int Map_ParseAntLiveStr (struct map *map, const char *message)
{
unsigned int row;
unsigned int col;
unsigned int owner;
unsigned int scanned;
struct map_cell cell;
struct ant *ant_node;
	scanned = sscanf(message, "%d %d %d", &row, &col, &owner);
	if (scanned < 3)
		return -1;
	cell.type = CT_LIVE_ANT;
	cell.owner = (unsigned short)owner;
/*	Map_SetCellType (map, row, col, &cell);*/
	/* adding to ants list */
	ant_node = Ants_SearchByPos (&map->ants, row, col);
	if (ant_node == NULL)
		Ants_AddNewAnt (&map->ants, row, col);
	return 0;
}
/*----------------------------------------------------------------------------*/
int Map_ParseAntDeadStr (struct map *map, const char *message)
{
unsigned int row;
unsigned int col;
unsigned int owner;
unsigned int scanned;
struct map_cell cell;
struct ant *ant_node;
	scanned = sscanf(message, "%d %d %d", &row, &col, &owner);
	if (scanned < 3)
		return -1;
	cell.type = CT_DEAD_ANT;
	cell.owner = (unsigned short)owner;
/*	Map_SetCellType (map, row, col, &cell);*/
	/* removing ant from list */
	ant_node = Ants_SearchByPos (&map->ants, row, col);
	if (ant_node != NULL)
		Ants_RemoveDeadAnt (ant_node);
	return 0;
}
/*----------------------------------------------------------------------------*/
/* PUBLIC FUNCTIONS                                                           */
/*----------------------------------------------------------------------------*/
void Map_Init (struct map *map, const struct game_info *info)
/* TODO: game_info is redundant here */
{
	Ants_Init (&map->ants);
	MapCell_Init (&map->water);
	MapCell_Init (&map->food);
	MapCell_Init (&map->hill);
	MapCell_Init (&map->enemies);
}
/*----------------------------------------------------------------------------*/
void Map_Destroy (struct map *map )
{
	Ants_Destroy (&map->ants);
}
/*----------------------------------------------------------------------------*/
void Map_ParseMapStr (struct map *map, const char *message)
{
const char *message_body;
int ret_code;
	ret_code = 0;
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
	if (0 != ret_code) {
		Logger_ERROR ("Can't understand map string");
	}
}

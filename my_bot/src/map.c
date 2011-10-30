#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "map.h"
#include "parse.h"
#include "logger.h"
/*----------------------------------------------------------------------------*/
/* DEFINES                                                                    */
/*----------------------------------------------------------------------------*/
#define LETTER_WATER    'w'
#define LETTER_FOOD     'f'
#define LETTER_HILL     'h'
#define LETTER_ANT_LIVE 'a'
#define LETTER_ANT_DEAD 'd'
/*----------------------------------------------------------------------------*/
/* PRIVATE FUNCTIONS                                                          */
/*----------------------------------------------------------------------------*/
void Map_SetCellType (
	struct map *map,
	unsigned int row,
	unsigned int col,
	struct map_cell *type
) {
struct map_cell *cell;
	assert (row < map->rows);
	assert (col < map->cols);
	cell = &map->data[row * map->cols + col];
	cell->type  = type->type;
	cell->owner = type->owner;
}
/*----------------------------------------------------------------------------*/
int Map_ParseWaterStr (struct map *map, const char *message)
{
unsigned int row;
unsigned int col;
unsigned int scanned;
struct map_cell cell;
	scanned = sscanf(message, "%d %d", &row, &col);
	if (scanned < 2)
		return -1;
	cell.type = CT_WATER;
	cell.owner = 0;
	Map_SetCellType (map, row, col, &cell);
	return 0;
}
/*----------------------------------------------------------------------------*/
int Map_ParseFoodStr (struct map *map, const char *message)
{
unsigned int row;
unsigned int col;
unsigned int scanned;
struct map_cell cell;
	scanned = sscanf(message, "%d %d", &row, &col);
	if (scanned < 2)
		return -1;
	cell.type = CT_FOOD;
	cell.owner = 0;
	Map_SetCellType (map, row, col, &cell);
	return 0;
}
/*----------------------------------------------------------------------------*/
int Map_ParseHillStr (struct map *map, const char *message)
{
unsigned int row;
unsigned int col;
unsigned int owner;
unsigned int scanned;
struct map_cell cell;
	scanned = sscanf(message, "%d %d %d", &row, &col, &owner);
	if (scanned < 3)
		return -1;
	cell.type = CT_HILL;
	cell.owner = (unsigned short)owner;
	Map_SetCellType (map, row, col, &cell);
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
	scanned = sscanf(message, "%d %d %d", &row, &col, &owner);
	if (scanned < 3)
		return -1;
	cell.type = CT_LIVE_ANT;
	cell.owner = (unsigned short)owner;
	Map_SetCellType (map, row, col, &cell);
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
	scanned = sscanf(message, "%d %d %d", &row, &col, &owner);
	if (scanned < 3)
		return -1;
	cell.type = CT_DEAD_ANT;
	cell.owner = (unsigned short)owner;
	Map_SetCellType (map, row, col, &cell);
	return 0;
}
/*----------------------------------------------------------------------------*/
/* PUBLIC FUNCTIONS                                                           */
/*----------------------------------------------------------------------------*/
void Map_Init (struct map *map, const struct game_info *info)
{
size_t i;
	map->rows = info->rows;
	map->cols = info->cols;
	map->data_length = map->rows * map->cols;
	map->data = (struct map_cell *)malloc(map->data_length * sizeof (struct map_cell));
	for (i = 0; i < map->data_length; i++) {
		map->data->type = CT_UNKNOWN;
		map->data->owner = 0;
	}
}
/*----------------------------------------------------------------------------*/
void Map_Destroy (struct map *map )
{
	free (map->data);
}
/*----------------------------------------------------------------------------*/
int Map_ParseMapStr (struct map *map, const char *message)
{
const char *message_body;

	message_body = &message[2];
	switch (message[0]) {
	case LETTER_WATER:
		return Map_ParseWaterStr (map, message_body);
	case LETTER_FOOD:
		return Map_ParseFoodStr (map, message_body);
	case LETTER_HILL:
		return Map_ParseHillStr (map, message_body);
	case LETTER_ANT_LIVE:
		return Map_ParseAntLiveStr (map, message_body);
	case LETTER_ANT_DEAD:
		return Map_ParseAntDeadStr (map, message_body);
	default:
		Logger_ERROR ("Can't recognise map string type");
	}
	return -1;
}

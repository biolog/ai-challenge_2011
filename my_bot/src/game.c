#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logger.h"
#include "game.h"
/*----------------------------------------------------------------------------*/
/* DEFINES                                                                    */
/*----------------------------------------------------------------------------*/
#define BUFFER_LENGTH 100
/*----------------------------------------------------------------------------*/
/* PUBLIC FUNCTIONS                                                           */
/*----------------------------------------------------------------------------*/
void Game_ParseGameInfoStr (
	struct game_info *info, 
	const char *input_line
) {
char *key_buffer;
char *val_buffer;
int   parsed;
size_t input_len;
	/* split key-value pair */
	input_len = strlen(input_line);
	key_buffer = (char *)malloc (input_len);
	val_buffer = (char *)malloc (input_len);
	parsed = sscanf (input_line, "%s %s", key_buffer, val_buffer);
	if (parsed < 2) {
		Logger_WARNING ("Unrecognize game param str");
		goto out;
	}

	if (0 == strcmp (key_buffer, PARAM_LOADTIME)) {
		info->loadtime = atoi (val_buffer);
		goto out;
	}
	if (0 == strcmp (key_buffer, PARAM_TURNTIME)) {
		info->turntime = atoi (val_buffer);
		goto out;
	}
	if (0 == strcmp (key_buffer, PARAM_ROWS)) {
		info->rows = atoi (val_buffer);
		goto out;
	}
	if (0 == strcmp (key_buffer, PARAM_COLS)) {
		info->cols = atoi (val_buffer);
		goto out;
	}
	if (0 == strcmp (key_buffer, PARAM_TURNS)) {
		info->turns = atoi (val_buffer);
		goto out;
	}
	if (0 == strcmp (key_buffer, PARAM_VIEWRADIUS2)) {
		info->viewradius2 = atoi (val_buffer);
		goto out;
	}
	if (0 == strcmp (key_buffer, PARAM_ATTACKRADIUS2)) {
		info->attackradius2 = atoi (val_buffer);
		goto out;
	}
	if (0 == strcmp (key_buffer, PARAM_SPAWNRADIUS2)) {
		info->spawnradius2 = atoi (val_buffer);
		goto out;
	}
	if (0 == strcmp (key_buffer, PARAM_PLAYERSEED)) {
		info->player_seed = atol (val_buffer);
		srand (info->player_seed);
		goto out;
	}
out:
	free (key_buffer);
	free (val_buffer);
}
/*----------------------------------------------------------------------------*/
int Game_ParseGameFinalizeStr (
	struct game_info *game_info, 
	const char *input_line
) {
	return 0;
}
/*----------------------------------------------------------------------------*/
int Game_ParseTurnStr (
	struct game_info *game_info, 
	const char *input_line
) {
	return 0;
}


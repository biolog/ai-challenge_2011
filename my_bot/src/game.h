#ifndef __GAME__
#define __GAME__
/*----------------------------------------------------------------------------*/
/* DEFINES                                                                    */
/*----------------------------------------------------------------------------*/
#define PARAM_LOADTIME      "loadtime"
#define PARAM_TURNTIME      "turntime"
#define PARAM_ROWS          "rows"
#define PARAM_COLS          "cols"
#define PARAM_TURNS         "turns"
#define PARAM_VIEWRADIUS2   "viewradius2"
#define PARAM_ATTACKRADIUS2 "attackradius2"
#define PARAM_SPAWNRADIUS2  "spawnradius2"
#define PARAM_PLAYERSEED    "player_seed"
/* Letter codes of map strings */
#define LETTER_WATER    'w'
#define LETTER_FOOD     'f'
#define LETTER_HILL     'h'
#define LETTER_ANT_LIVE 'a'
#define LETTER_ANT_DEAD 'd'

/*----------------------------------------------------------------------------*/
/* TYPES                                                                      */
/*----------------------------------------------------------------------------*/
struct game_info {
	/* time given for bot to start up after it is given "ready" (see below) */
	signed int loadtime; /* in milliseconds */
	/* time given to the bot each turn */
	signed int turntime; /* in milliseconds */
	/* number of rows in the map */
	signed int rows;
	/* number of columns in the map */
	signed int cols;
	/* maximum number of turns in the game */
	signed int turns;
	/* view radius squared */
	signed int viewradius2;
	/* battle radius squared */
	signed int attackradius2;
	/* food gathering radius squared */
	signed int spawnradius2;
	/* seed for random number generator, useful for reproducing games */
	signed long player_seed;
};

/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
void Game_ParseGameInfoStr (
	struct game_info *game_info, 
	const char *input_line
);
int Game_ParseGameFinalizeStr (
	struct game_info *game_info, 
	const char *input_line
);
int Game_ParseTurnStr (
	struct game_info *game_info, 
	const char *input_line
);
#endif


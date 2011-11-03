#include <stdio.h>
#include <string.h>
#include "game.h"
#include "logger.h"
#include "map.h"
#include "ai.h"
/*----------------------------------------------------------------------------*/
/* DEFINES                                                                    */
/*----------------------------------------------------------------------------*/
/* common */
#define IO_BUFFER_LENGTH 100
#define LOGGER_FILENAME  "/tmp/gamelog.log"
/* state transitions */
#define WORD_TURN0 "turn 0"
#define WORD_READY "ready"
#define WORD_END   "end"
#define WORD_GO    "go"
/*----------------------------------------------------------------------------*/
/* TYPES */
/*----------------------------------------------------------------------------*/
enum engine_state {
	ESTATE_RESET,
	ESTATE_INIT,
	ESTATE_RUN_TURN,
	ESTATE_RUN_MAP,
	ESTATE_FINALIZE1,
	ESTATE_FINALIZE2
};
/*----------------------------------------------------------------------------*/
void SendEndTurn (void)
{
	puts ("go\n");
	fflush (stdout);
}
/*----------------------------------------------------------------------------*/
void MoveFunc (
        unsigned int pos_x, unsigned int pos_y,
        enum ants_move_directions direction
) {
char way_letter;
        switch (direction) {
        case ANT_NORTH:
                way_letter = 'N';
                break;
        case ANT_SOUTH:
                way_letter = 'S';
                break;
        case ANT_EAST:
                way_letter = 'E';
                break;
        case ANT_WEST:
                way_letter = 'W';
                break;
        }
        printf ("o %d %d %c\n", pos_x, pos_y, way_letter);
	fflush (stdout);
}
/*----------------------------------------------------------------------------*/
/* MAIN                                                                       */
/*----------------------------------------------------------------------------*/
int main (int argc, char *argv[])
{
char             input_line[IO_BUFFER_LENGTH];
struct game_info game_info;
struct map       map;
enum engine_state state = ESTATE_RESET;
enum engine_state state_next = state;

	/* initialization */
	Logger_Init (LOGGER_FILENAME);
	Logger_INFO ("me: Hi");

	/* main cycle */
	for (;;) {
		state = state_next;
		/* get next line from input */
		gets (input_line);
		Logger_INFO (input_line);
		/* detect if we must go to another state */
		if (state == ESTATE_RESET && 
                    0 == strcmp (input_line, WORD_TURN0)) {
			state_next = ESTATE_INIT;
			continue;
		}
		if (state == ESTATE_INIT &&
                    0 == strcmp (input_line, WORD_READY)) {
			/* we are loaded all initializing information */
			/* lets intialize internal structures         */
			state_next = ESTATE_RUN_TURN;
			Map_Init (&map, &game_info);
			SendEndTurn ();
			continue;
		}
		if (state == ESTATE_RUN_TURN &&
                    0 == strcmp (input_line, WORD_END)) {
			state_next = ESTATE_FINALIZE1;
			continue;
		}
		if (state == ESTATE_RUN_MAP && 
		    0 == strcmp (input_line, WORD_GO)) {
			Logger_INFO ("--- my turn");
			/*TODO: here is my go logic*/
                        AI_DoNextTurn ();
			state_next = ESTATE_RUN_TURN;
			SendEndTurn();
			continue;
		}
		/* state functions */
		switch (state) {
		case ESTATE_RESET:
			Logger_INFO ("ESTATE_RESET");
			break;
		case ESTATE_INIT:
			Logger_INFO ("ESTATE_INIT");
			Game_ParseGameInfoStr (&game_info, input_line);
			break;
		case ESTATE_RUN_TURN:
			Logger_INFO ("ESTATE_RUN_TURN");
			Game_ParseTurnStr (&game_info, input_line);
			state_next = ESTATE_RUN_MAP;
			break;
		case ESTATE_RUN_MAP:
			Logger_INFO ("ESTATE_RUN_MAP");
			Map_ParseMapStr (&map, input_line);
			SendEndTurn ();
			break;
		case ESTATE_FINALIZE1:
			Logger_INFO ("ESTATE_FINALIZE1");
			Game_ParseGameFinalizeStr (&game_info, input_line);
			state_next = ESTATE_FINALIZE2;
			break;
		case ESTATE_FINALIZE2:
			Logger_INFO ("ESTATE_FINALIZE2");
			Game_ParseGameFinalizeStr (&game_info, input_line);
			goto out;
		default:
			Logger_ERROR ("state is wrong");
			goto out;
		}
	}
out:
	/* destroy */
	Logger_Destroy ();
	Map_Destroy (&map);
	return 0;
}

//	/* initialization */
//	Logger_Init (LOGGER_FILENAME);
//	Logger_INFO ("Hi");
//	/* loading game info */
//	Game_GetInitInfo (&game_info);
//	Game_InitRandom (&game_info);
//	Map_Init (&map, &game_info);
//	IO_SendEndTurn ();
//	/* main cycle */
//	Logger_INFO ("start main cycle");
//	for (;;) {
//		if (0 == strcmp (input_line, "end"))
//			break;
//		Map_Update (&map);
//		gets (input_line);
//		Logger_INFO (input_line);
//		IO_SendEndTurn ();
//	}
//	/* loading finalizing information */
//	/* TODO */
//	/* destroy */
//	Logger_Destroy ();
//	Map_Destroy (&map);
//	return 0;


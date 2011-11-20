#ifndef __ANTS__
#define __ANTS__
/*----------------------------------------------------------------------------*/
/* ENUMS                                                                      */
/*----------------------------------------------------------------------------*/
enum ants_move_directions {
        ANT_NORTH,
        ANT_SOUTH,
        ANT_EAST,
        ANT_WEST,
        ANT_TOTAL_DIRECTIONS
};
enum ants_tasks_codes {
	ANT_NO_TASK,
	ANT_CMD_GATHER_FOOD,
	ANT_CMD_EXPLORE,
	ANT_CMD_ATTACK_ANT,
	ANT_CMD_ATTACK_HILL,
	ANT_CMD_TOTAL
};
/*----------------------------------------------------------------------------*/
/* TYPES                                                                      */
/*----------------------------------------------------------------------------*/
struct ant_task {
        unsigned int row;
        unsigned int col;
	enum ants_tasks_codes task_code;
};
struct ant {
	/* ant characteristics */
        unsigned int row;
        unsigned int col;
	struct ant_task task;
};
/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
#endif

#ifndef __ANTS__
#define __ANTS__
/*----------------------------------------------------------------------------*/
/* ENUMS                                                                      */
/*----------------------------------------------------------------------------*/
enum ants_move_directions {
        ANT_NORTH,
        ANT_SOUTH,
        ANT_EAST,
        ANT_WEST
};
/*----------------------------------------------------------------------------*/
/* TYPES                                                                      */
/*----------------------------------------------------------------------------*/
struct ant {
        unsigned int pos_x;
        unsigned int pos_y;
};
struct ant_node {
        struct ant  ant;
        struct ant *next_ant;
};

#endif

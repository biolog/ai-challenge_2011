#ifndef __ANTS__
#define __ANTS__
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

#ifndef __AI_ENGINE__
#define __AI_ENGINE__
/*----------------------------------------------------------------------------*/
/* TYPES                                                                      */
/*----------------------------------------------------------------------------*/
struct ants_ai {

        void (*MoveFunc) (
                unsigned int pos_x,
                unsigned int pos_y,
                unsigned int dx,
                unsigned int dy
        );
};

#endif

#ifndef ASSIGN_H
#define ASSIGN_H

#include <pinocchio.h>

/* ========================================================================= */

struct Assign_t {
    Optr          variable;
    Optr          expression;
};

/* ========================================================================= */
extern Assign new_Assign(Optr variable, Optr expression);
extern void post_init_Assign();
/* ========================================================================= */

extern void do_assign();

#endif // ASSIGN_H

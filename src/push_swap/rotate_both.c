#include "push_swap.h"

int	rotate_both(t_stacks *s)
{
    int	res1;
    int	res2;

    res1 = rotate(&(s->a));
    res2 = rotate(&(s->b));
    return ((res1 == OK || res2 == OK) ? OK : KO);
}

#include "push_swap.h"

/*
** This one returns KO if both swaps failed (returned KO).
**
** Otherwise it returns OK.
*/

int	swap_both(t_stacks *s)
{
    int	res;

    res = 0;
    res = swap(s->a);
    res = swap(s->b);
    return ((res == OK) ? OK : KO);
}

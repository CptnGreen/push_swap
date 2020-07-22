#include "push_swap.h"

/*
** This one returns KO if nothing happened,
** i.e. both swaps failed (returned KO).
**
** Otherwise it returns OK.
*/

int	swap_both(t_stacks *s)
{
    int	res1;
    int	res2;

    res1 = swap(s->a);
    res2 = swap(s->b);
    return ((res1 == OK || res2 == OK) ? OK : KO);
}

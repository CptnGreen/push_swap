#include "push_swap.h"

int	reverse_rotate_both(t_stacks *s)
{
    int	res1;
    int	res2;

    res1 = reverse_rotate(&(s->a));
    res2 = reverse_rotate(&(s->b));
    return ((res1 == OK || res2 == OK) ? OK : KO);
}

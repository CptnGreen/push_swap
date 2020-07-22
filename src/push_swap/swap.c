#include "push_swap.h"

int	swap(t_stack *c)
{
    int	a;

    if (c && c->next)
    {
        a = c->num;
        c->num = c->next->num;
        c->next->num = a;
        return (OK);
    }
    return (KO);
}

#include "push_swap.h"

int	rotate(t_stack **s)
{
    t_stack	*old_top;
    t_stack	*cur;

    if ((*s) && (*s)->next)
    {
        old_top = (*s);
        (*s) = (*s)->next;
        cur = (*s);
        while (cur->next)
            cur = cur->next;
        cur->next = old_top;
        old_top->next = NULL;
        return (OK);
    }
    return (KO);
}

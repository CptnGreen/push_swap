#include "push_swap.h"

/*
** Before:
** 1 2 3 4
**
** After:
** 4 1 2 3
*/

int	reverse_rotate(t_stack **s)
{
    t_stack	*old_top;
    t_stack	*cur;

    if ((*s) && (*s)->next)
    {
        old_top = (*s);
        cur = (*s);
        while (cur->next->next)
            cur = cur->next;
        (*s) = cur->next;
        (*s)->next = old_top;
        cur->next = NULL;
        return (OK);
    }
    return (KO);
}

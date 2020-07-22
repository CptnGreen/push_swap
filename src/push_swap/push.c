#include "push_swap.h"

/*
** This function takes number from the top of the stack "from" and
** puts it on top of the stack "to".
** 
** It returns "KO" if "from" is empty (is NULL) and "OK" otherwise.
*/

int	push(t_stack **to, t_stack **from)
{
    t_stack	*prev;

    if (!(*from))
        return (KO);
    if (*to)
        (*to) = (*to)->next;
    if (((*to) = (t_stack *)ft_memalloc(sizeof(t_stack))))
    {
        (*to)->num = (*from)->num;
        (*to)->next = NULL;
        prev = (*from);
        (*from) = (*from)->next;
        free(prev);
        prev = NULL;
    }
    return (OK);
}

#include "push_swap.h"

t_stacks	*init_stacks(int *t_a, size_t size_a, int *t_b, size_t size_b)
{
    t_stacks	*s;

    if ((s = (t_stacks *)ft_memalloc(sizeof(t_stacks))))
    {
        s->a = init_stack(t_a, size_a);
        s->b = init_stack(t_b, size_b);
        return (s);
    }
    return (NULL);
}

#include "push_swap.h"

int	print_stack(t_stack *s)
{
    if (!s)
    {
        ft_printf("Nothing to print\n");
        return (KO);
    }
    while (s)
    {
        ft_printf("%d\n", s->num);
        s = s->next;
    }
	return (OK);
}

#include "push_swap.h"

#define SUCCESS 0
#define FAILURE 1

int	main(void)
{
    int		t[4] = {1, 2, 3, -5};
    t_stack	*s;

    s = init_stack(t, 4);
    print_stack(s);
    return (0);
}

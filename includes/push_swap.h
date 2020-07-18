#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libftprintf.h"

/*
**  Data structures:
*/

typedef struct		s_stacks{
    struct s_stack	*a;
    struct s_stack	*b;
}					t_stacks;

typedef struct		s_stack{
    int			num;
    struct s_stack	*next;
}					t_stack;

/*
** Given operations:
*/

int	swap(t_stack *c);
int	swap_both(t_stacks *stacks);
int	push(t_stack *c);
int	rotate(t_stack *c);
int	rotate_both(t_stacks *stacks);
int	reverse_rotate(t_stack *c);
int	reverse_rotate_both(t_stacks *stacks);

/*
** Other functions:
*/

/* int	init_stacks(t_stacks *stacks); */

#endif

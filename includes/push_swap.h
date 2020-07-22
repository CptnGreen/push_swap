#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libftprintf.h"

/*
**  Useful defines:
*/

# define OK 1
# define KO 0

/*
**  Data structures:
*/

typedef struct		s_stacks{
	struct s_stack	*a;
	struct s_stack	*b;
}					t_stacks;

typedef struct		s_stack{
	int				num;
	struct s_stack	*next;
}					t_stack;

/*
** Given operations:
*/

int			swap(t_stack *c);
int			swap_both(t_stacks *stacks);
int			push(t_stack **to, t_stack **from);
int			rotate(t_stack **c);
int			rotate_both(t_stacks *stacks);
int			reverse_rotate(t_stack **c);
int			reverse_rotate_both(t_stacks *stacks);

/*
** Other functions:
*/

int			print_stack(t_stack *s);
t_stack		*init_stack(int *tab, size_t size);
t_stacks	*init_stacks(int *t_a, size_t size_a, int *t_b, size_t size_b);

#endif

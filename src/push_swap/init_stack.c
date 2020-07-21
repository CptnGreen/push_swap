/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 06:26:57 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/26 12:21:52 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** This function checks that given number:
** - is not negative
** - has no duplicates in the array
*/

int		is_valid(size_t num, int *tab, size_t size)
{
	size_t		i;

	if (tab[num] < 0)
		return (KO);
	i = 0;
	while (i != num && i < size)
	{
		if (tab[i] == tab[num])
			return (KO);
		i += 1;
	}
	return (OK);
}

/*
** This function receives integer array and its size.
** If either of these if zero, it returns NULL.
** Else it initializes corresponding stack
** (with array's first number at the top of it).
*/

t_stack	*init_stack(int *tab, size_t size)
{
	size_t		i;
	t_stack		*top;
	t_stack		*prev;
	t_stack		*cur;

	if (!tab || size <= 0)
		return (NULL);
	i = 0;
	top = NULL;
	prev = NULL;
	while (i < size)
	{
		if (!is_valid(i, tab, size))
			return (NULL);
		cur = (t_stack *)ft_memalloc(sizeof(t_stack));
		if (!top)
			top = cur;
		if (prev)
			prev->next = cur;
		prev = cur;
		cur->num = tab[i++];
		cur = cur->next;
	}
	cur = NULL;
	return (top);
}

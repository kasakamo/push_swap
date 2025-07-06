/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:42:06 by kasakamo          #+#    #+#             */
/*   Updated: 2025/07/06 22:06:55 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_top(t_stack *a, int idx)
{
	if (idx <= a->size / 2)
		while (idx-- > 0)
			op_ra(a);
	else
		while (idx++ < a->size)
			op_rra(a);
}

int	find_min_index(t_stack *a)
{
	int		min;
	t_node	*cur;
	int		idx;
	int		i;

	min = a->top->value;
	cur = a->top;
	idx = 0;
	i = 0;
	while (cur)
	{
		if (cur->value < min)
		{
			min = cur->value;
			idx = i;
		}
		cur = cur->next;
		i++;
	}
	return (idx);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int		idx;

	while ((*a)->size > 3)
	{
		idx = find_min_index(*a);
		rotate_top(a, idx);
		op_pb(a, b);
	}
	sort_three(*a);
	while (*b && (*b)->size)
		op_pa(a, b);
}

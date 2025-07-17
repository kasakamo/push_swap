/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:07:28 by kasakamo          #+#    #+#             */
/*   Updated: 2025/07/11 18:38:19 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack *a)
{
	int		max;
	t_node	*cur;

	max = a->top->value;
	cur = a->top;
	while (cur)
	{
		if (max < cur->value)
			max = cur->value;
		cur = cur->next;
	}
	return (max);
}

void	sort_three(t_stack *a)
{
	int	max;

	max = get_max(a);
	if (max == a->top->value)
		op_ra(a, 1);
	else if (max == a->top->next->value)
		op_rra(a, 1);
	if (a->top->value > a->top->next->value)
		op_sa(a);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	if (!a || !*a || (*a)->size <= 1)
		return ;
	if ((*a)->size == 2)
		op_sa(*a);
	else if ((*a)->size == 3)
		sort_three(*a);
	else if ((*a)->size <= 5)
		sort_five(a, b);
	else
		sort_large(a, b);
}

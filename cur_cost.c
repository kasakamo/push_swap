/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:10:00 by kasakamo          #+#    #+#             */
/*   Updated: 2025/07/07 16:10:38 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rot_cost(int size, int index)
{
	if (index <= size / 2)
		return (index);
	else
		return (size - index);
}

int	mid_idx(t_node *cur, int val)
{
	int	idx;

	idx = 1;
	while (cur->next)
	{
		if (cur->value > val && val > cur->next->value)
			return (idx);
		cur = cur->next;
		idx++;
	}
	return (idx);
}

int	over_idx(t_node *cur, int val, int max)
{
	int	idx;

	idx = 1;
	while (cur->value != max)
	{
		cur = cur->next;
		idx++;
	}
	return (idx);
}

int	target_idx(t_stack *s, int val)
{
	t_node	*cur;
	int	max;
	int min;

	if (!s || !s->top)
		return (0);
	min = INT_MAX;
	max = INT_MIN;
	cur = s->top;
	while (cur)
	{
		if (cur->value < min)
			min = cur->value;
		if (cur->value > max)
			max = cur->value;
		cur = cur->next;
	}
	if (val < min || max < val)
		return (over_idx(s->top, val, max));
	else
		return (mid_idx(s->top, val));
	return (0);
}

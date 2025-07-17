/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:03:29 by kasakamo          #+#    #+#             */
/*   Updated: 2025/07/11 19:07:02 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *a)
{
	t_node	*cur;
	int		min;
	int		i;
	int		idx;

	min = INT_MAX;
	i = 0;
	cur = a->top;
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
	if (idx <= a->size / 2)
		while (idx-- > 0)
			op_ra(a, 1);
	else
		while (idx++ < a->size)
			op_rra(a, 1);
}

void	exe_move(t_stack **s1, t_stack **s2, t_node *node, int r)
{
	int	idx;
	int	tgt;

	if (!node)
		return ;
	idx = node_idx(*s1, node);
	tgt = target_idx(*s2, node->value);
	while (idx && tgt && idx <= (*s1)->size / 2 && tgt <= (*s2)->size / 2)
	{
		op_rr(*s1, *s2);
		idx--;
		tgt--;
	}
	while (idx && tgt && idx > (*s1)->size / 2 && tgt > (*s2)->size / 2)
	{
		op_rrr(*s1, *s2);
		idx++;
		tgt--;
	}
	if (r == 0)
		rotate_move(s1, s2, idx, tgt);
	else
		rotate_return(s1, s2, idx, tgt);
}

t_node	*best_move(t_stack *s1, t_stack *s2)
{
	t_node	*best;
	t_node	*cur;
	int		best_cost;
	int		cur_cost;
	int		i;

	cur = s1->top;
	best = cur;
	best_cost = INT_MAX;
	i = 0;
	while (cur)
	{
		cur_cost = rot_cost(s1->size, i) + rot_cost(s2->size, target_idx(s2, cur->value));
		if (cur_cost < best_cost)
		{
			best_cost = cur_cost;
			best = cur;
		}
		cur = cur->next;
		i++;
	}
	return (best);
}

void	sort_large(t_stack **a, t_stack **b)
{
	t_node	*move;

	op_pb(a, b);
	op_pb(a, b);
	while ((*a)->size > 3)
	{
		move = best_move(*a, *b);
		exe_move(a, b, move, 0);
	}
	sort_three(*a);
	while (*b && (*b)->size)
	{
		move = best_move(*b, *a);
		exe_move(a, b, move, 1);
	}
	rotate_a(*a);
}

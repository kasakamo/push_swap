/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:36:02 by kasakamo          #+#    #+#             */
/*   Updated: 2025/07/07 17:13:24 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sb(t_stack *b)
{
	t_node	*first;
	t_node	*second;
	int		tmp;

	if (!b || b->size < 2)
		return ;
	first = b->top;
	second = first->next;
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
	write(1, "sb\n", 3);
}

void	op_rb(t_stack *b, int w)
{
	t_node	*first;
	t_node	*last;

	if (!b || b->size < 2)
		return ;
	first = b->top;
	b->top = first->next;
	first->next = NULL;
	last = b->top;
	while (last->next)
		last = last->next;
	last->next = first;
	if (w)
		write(1, "rb\n", 3);
}

void	op_rrb(t_stack *b, int w)
{
	t_node	*prev;
	t_node	*last;

	if (!b | b->size < 2)
		return ;
	prev = NULL;
	last = b->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = b->top;
	b->top = last;
	if (w)
		write(1, "rrb\n", 4);
}

void	op_pb(t_stack **a, t_stack **b)
{
	t_node	*tmp;

	if (!b || !*b)
		return ;
	if (!a || !*a || !(*a)->top)
		return ;
	tmp = (*a)->top;
	(*a)->top = tmp->next;
	tmp->next = (*b)->top;
	(*b)->top = tmp;
	(*a)->size--;
	(*b)->size++;
	write(1, "pb\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:25:20 by kasakamo          #+#    #+#             */
/*   Updated: 2025/07/07 12:52:39 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_stack *a)
{
	t_node	*f;
	t_node	*s;
	int		tmp;

	if (!a || a->size < 2)
		return ;
	f = (a)->top;
	s = f->next;
	tmp = f->value;
	f->value = s->value;
	s->value = tmp;
	write(1, "sa\n", 3);
}

void	op_ra(t_stack *a)
{
	t_node	*first;
	t_node	*last;

	if (!a || a->size < 2)
		return ;
	first = a->top;
	a->top = first->next;
	first->next = NULL;
	last = a->top;
	while (last->next)
		last = last->next;
	last->next = first;
	write(1, "ra\n", 3);
}

void	op_rra(t_stack *a)
{
	t_node	*prev;
	t_node	*last;

	if (!a || a->size < 2)
		return ;
	prev = NULL;
	last = a->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = a->top;
	a->top = last;
	write(1, "rra\n", 4);
}

void	op_pa(t_stack **a, t_stack **b)
{
	t_node	*tmp;

	if (!a || !*a)
		return ;
	if (!b || !*b || !(*b)->top)
		return ;
	tmp = (*b)->top;
	(*b)->top = tmp->next;
	tmp->next = (*a)->top;
	(*a)->top = tmp;
	(*b)->size--;
	(*a)->size++;
	write(1, "pa\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:07:28 by kasakamo          #+#    #+#             */
/*   Updated: 2025/07/03 20:50:57 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_stack *a)
{
	t_node *f;
	t_node *s;
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
	t_node	*f;
	t_node	*l;

	if (!a || a->size < 2)
		return ;
	f = a->top;
	a->top = f->next;
	f->next = NULL;
	l = a->top;
	while (l->next)
		l = l->next;
	l->next = f;
	write(1, "ra\n", 3);
}

void	op_rra(t_stack *a)
{
	t_node *p;
	t_node *l;

	if (!a || a->size < 2)
		return ;
	l = a->top;
	while (l->next)
	{
		p = l;
		l = l->next;
	}
	p->next = NULL;
	l->next = a->top;
	a->top = l;
	write(1, "rra\n", 4);
}

// void	op_sb(t_stack *b)
// {
// 	t_node *fst;
// 	t_node *snd;
// 	int		tmp;

// 	if (!b)
// 		return ;
// 	fst = (b)->top;
// 	snd = fst->next;
// 	tmp = fst->value;
// 	fst->value = snd->value;
// 	snd->value = tmp;
// 	write(1, "sb\n", 3);
// }

// void	op_ss(t_stack *a, t_stack *b)
// {
// 	op_sa(a);
// 	op_sb(b);
// 	write(1, "ss\n", 3);
// }

void	sort_three(t_stack *a)
{
	int	fst;
	int	snd;
	int	trd;

	fst = a->top->value;
	snd = a->top->next->value;
	trd = a->top->next->next->value;
	if (fst > snd && fst < trd) // 213
		op_sa(a);
	else if (fst > snd && snd > trd) // 321
	{
		op_sa(a);
		op_rra(a);
	}
	else if (fst > trd && snd < trd) // 312
		op_ra(a);
	else if (fst < trd && snd > trd) // 132
	{
		op_sa(a);
		op_ra(a);
	}
	else if (fst > trd && fst < snd) // 231
		op_rra(a);
}

void	rotate_top(t_stack **a, int idx)
{
	if (idx <= (*a)->size / 2)
		while (idx-- > 0)
			op_ra(*a);
	else
		while (idx++ < (*a)->size)
			op_rra(*a);
}

int	find_min_index(t_stack **a)
{
	int		min;
	t_node	*cur;
	int		idx;
	int		i;

	min = (*a)->top->value;
	cur = (*a)->top;
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

void	sort_stack(t_stack **a, t_stack **b)
{
	if (!a || !*a || (*a)->size <= 1)
		return ;
	if ((*a)->size == 2)
		op_sa(*a);
	else if ((*a)->size == 3)
		sort_three(*a);
	else if ((*a)->size == 5)
		sort_five(a, b);
}

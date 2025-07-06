/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:07:28 by kasakamo          #+#    #+#             */
/*   Updated: 2025/07/06 20:45:37 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int	fst;
	int	snd;
	int	trd;

	fst = a->top->value;
	snd = a->top->next->value;
	trd = a->top->next->next->value;
	if (fst > snd && fst < trd)
		op_sa(a);
	else if (fst > snd && snd > trd)
	{
		op_sa(a);
		op_rra(a);
	}
	else if (fst > trd && snd < trd)
		op_ra(a);
	else if (fst < trd && snd > trd)
	{
		op_sa(a);
		op_ra(a);
	}
	else if (fst > trd && fst < snd)
		op_rra(a);
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
	{
		comp_vals(*a);
		sort_large(a, b);
	}
}

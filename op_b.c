/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:36:02 by kasakamo          #+#    #+#             */
/*   Updated: 2025/07/06 19:04:52 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

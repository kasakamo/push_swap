/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:35:55 by kasakamo          #+#    #+#             */
/*   Updated: 2025/07/07 17:19:52 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	node_idx(t_stack *s, t_node *n)
{
	t_node	*cur;
	int	idx;

	cur = s->top;
	idx = 0;
	while (cur && cur != n)
	{
		cur = cur->next;
		idx++;
	}
	return (idx);
}

void	rotate_return(t_stack **a, t_stack **b, int idx_b, int tgt_a)
{
	while (idx_b-- > 0)
		op_rb(*b, 1);
	while (idx_b++ < 0)
		op_rrb(*b, 1);
	while (tgt_a-- > 0)
		op_ra(*a, 1);
	while (tgt_a++ < 0)
		op_rra(*a, 1);
	op_pa(a, b);
}

void	rotate_move(t_stack **a, t_stack **b, int idx_a, int tgt_b)
{
	while (idx_a-- > 0)
		op_ra(*a, 1);
	while (idx_a++ < 0)
		op_rra(*a, 1);
	while (tgt_b-- > 0)
		op_rb(*b, 1);
	while (tgt_b++ < 0)
		op_rrb(*b, 1);
	op_pb(a, b);
}

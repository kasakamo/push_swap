/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:04:33 by kasakamo          #+#    #+#             */
/*   Updated: 2025/07/07 17:12:33 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rr(t_stack *a, t_stack *b)
{
	op_ra(a, 0);
	op_rb(b, 0);
	write(1, "rr\n", 3);
}

void	op_rrr(t_stack *a, t_stack *b)
{
	op_rra(a, 0);
	op_rrb(b, 0);
	write(1, "rrr\n", 4);
}

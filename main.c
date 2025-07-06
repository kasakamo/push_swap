/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:51:24 by kasakamo          #+#    #+#             */
/*   Updated: 2025/07/06 19:15:25 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	p_err(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*st_a;
	t_stack	*st_b;

	if (ac < 2)
		return (0);
	if (!is_valid(ac, av))
		return (p_err());
	st_a = in_stack(ac, av);
	if (!st_a)
		return (p_err());
	st_b = malloc(sizeof(t_stack));
	if (!st_b)
	{
		free_stack(st_a);
		return (p_err());
	}
	st_b->top = NULL;
	st_b->size = 0;
	if (!is_sorted(st_a))
		sort_stack(&st_a, &st_b);
	free_stack(st_a);
	free_stack(st_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:55:32 by kasakamo          #+#    #+#             */
/*   Updated: 2025/06/25 17:59:19 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(t_stack *stack, t_node *node)
{
	t_node	*cur;

	if (!stack->top)
		stack->top = node;
	else
	{
		cur = stack->top;
		while (cur->next)
			cur = cur->next;
		cur->next = node;
	}
	stack->size++;
}

t_node	*new_node(int value)
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->value = value;
	n->next = NULL;
	return (n);
}

t_stack	*in_stack(int ac, char **av)
{
	t_stack	*stack;
	t_node	*node;
	int		i;
	long	num;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	i = 0;
	while (++i < ac)
	{
		num = ft_atol(av[i]);
		node = new_node(num);
		if (!node)
			return (free_stack(stack), NULL);
		push_back(stack, node);
	}
	return (stack);
}

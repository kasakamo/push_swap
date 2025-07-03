/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:03:18 by kasakamo          #+#    #+#             */
/*   Updated: 2025/06/28 19:35:31 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

#include <stdio.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

int		is_valid(int ac, char **av);
int		is_signed_digit(char *s);
long	ft_atol(char *s);
int		is_new_digit(int *tab, int num, int sz);
t_stack	*in_stack(int ac, char **av);
t_node	*new_node(int value);
void	push_back(t_stack *stack, t_node *node);
void 	free_stack(t_stack *stack);
int		is_sorted(t_stack *stack);
void	sort_stack(t_stack **a, t_stack **b);
void	sort_three(t_stack *a);

void	op_sa(t_stack *a);
void	op_ra(t_stack *a);
void	op_rra(t_stack *a);

int		p_err(void);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:03:18 by kasakamo          #+#    #+#             */
/*   Updated: 2025/07/11 18:39:04 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

# ifndef BIT_SIZE
#  define BIT_SIZE 31
# endif

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

typedef struct s_move
{
	int	a_idx;
	int	b_idx;
	int	total_ops;
}	t_move;

int		p_err(void);

int		is_valid(int ac, char **av);
int		is_signed_digit(char *s);
long	ft_atol(char *s);
int		is_new_digit(int *tab, int num, int sz);

t_stack	*in_stack(int ac, char **av);
t_node	*new_node(int value);
void	push_back(t_stack *stack, t_node *node);

void	free_stack(t_stack *stack);

int		is_sorted(t_stack *stack);

void	sort_stack(t_stack **a, t_stack **b);
void	sort_three(t_stack *a);
int		get_max(t_stack *a);

void	sort_five(t_stack **a, t_stack **b);
int		find_min_index(t_stack *a);
void	rotate_top(t_stack *a, int idx);

void	sort_large(t_stack **a, t_stack **b);
t_node	*best_move(t_stack *s1, t_stack *s2);
void	exe_move(t_stack **s1, t_stack **s2, t_node *node, int r);
void	rotate_a(t_stack *a);

int		target_idx(t_stack *s, int val);
int		over_idx(t_node *cur, int val, int max);
int		mid_idx(t_node *cur, int val);
int		rot_cost(int size, int index);

void	rotate_move(t_stack **a, t_stack **b, int idx_a, int tgt_b);
void	rotate_return(t_stack **a, t_stack **b, int idx_b, int tgt_a);
int		node_idx(t_stack *s, t_node *n);

void	op_sa(t_stack *a);
void	op_ra(t_stack *a, int w);
void	op_rra(t_stack *a, int w);
void	op_pa(t_stack **a, t_stack **b);

void	op_sb(t_stack *b);
void	op_rb(t_stack *b, int w);
void	op_rrb(t_stack *b, int w);
void	op_pb(t_stack **a, t_stack **b);

void	op_rr(t_stack *a, t_stack *b);
void	op_rrr(t_stack *a, t_stack *b);

#endif

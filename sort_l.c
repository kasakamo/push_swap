#include "push_swap.h"

int	node_idx(t_stack *a, t_node *n)
{
	t_node	*cur;
	int	idx;

	cur = a->top;
	idx = 0;
	while (cur && cur != n)
	{
		cur = cur->next;
		idx++;
	}
	return (idx);
}

void	exe_move(t_stack **a, t_stack **b, t_node node)
{
	int	idx_a;
	int	tgt_b;

	if (!node)
		return ;
	idx_a = node_idx(*a, node);
	tgt_b = target_idx(*b, node->value)
	while (idx_a && tgt_b && idx_a <= (*a)->size / 2 && tgt_b <= (*b)->size / 2)
	{
		op_rr(*a, *b);
		idx_a--;
		tgt_b--;
	}
	while (idx_a && tgt_b && idx_a > (*a)->size / 2 && tgt_b > (*b)->size / 2)
	{
		op_rrr(*a. *b);
		idx_a++;
		tgt_b++;
	}
	while (idx_a-- > 0)
		op_ra(*a);
	while (idx_a++ < 0)
		op_rra(*a);
	while (tgt_b-- > 0)
		op_rb(*b);
	while (tgt_b++ < 0)
		op_rrb(*b);
	op_pb(a, b);
}

int	rot_cost(int size, int index)
{
	if (index <= size / 2)
		return (index);
	else
		return (size - index);
}

int	mid_idx(t_node *cur, int val)
{
	int	idx;

	idx = 1;
	while (cur->next)
	{
		if (cur->value > val && val > cur->next->value)
			return (idx);
		cur = cur->next;
		idx++;
	}
	return (idx);
}

int	over_idx(t_node *cur, int val, int max)
{
	int	idx;

	idx = 1;
	while (cur->value != max)
	{
		cur = cur->next;
		idx++;
	}
	return (idx);
}

int	target_idx(t_stack *b, int val)
{
	t_node	*cur;
	int	max;
	int min;

	if (!b || !b->top)
		return (0);
	min = INT_MAX;
	max = INT_MIN;
	cur = b->top;
	while (cur)
	{
		if (cur->value < min)
			min = cur->value;
		if (cur->value > max)
			max = cur->value;
		cur = cur->next;
	}
	if (val < min || max < val)
		return (over_idx(b->top, val, max));
	else
		return (mid_idx(b->top, val));
	return (0);
}

t_node	*best_move(t_stack *a, t_stack *b)
{
	t_node	*best;
	t_node	*cur;
	int		best_cost;
	int		cur_cost;
	int		i;

	best = NULL;
	cur = a->top;
	best_cost = INT_MAX;
	i = 0;
	while (cur)
	{
		cur_cost = rot_cost(a->size, i) + rot_cost(b->size, target_idx(b, cur->value));
		if (cur_cost < best_cost)
		{
			best_cost = cur_cost;
			best = cur;
		}
		cur = cur->next;
		i++;
	}
	return (best);
}

void	sort_large(t_stack **a, t_stack **b)
{
	t_node	*move;

	while ((*a)->size > 3)
	{
		move = best_move(*a, *b);
		exe_move(a, b, move);
	}
	sort_three(*a);
	while (*b && (*b)->size)
		op_pa(a, b);
}

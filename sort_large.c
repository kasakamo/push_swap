/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:42:58 by kasakamo          #+#    #+#             */
/*   Updated: 2025/07/06 17:48:18 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_large(t_stack **a, t_stack **b)
{
	int	size;
	int	i;
	int	j;
	int	val;

	size = (*a)->size;
	i = 0;
	while (i < BIT_SIZE)
	{
		j = 0;
		while (j < size)
		{
			val = (*a)->top->value;
			if (((val >> i) & 1) == 0)
				op_pb(a, b);
			else
				op_ra(*a);
			j++;
		}
		while (*b && (*b)->size > 0)
			op_pa(a, b);
		i++;
	}
}

int	bin_search(int *arr, int size, int val)
{
	int	l;
	int	h;
	int	m;

	l = 0;
	h = size - 1;
	while (l <= h)
	{
		m = (l + h) / 2;
		if (arr[m] == val)
			return (m);
		else if (arr[m] < val)
			l = m + 1;
		else
			h = m - 1;
	}
	return (0);
}

void	sort_arr(int *arr, int size)
{
	int	key;
	int	i;
	int	j;

	i = 0;
	while (++i < size)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void	comp_vals(t_stack *a)
{
	int		size;
	int		*arr;
	t_node	*cur;
	int		i;
	int		j;

	size = a->size;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return ;
	cur = a->top;
	i = 0;
	while (cur)
	{
		arr[i++] = cur->value;
		cur = cur->next;
	}
	sort_arr(arr, size);
	cur = a->top;
	while (cur)
	{
		cur->value = bin_search(arr, size, cur->value);
		cur = cur->next;
	}
	free(arr);
}

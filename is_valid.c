/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:53:26 by kasakamo          #+#    #+#             */
/*   Updated: 2025/06/25 19:03:57 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_new_digit(int *tab, int num, int sz)
{
	int	i;

	i = 0;
	while (i < sz)
	{
		if (tab[i] == num)
		return (0);
		i++;
	}
	return (1);
}

long	ft_atol(char *s)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == '-')
			sign = -1;
		res = res * 10 + s[i] - '0';
		i++;
	}
	return (res * sign);
}

int	is_signed_digit(char *s)
{
	int	i;

	if (!s || !*s)
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || '9' < s[i])
			return (0);
		++i;
	}
	return (1);
}

int	is_valid(int ac, char **av)
{
	int		*tab;
	int		i;
	long	num;

	tab = (int *)malloc(sizeof(int) * (ac - 1));
	if (!tab)
		return (0);
	i = 0;
	while (++i < ac)
	{
		if (!is_signed_digit(av[i]))
			return (free(tab), 0);
		num = ft_atol(av[i]);
		if (num < INT_MIN || INT_MAX < num)
			return (free(tab), 0);
		if (!is_new_digit(tab, num, i - 1))
			return (free(tab), 0);
		tab[i - 1] = num;
	}
	return (free(tab), 1);
}

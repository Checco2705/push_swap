/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffebbrar <ffebbrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:47:15 by ffebbrar          #+#    #+#             */
/*   Updated: 2025/05/09 10:47:15 by ffebbrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_sorter.h"

int	is_valid_integer(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(int *values, int total)
{
	int	i;
	int	j;

	i = 0;
	while (i < total)
	{
		j = i + 1;
		while (j < total)
		{
			if (values[i] == values[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_atoi_safe(const char *str, int *result)
{
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	return (ft_atoi_safe_continue(str, i, sign, result));
}

int	ft_atoi_safe_continue(const char *str, int i, int sign, int *result)
{
	long	num;

	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		if ((sign == 1 && num > INT_MAX)
			|| (sign == -1 && num * sign < INT_MIN))
			return (0);
		i++;
	}
	*result = num * sign;
	return (1);
}

int	is_sorted(t_elem *list)
{
	while (list && list->forward)
	{
		if (list->val > list->forward->val)
			return (0);
		list = list->forward;
	}
	return (1);
}

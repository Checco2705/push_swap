/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffebbrar <ffebbrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:48:18 by ffebbrar          #+#    #+#             */
/*   Updated: 2025/05/09 10:48:18 by ffebbrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_sorter.h"

void	normalize_list(t_elem **stack_x)
{
	int	*array;
	int	len;

	len = ft_list_size(*stack_x);
	if (len <= 0)
		return ;
	array = list_to_array(*stack_x, len);
	if (!array)
		return ;
	sort_array(array, len);
	apply_normalization(*stack_x, array, len);
	free(array);
}

int	find_max(t_elem *list)
{
	int	highest;

	if (!list)
		return (0);
	highest = list->val;
	while (list)
	{
		if (list->val > highest)
			highest = list->val;
		list = list->forward;
	}
	return (highest);
}

int	find_min_position(t_elem *stack_x)
{
	int		lowest;
	int		lowest_pos;
	int		pos;
	t_elem	*aux;

	lowest = stack_x->val;
	lowest_pos = 0;
	pos = 0;
	aux = stack_x;
	while (aux)
	{
		if (aux->val < lowest)
		{
			lowest = aux->val;
			lowest_pos = pos;
		}
		aux = aux->forward;
		pos++;
	}
	return (lowest_pos);
}

void	rotate_to_min(t_elem **stack_x, int lowest_pos, int len)
{
	int	i;

	i = 0;
	if (lowest_pos <= len / 2)
	{
		while (i++ < lowest_pos)
			ft_rx(stack_x);
	}
	else
	{
		while (i++ < len - lowest_pos)
			ft_rrx(stack_x);
	}
}

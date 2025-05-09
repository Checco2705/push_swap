/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffebbrar <ffebbrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:42:16 by ffebbrar          #+#    #+#             */
/*   Updated: 2025/05/09 12:54:32 by ffebbrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_sorter.h"

void	sort_array(int *array, int len)
{
	int	swap_tmp;
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (array[i] > array[j])
			{
				swap_tmp = array[i];
				array[i] = array[j];
				array[j] = swap_tmp;
			}
			j++;
		}
		i++;
	}
}

int	*list_to_array(t_elem *list, int len)
{
	int	*array;
	int	i;

	array = malloc(sizeof(int) * len);
	if (!array)
		return (NULL);
	i = 0;
	while (list)
	{
		array[i] = list->val;
		list = list->forward;
		i++;
	}
	return (array);
}

void	apply_normalization(t_elem *list, int *array, int len)
{
	int	norm_idx;

	while (list)
	{
		norm_idx = 0;
		while (norm_idx < len && array[norm_idx] != list->val)
			norm_idx++;
		list->val = norm_idx;
		list = list->forward;
	}
}

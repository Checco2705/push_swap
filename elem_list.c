/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffebbrar <ffebbrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:46:57 by ffebbrar          #+#    #+#             */
/*   Updated: 2025/05/09 12:55:54 by ffebbrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_sorter.h"

void	ft_node_back(t_elem **list, t_elem *new_elem)
{
	t_elem	*swap_tmp;

	if (!list || !new_elem)
		return ;
	if (!*list)
	{
		*list = new_elem;
		return ;
	}
	swap_tmp = *list;
	while (swap_tmp->forward)
		swap_tmp = swap_tmp->forward;
	swap_tmp->forward = new_elem;
}

void	ft_node_front(t_elem **list, t_elem *new_elem)
{
	if (!list || !new_elem)
		return ;
	new_elem->forward = *list;
	*list = new_elem;
}

int	ft_list_size(t_elem *list)
{
	int	count;

	count = 0;
	while (list)
	{
		count++;
		list = list->forward;
	}
	return (count);
}

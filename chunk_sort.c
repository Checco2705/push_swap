/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffebbrar <ffebbrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:46:45 by ffebbrar          #+#    #+#             */
/*   Updated: 2025/05/09 13:19:45 by ffebbrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_sorter.h"

void	chunk_sort(t_elem **stack_x, t_elem **stack_y)
{
	int	total;
	int	chunk_count;
	int	chunk_len;

	total = ft_list_size(*stack_x);
	if (total <= 100)
		chunk_count = 5;
	else
		chunk_count = 11;
	chunk_len = total / chunk_count + 1;
	push_chunks(stack_x, stack_y, chunk_len, chunk_count);
	pull_chunks(stack_x, stack_y);
}

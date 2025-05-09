/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffebbrar <ffebbrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:46:45 by ffebbrar          #+#    #+#             */
/*   Updated: 2025/05/09 13:16:40 by ffebbrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_sorter.h"

int	find_position(t_elem *list, int target)
{
	int	pos;

	pos = 0;
	while (list)
	{
		if (list->val == target)
			return (pos);
		pos++;
		list = list->forward;
	}
	return (pos);
}

static void	handle_push_to_b(t_elem **stack_x, t_elem **stack_y,
		int c_chunk, int chunk_len)
{
	ft_px(stack_y, stack_x);
	write(1, "pb\n", 3);
	if ((*stack_y) && ((*stack_y)->val < (c_chunk * chunk_len)
			- (chunk_len / 2)))
	{
		ft_rx(stack_y);
		write(1, "rb\n", 3);
	}
}

void	push_chunks(t_elem **stack_x, t_elem **stack_y, int chunk_len,
		int chunk_count)
{
	int	c_chunk;
	int	list_b;

	c_chunk = 1;
	while (*stack_x)
	{
		if (((*stack_x)->val) < c_chunk * chunk_len)
			handle_push_to_b(stack_x, stack_y, c_chunk, chunk_len);
		else
		{
			ft_rx(stack_x);
			write(1, "ra\n", 3);
		}
		list_b = ft_list_size(*stack_y);
		if (list_b >= c_chunk * chunk_len && c_chunk < chunk_count)
			c_chunk = c_chunk + 1;
	}
}

void	rotate_b(t_elem **stack_y, int count, int use_rrx)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (use_rrx)
		{
			ft_rrx(stack_y);
			write(1, "rrb\n", 4);
		}
		else
		{
			ft_rx(stack_y);
			write(1, "rb\n", 3);
		}
		i = i + 1;
	}
}

void	pull_chunks(t_elem **stack_x, t_elem **stack_y)
{
	int	highest;
	int	idx;
	int	size_b;

	while (*stack_y)
	{
		highest = find_max(*stack_y);
		idx = find_position(*stack_y, highest);
		size_b = ft_list_size(*stack_y);
		if (idx <= size_b / 2)
			rotate_b(stack_y, idx, 0);
		else
			rotate_b(stack_y, size_b - idx, 1);
		ft_px(stack_x, stack_y);
		write(1, "pa\n", 3);
	}
}

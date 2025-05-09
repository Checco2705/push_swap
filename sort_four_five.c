/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffebbrar <ffebbrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:48:09 by ffebbrar          #+#    #+#             */
/*   Updated: 2025/05/09 13:05:34 by ffebbrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_sorter.h"

static void	push_min_to_b(t_elem **stack_x, t_elem **stack_y, int len)
{
	int	pos;

	pos = find_min_position(*stack_x);
	if (pos <= len / 2)
	{
		while (pos--)
		{
			ft_rx(stack_x);
			write(1, "ra\n", 3);
		}
	}
	else
	{
		while (pos++ < len)
		{
			ft_rrx(stack_x);
			write(1, "rra\n", 4);
		}
	}
	ft_px(stack_y, stack_x);
	write(1, "pb\n", 3);
}

void	sort_four(t_elem **stack_x, t_elem **stack_y)
{
	push_min_to_b(stack_x, stack_y, 4);
	sort_three(stack_x);
	ft_px(stack_x, stack_y);
	write(1, "pa\n", 3);
}

void	sort_five(t_elem **stack_x, t_elem **stack_y)
{
	push_min_to_b(stack_x, stack_y, 5);
	push_min_to_b(stack_x, stack_y, 4);
	sort_three(stack_x);
	if ((*stack_y)->val < (*stack_y)->forward->val)
	{
		ft_sx(stack_y);
		write(1, "sb\n", 3);
	}
	ft_px(stack_x, stack_y);
	write(1, "pa\n", 3);
	ft_px(stack_x, stack_y);
	write(1, "pa\n", 3);
}

void	sort_four_five(t_elem **stack_x, t_elem **stack_y, int len)
{
	if (len == 4)
		sort_four(stack_x, stack_y);
	else if (len == 5)
		sort_five(stack_x, stack_y);
}

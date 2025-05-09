/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffebbrar <ffebbrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:48:09 by ffebbrar          #+#    #+#             */
/*   Updated: 2025/05/09 10:48:09 by ffebbrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_sorter.h"

void	sort_two(t_elem **stack_x)
{
	if ((*stack_x)->val > (*stack_x)->forward->val)
	{
		ft_sx(stack_x);
		write(1, "sa\n", 3);
	}
}

void	sort_three(t_elem **stack_x)
{
	int	alpha;
	int	beta;
	int	gamma;

	alpha = (*stack_x)->val;
	beta = (*stack_x)->forward->val;
	gamma = (*stack_x)->forward->forward->val;
	if (alpha > beta && beta < gamma && alpha < gamma)
		sort_three_case1(stack_x);
	else if (alpha > beta && beta > gamma)
		sort_three_case2(stack_x);
	else if (alpha > beta && alpha > gamma)
		sort_three_case3(stack_x);
	else if (alpha < beta && beta > gamma && alpha < gamma)
		sort_three_case4(stack_x);
	else if (alpha < beta && beta > gamma)
		sort_three_case5(stack_x);
}

void	sort_three_continue(t_elem **stack_x)
{
	int	alpha;
	int	beta;
	int	gamma;

	alpha = (*stack_x)->val;
	beta = (*stack_x)->forward->val;
	gamma = (*stack_x)->forward->forward->val;
	if (alpha < beta && beta > gamma && alpha < gamma)
	{
		ft_sx(stack_x);
		write(1, "sa\n", 3);
		ft_rx(stack_x);
		write(1, "ra\n", 3);
	}
	else if (alpha < beta && beta > gamma)
	{
		ft_rrx(stack_x);
		write(1, "rra\n", 4);
	}
}

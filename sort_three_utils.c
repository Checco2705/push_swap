/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffebbrar <ffebbrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:48:09 by ffebbrar          #+#    #+#             */
/*   Updated: 2025/05/09 13:01:11 by ffebbrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_sorter.h"

void	sort_three_case1(t_elem **stack_x)
{
	ft_sx(stack_x);
	write(1, "sa\n", 3);
}

void	sort_three_case2(t_elem **stack_x)
{
	ft_sx(stack_x);
	write(1, "sa\n", 3);
	ft_rrx(stack_x);
	write(1, "rra\n", 4);
}

void	sort_three_case3(t_elem **stack_x)
{
	ft_rx(stack_x);
	write(1, "ra\n", 3);
}

void	sort_three_case4(t_elem **stack_x)
{
	ft_sx(stack_x);
	write(1, "sa\n", 3);
	ft_rx(stack_x);
	write(1, "ra\n", 3);
}

void	sort_three_case5(t_elem **stack_x)
{
	ft_rrx(stack_x);
	write(1, "rra\n", 4);
}

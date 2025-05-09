/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffebbrar <ffebbrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:48:31 by ffebbrar          #+#    #+#             */
/*   Updated: 2025/05/09 10:48:31 by ffebbrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_sorter.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	r;

	r = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		r = r * 10 + *str - '0';
		str++;
	}
	return (sign * r);
}

void	ft_sx(t_elem **list)
{
	t_elem	*alpha;
	t_elem	*beta;

	if (!list || !*list || !(*list)->forward)
		return ;
	alpha = *list;
	beta = (*list)->forward;
	alpha->forward = beta->forward;
	beta->forward = alpha;
	*list = beta;
}

void	ft_px(t_elem **dest_elem, t_elem **src_elem)
{
	t_elem	*swap_tmp;

	if (!src_elem || !*src_elem)
		return ;
	swap_tmp = *src_elem;
	*src_elem = (*src_elem)->forward;
	swap_tmp->forward = *dest_elem;
	*dest_elem = swap_tmp;
}

void	ft_rx(t_elem **elem)
{
	t_elem	*alpha;
	t_elem	*swap_tmp;

	if (!elem || !*elem || !(*elem)->forward)
		return ;
	alpha = *elem;
	*elem = (*elem)->forward;
	alpha->forward = NULL;
	swap_tmp = *elem;
	while (swap_tmp->forward)
		swap_tmp = swap_tmp->forward;
	swap_tmp->forward = alpha;
}

void	ft_rrx(t_elem **elem)
{
	t_elem	*omega;
	t_elem	*swap_tmp;

	if (!elem || !*elem || !(*elem)->forward)
		return ;
	omega = *elem;
	while (omega->forward)
		omega = omega->forward;
	swap_tmp = *elem;
	while (swap_tmp->forward->forward)
		swap_tmp = swap_tmp->forward;
	omega->forward = elem[0];
	*elem = omega;
	swap_tmp->forward = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffebbrar <ffebbrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:46:19 by ffebbrar          #+#    #+#             */
/*   Updated: 2025/05/09 12:42:35 by ffebbrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_sorter.h"

int	parse_arguments(int argc, char **argv, t_elem **stack_x)
{
	char	**split;
	int		result;

	*stack_x = NULL;
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!split)
			return (0);
		result = process_split_args(split, stack_x);
		free_split(split);
		return (result);
	}
	else
		return (process_direct_args(argc, argv, stack_x));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffebbrar <ffebbrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:46:40 by ffebbrar          #+#    #+#             */
/*   Updated: 2025/05/09 10:46:40 by ffebbrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_sorter.h"

int	process_split_args(char **tokens, t_elem **stack_x)
{
	int	total;
	int	*values;

	total = 0;
	while (tokens[total])
		total++;
	if (total == 0)
		return (0);
	values = (int *)malloc(sizeof(int) * total);
	if (!values)
		return (0);
	if (!validate_and_convert(tokens, values, total))
	{
		free(values);
		return (0);
	}
	if (!create_list_from_numbers(values, total, stack_x))
	{
		free(values);
		return (0);
	}
	free(values);
	return (1);
}

int	validate_and_convert(char **tokens, int *values, int total)
{
	int	i;

	i = 0;
	while (i < total)
	{
		if (!is_valid_integer(tokens[i])
			|| !ft_atoi_safe(tokens[i], &values[i]))
			return (0);
		i++;
	}
	if (check_duplicates(values, total))
		return (0);
	return (1);
}

int	create_list_from_numbers(int *values, int total, t_elem **stack_x)
{
	int		i;
	t_elem	*new_elem;

	i = 0;
	while (i < total)
	{
		new_elem = ft_new_num(values[i]);
		if (!new_elem)
			return (0);
		ft_node_back(stack_x, new_elem);
		i++;
	}
	return (1);
}

int	validate_direct_args(int argc, char **argv, int *numbers)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_integer(argv[i])
			|| !ft_atoi_safe(argv[i], &numbers[i - 1]))
			return (0);
		i++;
	}
	if (check_duplicates(numbers, argc - 1))
		return (0);
	return (1);
}

int	process_direct_args(int argc, char **argv, t_elem **stack_x)
{
	int	*numbers;

	numbers = (int *)malloc(sizeof(int) * (argc - 1));
	if (!numbers)
		return (0);
	if (!validate_direct_args(argc, argv, numbers))
	{
		free(numbers);
		return (0);
	}
	if (!create_list_from_numbers(numbers, argc - 1, stack_x))
	{
		free(numbers);
		return (0);
	}
	free(numbers);
	return (1);
}

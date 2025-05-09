/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sorter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffebbrar <ffebbrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:47:32 by ffebbrar          #+#    #+#             */
/*   Updated: 2025/05/09 10:47:34 by ffebbrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_sorter.h"

int	ft_check_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc)
		{
			if (ft_atoi(argv[j]) == ft_atoi(argv[i]) && j != i)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_elem	**ft_new_nums(int argc, char **argv)
{
	t_elem	**elems;
	int		i;

	elems = malloc(sizeof(t_elem *) * argc);
	i = 0;
	while (i + 1 < argc)
	{
		if (i == 0)
			elems[i] = ft_new_num(ft_atoi(argv[i + 1]));
		else
		{
			elems[i] = ft_new_num(ft_atoi(argv[i + 1]));
			ft_node_back(elems, elems[i]);
		}
		i++;
	}
	return (elems);
}

int	init_and_validate(int argc, char **argv, t_elem **stack_x)
{
	if (!parse_arguments(argc, argv, stack_x))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (ft_list_size(*stack_x) == 1 || is_sorted(*stack_x))
	{
		free_list(*stack_x);
		return (0);
	}
	return (1);
}

void	apply_sorting_algorithm(t_elem **stack_x, t_elem **stack_y, int len)
{
	if (len == 2)
		sort_two(stack_x);
	else if (len == 3)
	{
		sort_three(stack_x);
		sort_three_continue(stack_x);
	}
	else if (len <= 5)
		sort_four_five(stack_x, stack_y, len);
	else
	{
		normalize_list(stack_x);
		chunk_sort(stack_x, stack_y);
	}
}

int	main(int argc, char **argv)
{
	t_elem	*stack_x;
	t_elem	*stack_y;
	int		len;

	stack_y = NULL;
	if (argc < 2)
		return (0);
	if (!init_and_validate(argc, argv, &stack_x))
		return (0);
	len = ft_list_size(stack_x);
	apply_sorting_algorithm(&stack_x, &stack_y, len);
	free_list(stack_x);
	return (0);
}

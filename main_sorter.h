/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sorter.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffebbrar <ffebbrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:47:39 by ffebbrar          #+#    #+#             */
/*   Updated: 2025/05/09 10:47:39 by ffebbrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_SORTER_H
# define MAIN_SORTER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h> 
# include <limits.h>
# include "ft_printf.h"

typedef struct s_elem
{
	int				val;
	struct s_elem	*forward;
}	t_elem;

/* Validazione input */
int		is_valid_integer(char *str);
int		check_duplicates(int *numbers, int count);
int		ft_atoi_safe(const char *str, int *result);
int		ft_atoi_safe_continue(const char *str, int i, int sign, int *result);
int		is_sorted(t_elem *lst);

/* Utility stringhe */
char	**ft_split(char const *s, char c);
char	**ft_split_continue(char const *s, char c,
			char **result, int word_count);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	free_split(char **split);

/* Parsing argomenti */
int		parse_arguments(int argc, char **argv, t_elem **stack_x);
int		validate_and_convert(char **split, int *numbers, int count);
int		create_list_from_numbers(int *numbers, int total, t_elem **stack_x);
int		process_split_args(char **split, t_elem **stack_x);
int		process_direct_args(int argc, char **argv, t_elem **stack_x);
int		validate_direct_args(int argc, char **argv, int *numbers);

/* Funzioni del main */
int		init_and_validate(int argc, char **argv, t_elem **stack_x);
void	apply_sorting_algorithm(t_elem **stack_x, t_elem **stack_y, int len);

/* Algoritmi di ordinamento */
void	sort_two(t_elem **stack_x);
void	sort_three(t_elem **stack_x);
void	sort_three_continue(t_elem **stack_x);
void	sort_four(t_elem **stack_x, t_elem **stack_y);
void	sort_five(t_elem **stack_x, t_elem **stack_y);
void	sort_four_five(t_elem **stack_x, t_elem **stack_y, int len);
void	chunk_sort(t_elem **stack_x, t_elem **stack_y);
void	normalize_list(t_elem **stack_x);

/* Funzioni di supporto per sort_three */
void	sort_three_case1(t_elem **stack_x);
void	sort_three_case2(t_elem **stack_x);
void	sort_three_case3(t_elem **stack_x);
void	sort_three_case4(t_elem **stack_x);
void	sort_three_case5(t_elem **stack_x);

/* Operations */
void	ft_sx(t_elem **nums);
void	ft_px(t_elem **node, t_elem **out);
void	ft_rx(t_elem **node);
void	ft_rrx(t_elem **node);

/* Funzioni di lista */
void	ft_node_back(t_elem **lst, t_elem *new_elem);
void	ft_node_front(t_elem **lst, t_elem *new_elem);
t_elem	*ft_new_num(int val);
int		ft_list_size(t_elem *lst);
void	free_list(t_elem *lst);

/* Utility per algoritmi di ordinamento */
int		find_position(t_elem *lst, int target);
int		find_max(t_elem *lst);
int		find_min_position(t_elem *stack_x);
void	rotate_to_min(t_elem **stack_x, int lowest_pos, int len);
void	push_chunks(t_elem **stack_x, t_elem **stack_y, int c_len,
			int num_chunks);
void	rotate_b(t_elem **stack_y, int total, int use_rrx);
void	pull_chunks(t_elem **stack_x, t_elem **stack_y);

/* Esistenti */
int		ft_atoi(const char *str);
int		ft_check_duplicate(int argc, char **argv);
t_elem	**ft_new_nums(int argc, char **argv);
void	ft_radix_sort(t_elem **stack_x, t_elem **stack_y);

void	sort_array(int *array, int len);
int		*list_to_array(t_elem *list, int len);
void	apply_normalization(t_elem *list, int *array, int len);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:10:18 by marvin            #+#    #+#             */
/*   Updated: 2022/10/19 20:05:32 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_element
{
	int		value;
	int		pos;
	char	empty;
}			t_element;

// File a_distances.c
int		ft_returning_b(t_element *stack_a, t_element *stack_b);
int		ft_dist_a_down(t_element *stack_a);
int		ft_dist_b_up(t_element *stack_a, t_element *stack_b);
int		ft_dist_b_down(t_element *stack_a, t_element *stack_b);

// File find_better_options.c
int		ft_find_better(t_element *stack_a, t_element *stack_b, int *moves);
void	ft_moves_next(t_element *stack_b, t_element *stack_temp,
			int *move, int **better);
void	ft_best_option(int *best, int **better);
void	ft_manage_best_options(t_element *stack_a, t_element *stack_b,
			int *best, int **better, int *moves);

//File find_better-options_aux.c
void	ft_manage_b_up_1(t_element *stack_a, t_element *stack_b, int *moves,
			int *best);
void	ft_manage_b_up_2(t_element *stack_a, t_element *stack_b, int *moves,
			int *best);
void	ft_no_synergies(t_element *stack_a, t_element *stack_b,
			int *best, int *moves);

// File managing_cases.c
int		ft_case_1(t_element *stack_a, t_element *stack_b, int *moves);
int		ft_case_2(t_element *stack_a, t_element *stack_b, int *moves);
int		ft_case_3(t_element *stack_a, t_element *stack_b, int *moves);
int		ft_case_4(t_element *stack_a, t_element *stack_b, int *moves);

// File managing_cases_aux.c
void	ft_case_1_a(t_element *stack_a, t_element *stack_b, int *moves,
			int *min, int *count);
void	ft_case_1_c(t_element *stack_a, t_element *stack_b, int *moves,
			int *count);
void	ft_case_3_b(t_element *stack_a, t_element *stack_b, int *moves);

// File method.c
int		ft_method(t_element *stack_a, t_element *stack_b, int *moves,
			int argc);
int		ft_next_step(t_element *stack_a, t_element *stack_b,
			int *moves);
int		ft_case_selection(t_element *stack_a, t_element *stack_b, int *moves);
int		ft_option_selection(t_element *stack_a, t_element *stack_b, int *moves,
			int *move);

// File push_movements.c
void	ft_push_b(t_element *stack_a, t_element *stack_b, int *moves);
void	ft_push_a(t_element *stack_a, t_element *stack_b, int *moves);

// File push_swap.c
int		ft_read_stack(int argc, char **argv, int *stack);
int		ft_ordering_stack(t_element *stack_a, int argc);
int		*ft_order_init_stack(int *stack, int *ordered, int argc);
void	ft_build_stack_a(int *stack, int *ordered, t_element *stack_a,
			int argc);
int		main(int argc, char **argv);

// File returning_from_b.c
int		ft_returning_from_b(t_element *stack_a, t_element *stack_b, int *moves,
			int argc);

// File reverse_rotate.c
void	ft_reverse_rotate_a(t_element *stack, int *moves, char print);
void	ft_reverse_rotate_b(t_element *stack, int *moves, char print);
void	ft_reverse_rotate_all(t_element *stack_a, t_element *stack_b,
			int *moves);

// File rotate.c
void	ft_rotate_a(t_element *stack_a, int *moves, char print);
void	ft_rotate_b(t_element *stack_b, int *moves, char print);
void	ft_rotate_all(t_element *stack_a, t_element *stack_b, int *moves);

// File split_cases.c

// File swap_movements.c
void	ft_swap_a(t_element *stack, int *moves, char print);
void	ft_swap_b(t_element *stack, int *moves, char print);
void	ft_swap_all(t_element *stack_a, t_element *stack_b, int *moves);

// File three_elements.c
void	ft_case_A(t_element *stack_a, t_element *stack_b, int *moves);
void	ft_case_B(t_element *stack_a, t_element *stack_b, int *moves);
void	ft_case_C(t_element *stack_a, int *moves);
void	ft_three_elements(t_element *stack_a, t_element *stack_b, int *moves,
			int argc);

// File utils.c
int		ft_stack_last_element(t_element *stack);
int		ft_print_error(void);
void	ft_lowest_number(int number_1, int number_2, int number_3,
			int number_4, int *sol);
void	ft_stack_min(t_element *stack, int *min);
void	ft_stack_max(t_element *stack, int *max);

// File utils_2.c
void	ft_stack_reduce(t_element *stack_a, t_element *stack_temp);
void	ft_better_malloc(int *move, int **better);
void	ft_better_free(int **better);
void	ft_init_stack_b(t_element *stack_b, int argc);
int		ft_hits_count(t_element *stack_a);

#endif
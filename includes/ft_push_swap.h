/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:10:18 by marvin            #+#    #+#             */
/*   Updated: 2022/06/28 20:10:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP
# define FT_PUSH_SWAP

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
int     ft_returning_b(t_element *stack_a, t_element *stack_b);
int     ft_dist_a_down(t_element *stack_a);
int     ft_dist_b_up(t_element *stack_a, t_element *stack_b);
int     ft_dist_b_down(t_element *stack_a, t_element *stack_b);

// File b_distances.c
int     ft_dist_b_to_a_up(t_element *stack_a, t_element *stack_b);
int     ft_dist_b_to_a_down(t_element *stack_a, t_element *stack_b);

// File managing_cases.c
int 	ft_case_1(t_element *stack_a, t_element *stack_b, int *moves);
int 	ft_case_2(t_element *stack_a, t_element *stack_b, int *moves);
int 	ft_case_3(t_element *stack_a, t_element *stack_b, int *moves);
int 	ft_case_4(t_element *stack_a, t_element *stack_b, int *moves);

// File method.c
void    ft_returning_from_b(t_element *stack_a, t_element *stack_b,
		int *moves);
int    ft_case_selection(t_element *stack_a, t_element *stack_b, int *moves);
int    ft_next_step(t_element *stack_a, t_element *stack_b,
		int *moves);
void    ft_method(t_element *stack_a, t_element *stack_b, int *moves,
		int argc);

// File push_movements.c
void    ft_push_b(t_element *stack_a, t_element *stack_b, int *moves);
void    ft_push_a(t_element *stack_a, t_element *stack_b, int *moves);

// File push_swap.c
int 	ft_read_stack(int argc, char **argv, int *stack);
int 	*ft_order_init_stack(int *stack, int *ordered, int argc);
void    ft_build_stack_a(int *stack, int *ordered, t_element *stack_a, int argc);
int     main(int argc, char **argv);

// File reverse_rotate.c
void    ft_reverse_rotate_a(t_element *stack, int *moves, char print);
void    ft_reverse_rotate_b(t_element *stack, int *moves, char print);
void    ft_reverse_rotate_all(t_element *stack_a, t_element *stack_b,
		int *moves);

// File rotate.c
void    ft_rotate_a(t_element *stack_a, int *moves, char print);
void    ft_rotate_b(t_element *stack_b, int *moves, char print);
void    ft_rotate_all(t_element *stack_a, t_element *stack_b, int *moves);

// File split_cases.c
void    ft_init_stack_b(t_element *stack_b, int argc);
int		ft_ordering_stack(t_element *stack_a, int argc);

// File swap_movements.c
void    ft_swap_a(t_element *stack, int *moves, char print);
void    ft_swap_b(t_element *stack, int *moves, char print);
void    ft_swap_all(t_element *stack_a, t_element *stack_b, int *moves);

// File three_elements.c
void    ft_case_A(t_element *stack_a, t_element *stack_b, int *moves);
void    ft_case_B(t_element *stack_a, t_element *stack_b, int *moves);
void    ft_case_C(t_element *stack_a, int *moves);
void    ft_three_elements(t_element *stack_a, t_element *stack_b, int *moves,
		int argc);

// File utils.c
int     ft_stack_last_element(t_element *stack);
int 	ft_print_error(void);
void	ft_lowest_number(int number_1, int number_2, int number_3,
		int number_4, int *sol);
int     ft_hits_count(t_element *stack_a);
void    ft_stack_min(t_element *stack, int *min);
void    ft_stack_max(t_element *stack, int *max);

#endif
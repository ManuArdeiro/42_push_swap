/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_better_option_aux.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:58:04 by marvin            #+#    #+#             */
/*   Updated: 2022/08/21 17:58:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"
#include "../includes/42_ft_printf/includes/ft_printf.h"
#include "../includes/42_libft/libft.h"

/*  Aux functions to finding better option. */

void    ft_manage_b_up_1(t_element *stack_a, t_element *stack_b, int *moves,
        int *best)
{
    int i;

    i = 0;
    while (i < best[0])
    {
        ft_rotate_all(stack_a, stack_b, moves);
        i++;
    }
    while (i++ < best[1] - 1)
        ft_rotate_b(stack_b, moves, 'Y');
    ft_push_b(stack_a, stack_b, moves);
}

void    ft_manage_b_up_2(t_element *stack_a, t_element *stack_b, int *moves,
        int *best)
{
    int i;

    i = 0;
    while (i < best[1] - 1)
    {
        ft_rotate_all(stack_a, stack_b, moves);
        i++;
    }
    while (i++ < best[0])
        ft_rotate_a(stack_a, moves, 'Y');
    ft_push_b(stack_a, stack_b, moves);
}

void    ft_no_synergies(t_element *stack_a, t_element *stack_b,
        int *best, int *moves)
{
    int i;

    i = 0;
    while (i++ < best[0])
        ft_rotate_a(stack_a, moves, 'Y');
    i = 0;
    while (i++ < best[1] - 1)
        ft_reverse_rotate_b(stack_b, moves, 'Y');
    ft_push_b(stack_a, stack_b, moves);
    return ;
}
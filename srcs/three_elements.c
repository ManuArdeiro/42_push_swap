/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 22:06:29 by marvin            #+#    #+#             */
/*   Updated: 2022/07/06 22:06:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void    ft_case_A(t_element *stack_a, t_element *stack_b, int *moves)
{
    if (stack_a[1].pos == 1)
        return ;
    if (stack_a[1].pos == 2)
    {
        ft_push_b(stack_a, stack_b, moves);
        ft_swap_a(stack_a, moves, 'Y');
        ft_push_a(stack_a,stack_b, moves);
    }
    return ;  
}

void    ft_case_B(t_element *stack_a, t_element *stack_b, int *moves)
{
    if (stack_a[0].pos == 1)
    {
        ft_push_b(stack_a, stack_b, moves);
        ft_swap_a(stack_a, moves, 'Y');
        ft_push_b(stack_a, stack_b, moves);
        ft_reverse_rotate_a(stack_a, moves, 'Y');
    }
    if (stack_a[0].pos == 2)
        ft_rotate_a(stack_a, moves, 'Y');
    return ;
}

void    ft_case_C(t_element *stack_a, int *moves)
{
    if (stack_a[0].pos == 1)
        ft_reverse_rotate_a(stack_a, moves, 'Y');
    if (stack_a[0].pos == 2)
    {
        ft_swap_a(stack_a, moves, 'Y');
        ft_reverse_rotate_a(stack_a, moves, 'Y');
    }
    return ;
}


void    ft_three_elements(t_element *stack_a, t_element *stack_b, int *moves, int argc)
{
    if (argc == 3)
    {
        if (stack_a[0].pos == 0)
            return ;
        else if (stack_a[0].pos == 1)
            ft_swap_a(stack_a, moves,'Y');
    }
    if (argc == 4)
    {
        if (stack_a[0].pos == 0)
            ft_case_A(stack_a, stack_b, moves);
        else if (stack_a[1].pos == 0)
            ft_case_B(stack_a, stack_b, moves);
        else if (stack_a[2].pos == 0)
            ft_case_C(stack_a, moves);
    }
    return ;
}
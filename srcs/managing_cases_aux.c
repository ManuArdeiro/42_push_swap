/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managing_cases_aux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:03:43 by marvin            #+#    #+#             */
/*   Updated: 2022/08/21 17:03:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"
#include "../includes/42_ft_printf/includes/ft_printf.h"
#include "../includes/42_libft/libft.h"

/*  Aux functions for managing cases functions. */

void    ft_case_1_b(t_element *stack_a, t_element *stack_b, int *moves,
        int *min, int *count)
{
    ft_stack_min(stack_b, min);
    while (stack_b[0].pos > stack_a[ft_stack_last_element(stack_a)].pos &&
        stack_b[0].value > min[0])
    {
        ft_push_a(stack_a, stack_b, moves);
        count++;
        if(stack_b[0].value == min[0])
        {
            ft_push_a(stack_a, stack_b, moves);
            count++;            
            while (*count > 0)
            {
                ft_rotate_a(stack_a, moves, 'Y');
                count--;
            }
            ft_rotate_a(stack_a, moves, 'Y');
            return ;
        }
    }
    return ;
}

void    ft_case_1_c(t_element *stack_a, t_element *stack_b, int *moves,
        int *count)
{
    while (*count > 0)
    {
        ft_rotate_a(stack_a, moves, 'Y');
        while (stack_b[0].pos > stack_a[ft_stack_last_element(stack_a)].pos)
        {
            ft_push_a(stack_a, stack_b, moves);
            count++;
        }
        count--;
    }
    return ;
}

void    ft_case_3_b(t_element *stack_a, t_element *stack_b, int *moves)
{
    if (stack_a[0].pos < stack_b[0].pos)
        while (stack_a[0].pos < stack_b[0].pos)
            ft_rotate_b(stack_b, moves, 'Y');
    else if (stack_a[0].pos > stack_b[0].pos)
    {
        while (stack_a[0].pos > stack_b[0].pos)
            ft_rotate_b(stack_b, moves, 'Y');
        while (stack_a[0].pos < stack_b[0].pos)
            ft_rotate_b(stack_b, moves, 'Y');
    }
}
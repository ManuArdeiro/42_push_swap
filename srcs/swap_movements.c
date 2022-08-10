/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:34:20 by marvin            #+#    #+#             */
/*   Updated: 2022/07/06 20:34:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"
#include "../includes/42_ft_printf/includes/ft_printf.h"
#include "../includes/42_libft/libft.h"

void    ft_swap_a(t_element *stack, int *moves, char print)
{
    int aux_pos;
    int aux_value;
    
    if (stack[0].empty == 'Y' || stack[1].empty == 'Y')
        return ;
    aux_pos = stack[0].pos;
    aux_value = stack[0].value;
    stack[0].pos = stack[1].pos;
    stack[0].value = stack[1].value;
    stack[1].pos = aux_pos;
    stack[1].value = aux_value;
    *moves = *moves + 1;
    if (print == 'Y')
    {
        ft_printf("sa\n");
        *moves = *moves + 1;
    }
}

void    ft_swap_b(t_element *stack, int *moves, char print)
{
    int aux_pos;
    int aux_value;
    
    if (stack[0].empty == 'Y' || stack[1].empty == 'Y')
        return ;
    aux_pos = stack[0].pos;
    aux_value = stack[0].value;
    stack[0].pos = stack[1].pos;
    stack[0].value = stack[1].value;
    stack[1].pos = aux_pos;
    stack[1].value = aux_value;
    *moves = *moves + 1;
    if (print == 'Y')
    {
        ft_printf("sb\n");
        *moves = *moves + 1;
    }
}

void    ft_swap_all(t_element *stack_a, t_element *stack_b, int *moves)
{
    ft_swap_a(stack_a, moves, 'N');
    ft_swap_b(stack_b, moves, 'N');
    ft_printf("ss\n");
    *moves = *moves + 1;
    return ;
}
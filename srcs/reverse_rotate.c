/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:24:46 by marvin            #+#    #+#             */
/*   Updated: 2022/07/06 19:24:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"
#include "../includes/42_ft_printf/includes/ft_printf.h"
#include "../includes/42_libft/libft.h"

void    ft_reverse_rotate_a(t_element *stack, int *moves, char print)
{
    int i;
    int aux_pos;
    int aux_value;

    i = 0;
    if (stack[0].empty == 'Y' || stack[1].empty == 'Y')
        return ;
    i = ft_stack_last_element(stack);
    aux_pos = stack[i].pos;
    aux_value = stack[i].value;
    while (i > 0)
    {
        stack[i].pos = stack[i - 1].pos;
        stack[i].value = stack[i - 1].value;
        i--;
    }
    stack[0].pos = aux_pos;
    stack[0].value = aux_value;
    if (print == 'Y')
    {
        ft_printf("rra\n");
        *moves = *moves + 1;
    }
    return ;
}

void    ft_reverse_rotate_b(t_element *stack, int *moves, char print)
{
    int i;
    int aux_pos;
    int aux_value;

    i = 0;
    if (stack[0].empty == 'Y' || stack[1].empty == 'Y')
        return ;
    i = ft_stack_last_element(stack);
    aux_pos = stack[i].pos;
    aux_value = stack[i].value;
    while (i > 0)
    {
        stack[i].pos = stack[i - 1].pos;
        stack[i].value = stack[i - 1].value;
        i--;
    }
    stack[0].pos = aux_pos;
    stack[0].value = aux_value;
    if (print == 'Y')
    {
        *moves = *moves + 1;
        ft_printf("rrb\n");
    }
    return ;
}

void    ft_reverse_rotate_all(t_element *stack_a, t_element *stack_b, int *moves)
{
    ft_reverse_rotate_a(stack_a, moves, 'N');
    ft_reverse_rotate_b(stack_b, moves, 'N');
    ft_printf("rrr\n");
    *moves = *moves + 1;
    return ;
}
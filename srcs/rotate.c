/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:39:28 by marvin            #+#    #+#             */
/*   Updated: 2022/07/06 15:39:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"
#include "../includes/42_ft_printf/includes/ft_printf.h"
#include "../includes/42_libft/libft.h"

void    ft_rotate_a(t_element *stack, int *moves, char print)
{
    int i;
    int j;
    int aux_pos;
    int aux_value;

    i = 0;
    j = 0;
    if (stack[0].empty == 'Y' || stack[1].empty == 'Y')
        return ;
    aux_pos = stack[0].pos;
    aux_value = stack[0].value;
    while (stack[i].empty == 'N')
        i++;
    while (j < i - 1)
    {
        stack[j].pos = stack[j + 1].pos;
        stack[j].value = stack[j + 1].value;
        j++;
    }
    stack[j].pos = aux_pos;
    stack[j].value = aux_value;
    if (print == 'Y')
    {
        ft_printf("ra\n");
        *moves = *moves + 1;
    }
}

void    ft_rotate_b(t_element *stack, int *moves, char print)
{
    int i;
    int j;
    int aux_pos;
    int aux_value;

    i = 0;
    j = 0;
    if (stack[0].empty == 'Y' || stack[1].empty == 'Y')
        return ;
    aux_pos = stack[0].pos;
    aux_value = stack[0].value;
    i = ft_stack_last_element(stack);
    while (j <= i - 1)
    {
        stack[j].pos = stack[j + 1].pos;
        stack[j].value = stack[j + 1].value;
        j++;
    }
    stack[j].pos = aux_pos;
    stack[j].value = aux_value;
    if (print == 'Y')
    {
        ft_printf("rb\n");
        *moves = *moves + 1;
    }
}

void    ft_rotate_all(t_element *stack_a, t_element *stack_b, int *moves)
{
    ft_rotate_a(stack_a, moves, 'N');
    ft_rotate_b(stack_b, moves, 'N');
    ft_printf("rr\n");
    *moves = *moves + 1;
    return ;
}
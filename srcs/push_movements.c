/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:23:51 by marvin            #+#    #+#             */
/*   Updated: 2022/07/01 11:23:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"
#include "../includes/42_ft_printf/includes/ft_printf.h"
#include "../includes/42_libft/libft.h"

void    ft_push_b(t_element *stack_a, t_element *stack_b, int *moves)
{
    int i;
    
    if (stack_a[0].empty == 'Y')
        return ;
    i = ft_stack_last_element(stack_b);
    while (i >= 0)
    {
        stack_b[i + 1].pos = stack_b[i].pos;
        stack_b[i + 1].value = stack_b[i].value;
        stack_b[i + 1].empty = stack_b[i].empty;
        i--;
    }
    stack_b[0].pos = stack_a[0].pos;
    stack_b[0].value = stack_a[0].value;
    stack_b[0].empty = stack_a[0].empty;
    ft_rotate_a(stack_a, moves, 'N');
    i = ft_stack_last_element(stack_a);
    stack_a[i].pos = -1;
    stack_a[i].value = 0;
    stack_a[i].empty = 'Y';
    *moves = *moves + 1;
    ft_printf("pb\n");
}

void    ft_push_a(t_element *stack_a, t_element *stack_b, int *moves)
{
    int i;
    
    i = 0;
    if (stack_b[0].empty == 'Y')
        return ;
    i = ft_stack_last_element(stack_a);
    while (i >= 0)
    {
        stack_a[i + 1].pos = stack_a[i].pos;
        stack_a[i + 1].value = stack_a[i].value;
        stack_a[i + 1].empty = stack_a[i].empty;
        i--;
    }
    stack_a[0].pos = stack_b[0].pos;
    stack_a[0].value = stack_b[0].value;
    stack_a[0].empty = stack_b[0].empty;
    ft_rotate_b(stack_b, moves, 'N');
    i = ft_stack_last_element(stack_b);
    stack_b[i].pos = -1;
    stack_b[i].value = 0;
    stack_b[i].empty = 'Y';
    *moves = *moves + 1;
    ft_printf("pa\n");
    i = 0;
}
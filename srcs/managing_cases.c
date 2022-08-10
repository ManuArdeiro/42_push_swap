/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managing_cases.c                                  :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:06:17 by marvin            #+#    #+#             */
/*   Updated: 2022/07/07 22:06:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"
#include "../includes/42_ft_printf/includes/ft_printf.h"
#include "../includes/42_libft/libft.h"

int ft_case_1(t_element *stack_a, t_element *stack_b, int *moves)
{
    //ft_printf("Case 1.\n");
    int count;

    count = 0;
    while (stack_b[0].pos < stack_a[ft_stack_last_element(stack_a)].pos)
    {
        ft_reverse_rotate_a(stack_a, moves, 'Y');
        count++;
    }
    ft_push_a(stack_a, stack_b, moves);
    while (stack_b[0].pos > stack_a[ft_stack_last_element(stack_a)].pos)
    {
        ft_push_a(stack_a, stack_b, moves);
        count++;
    }
    while (count > 0)
    {
        ft_rotate_a(stack_a, moves, 'Y');
        while (stack_b[0].pos > stack_a[ft_stack_last_element(stack_a)].pos)
        {
            ft_push_a(stack_a, stack_b, moves);
            count++;
        }
        count--;
    }
    ft_rotate_a(stack_a, moves, 'Y');  
    return (0);
}

int ft_case_2(t_element *stack_a, t_element *stack_b, int *moves)
{
    //ft_printf("Case 2.\n");
    int count;

    count = 0;
    ft_push_b(stack_a, stack_b, moves);
    ft_reverse_rotate_a(stack_a, moves, 'Y');
    while (stack_b[0].pos < stack_a[ft_stack_last_element(stack_a)].pos)
    {
        ft_reverse_rotate_a(stack_a, moves, 'Y');
        count++;
    }
    ft_push_a(stack_a, stack_b, moves);
    ft_rotate_a(stack_a, moves, 'Y');
    while (count-- >= 0)
        ft_rotate_a(stack_a, moves, 'Y');
    return (0);    
}

int ft_case_3(t_element *stack_a, t_element *stack_b, int *moves)
{
    //ft_printf("Case 3.\n");
    int min[2];
    int max[2];

    ft_stack_min(stack_b, min);
    ft_stack_max(stack_b, max);
    if (stack_a[0].value < min[0])
    {
        while (stack_b[0].value > min[0])
            ft_rotate_b(stack_b, moves, 'Y');
        ft_rotate_b(stack_b, moves, 'Y');
    }
    else if (stack_a[0].value > max[0])
        while (stack_b[0].value < max[0])
            ft_rotate_b(stack_b, moves, 'Y');
    else if (stack_a[0].value > min[0] && stack_a[0].value < max[0])
    {
        if (stack_a[0].pos < stack_b[0].pos)
        {
            while (stack_a[0].pos < stack_b[0].pos)
                ft_rotate_b(stack_b, moves, 'Y');
        }
        else if (stack_a[0].pos > stack_b[0].pos)
        {
            while (stack_a[0].pos > stack_b[0].pos)
                ft_rotate_b(stack_b, moves, 'Y');
            while (stack_a[0].pos < stack_b[0].pos)
                ft_rotate_b(stack_b, moves, 'Y');
        }
    }
    ft_push_b(stack_a, stack_b, moves);
    return (0);    
}

int ft_case_4(t_element *stack_a, t_element *stack_b, int *moves)
{
    //ft_printf("Case 4.\n");
    int min[2];
    int max[2];

    ft_stack_min(stack_b, min);
    ft_stack_max(stack_b, max);
    if (stack_a[0].value < min[0])
        while (stack_b[ft_stack_last_element(stack_b)].value > min[0])
            ft_reverse_rotate_b(stack_b, moves, 'Y');
    else if (stack_a[0].value > max[0])
        while (stack_b[0].value < max[0])
            ft_reverse_rotate_b(stack_b, moves, 'Y');
    else if (stack_a[0].value > min[0] && stack_a[0].value < max[0])
    {
        if (stack_a[0].pos < stack_b[0].pos)
            while (stack_a[0].pos < stack_b[0].pos)
                ft_reverse_rotate_b(stack_b, moves, 'Y');
        if (stack_a[0].pos > stack_b[0].pos)
            while (stack_a[0].pos > stack_b[ft_stack_last_element(stack_b)].pos)
                ft_reverse_rotate_b(stack_b, moves, 'Y');
    }
    ft_push_b(stack_a, stack_b, moves); 
    return (0);      
}
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

/*  ft_case_1: returning b elements
    This function pushes the first element from stack b to the properly position
    in stack a via reverse rotating stack a. If it's appropriate it will push 
    the next elements of b as well. */

int     ft_case_1(t_element *stack_a, t_element *stack_b, int *moves)
{
    int count;
    int min[2];

    count = 0;
    ft_stack_min(stack_a, min);
    if (stack_b[0].value < min[0])
    {
        ft_push_a(stack_a, stack_b, moves);
        return (0);
    }
    while (stack_b[0].pos < stack_a[ft_stack_last_element(stack_a)].pos)
    {
        ft_reverse_rotate_a(stack_a, moves, 'Y');
        count++;
    }
    ft_push_a(stack_a, stack_b, moves);
    ft_case_1_b(stack_a, stack_b, moves, min, &count);
    ft_case_1_c(stack_a, stack_b, moves, &count);
    ft_rotate_a(stack_a, moves, 'Y');
    return (0);
}

/*  ft_case_2: moving first a element to the end
    This function takes the first element from stack a and moves it to the bottom
    of stack a in the properly position. */

int     ft_case_2(t_element *stack_a, t_element *stack_b, int *moves)
{
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

/*  ft_case_3: moving first a element to stack b via rotating b
    This function takes the first element from stack a and moves into the
    properly position on stack b via rotating stack b. */

int     ft_case_3(t_element *stack_a, t_element *stack_b, int *moves)
{
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
        ft_case_3_b(stack_a, stack_b, moves);
    ft_push_b(stack_a, stack_b, moves);
    return (0);    
}

/*  ft_case_4: moving first a element to stack b via reverse rotating b
    This function takes the first element from stack a and moves into the
    properly position on stack b via reverse rotating stack b. */

int     ft_case_4(t_element *stack_a, t_element *stack_b, int *moves)
{
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
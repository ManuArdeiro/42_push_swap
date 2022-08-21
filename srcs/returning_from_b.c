/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   returning_from_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 19:44:02 by marvin            #+#    #+#             */
/*   Updated: 2022/08/10 19:44:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"
#include "../includes/42_ft_printf/includes/ft_printf.h"
#include "../includes/42_libft/libft.h"

/*  ft_returning_from_b function:
    1.  It (reverse?) rotates stack b until the biggest element is placed on
        top.
    2.  Then it rotates stack a once to get the biggest element of a to top.
    3.  Then it pushes b elements to a or rotates a according the involved
    values. */

int     ft_returning_from_b(t_element *stack_a, t_element *stack_b, int *moves,
        int argc)
{
    int b_elements;
    int max[2];

    b_elements = ft_stack_last_element(stack_b);
    ft_stack_max(stack_b, max);
    if(max[1] > b_elements / 2)
        while (stack_b[0].value != max[0])
            ft_reverse_rotate_b(stack_b, moves, 'Y');
    else
        while (stack_b[0].value != max[0])
            ft_rotate_b(stack_b, moves, 'Y');
    ft_reverse_rotate_a(stack_a, moves, 'Y');
    while (ft_hits_count(stack_a) < (argc - 2))
    {
        ft_stack_max(stack_a, max);
        if(stack_b[0].pos < stack_a[0].pos && stack_b[0].pos >
            stack_a[ft_stack_last_element(stack_a)].pos)
            ft_push_a(stack_a, stack_b, moves);
        else if(stack_b[0].pos < stack_a[0].pos &&
            stack_a[ft_stack_last_element(stack_a)].value == max[0])
            ft_push_a(stack_a, stack_b, moves);
        else
            ft_reverse_rotate_a(stack_a, moves, 'Y');
    }
    return (0);
}
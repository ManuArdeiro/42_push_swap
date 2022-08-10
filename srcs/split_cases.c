/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:14:38 by marvin            #+#    #+#             */
/*   Updated: 2022/07/01 01:14:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"
#include "../includes/42_ft_printf/includes/ft_printf.h"
#include "../includes/42_libft/libft.h"

/*  ft_ordering_stack function:
    1.  Allocating memory for stack b.
    2.  Creating stack b with empty elements (same number than initial stack numbers).
    3.  Depending on the elements number it calls to ft_three_elements function
        (elements < 4) or ft_method function.
    4.  Deallocating stack b memory and returning 0 to main if no errors.
*/

int    ft_ordering_stack(t_element *stack_a, int argc)
{
    t_element   *stack_b;
    int         moves;
    
    moves = 0;
    stack_b = malloc(sizeof(t_element) * argc);
    if (!stack_b)
        return (ft_print_error());
    ft_init_stack_b(stack_b, argc);
    if (argc > 4)
        ft_method(stack_a, stack_b, &moves, argc);
    else if (argc <= 4)
        ft_three_elements(stack_a, stack_b, &moves, argc);
    free (stack_b);
    return (0);
}

void    ft_init_stack_b(t_element *stack_b, int argc)
{
    int i;

    i = 0;
    while (i < argc - 1)
    {
        stack_b[i].value = 0;
        stack_b[i].pos = -1;
        stack_b[i].empty = 'Y';
        i++;
    }
    return ;
}
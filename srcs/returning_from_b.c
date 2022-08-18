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

int     ft_returning_from_b(t_element *stack_a, t_element *stack_b, int *moves)
{
    int i;
    int b_elements;
    int *max;
    int *move;

    printf("Returning from b.\n");
    i = 0;
    b_elements = ft_stack_last_element(stack_b);
    max = malloc(sizeof(int) * 2);
    move = malloc(sizeof(int) * 2);
    if (!move || !max)
    {
        ft_print_error();
        return ;
    }
    ft_stack_max(stack_a, max);
    while (b_elements >= 0)
    {
        ft_lowest_number(ft_dist_b_to_a_up(stack_a, stack_b),
            ft_dist_b_to_a_down(stack_a, stack_b), -1, -1, move);
        if (move[1] == 1)
        {
            while (stack_b[0].pos > stack_a[0].pos)
                ft_rotate_a(stack_a, moves, 'Y');      
        }
        if (move[1] == 2)
        {
            i = ft_dist_b_to_a_down(stack_a, stack_b) - 1;
            while (i > 0)
            {
                ft_reverse_rotate_a(stack_a, moves, 'Y');
                i--;
            }
        }
        ft_push_a(stack_a, stack_b, moves);
        b_elements = ft_stack_last_element(stack_b);
    }
    free (move);
    return ;
}
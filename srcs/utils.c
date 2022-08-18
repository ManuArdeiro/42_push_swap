/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 01:21:59 by marvin            #+#    #+#             */
/*   Updated: 2022/07/07 01:21:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"
#include "../includes/42_ft_printf/includes/ft_printf.h"
#include "../includes/42_libft/libft.h"

int     ft_stack_last_element(t_element *stack)
{
    int i;

    i = 0;
    while (stack[i].empty == 'N')
        i++;
    return (i - 1);    
}

int     ft_print_error(void)
{
    ft_printf("Error\n");
    return (-1);
}

void    ft_lowest_number(int number_1, int number_2, int number_3, int number_4, int *sol)
{
    int lowest;
    int number;

    if (number_1 > 0)
    {
        lowest = number_1;
        number = 1;
    }
    if (number_2 < lowest && number_2 > 0)
    {
        lowest = number_2;
        number = 2;
    }
    if (number_3 < lowest && number_3 > 0)
    {
        lowest = number_3;
        number = 3;
    }
    if (number_4 < lowest && number_4 > 0)
    {
        lowest = number_4;
        number = 4;
    }
    sol[0] = lowest;
    sol[1] = number;
}

int     ft_hits_count(t_element *stack_a)
{
    int i;
    int a_elements;
    int hits;

    i = 0;
    hits = 0;
    a_elements = ft_stack_last_element(stack_a);
    while (i < a_elements)
    {
        if (stack_a[i].pos < stack_a[i + 1].pos)
            hits++;
        i++;
    }
    return (hits);
}

void    ft_stack_min(t_element *stack, int *min)
{    
    int i;
    int b_elements;
    
    i = 0;
    b_elements = ft_stack_last_element(stack);
    min[0] = INT_MAX;
    min[1] = -1;
    while (i++ <= b_elements)
    {
        if (stack[i - 1].value < min[0])
        {
            min[0] = stack[i - 1].value;
            min[1] = i - 1;
        }
    }
    return ;
}

void    ft_stack_max(t_element *stack, int *max)
{    
    int i;
    int b_elements;
    
    i = 0;
    b_elements = ft_stack_last_element(stack);
    max[0] = INT_MIN;
    max[1] = -1;
    while (i++ <= b_elements)
    {
        if (stack[i - 1].value > max[0])
        {
            max[0] = stack[i - 1].value;
            max[1] = i - 1;
        }
    }
    return ;
}
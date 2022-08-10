/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distances.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 01:06:00 by marvin            #+#    #+#             */
/*   Updated: 2022/07/07 01:06:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int     ft_returning_b(t_element *stack_a, t_element *stack_b)
{
    int distance;
    int last_a;

    last_a = ft_stack_last_element(stack_a);
    distance = 0;
    while (stack_b[0].pos < stack_a[last_a - distance].pos)
        distance = distance + 1;
    return (2 * distance + 2);
}

int     ft_dist_a_down(t_element *stack_a)
{
    int distance;
    int last_a;

    distance = 0;
    last_a = ft_stack_last_element(stack_a);
    while (stack_a[0].pos < stack_a[last_a - distance].pos)
        distance++;
    return (2 * distance + 3);
}

int     ft_dist_b_up(t_element *stack_a, t_element *stack_b)  
{
    int distance;
    int min[2];
    int max[2];

    distance = 0;
    ft_stack_min(stack_b, min);
    ft_stack_max(stack_b, max);
    if (stack_a[0].value < min[0])
        return (min[1] + 2);
    else if (stack_a[0].value > max[0])
        return (max[1] + 1);
    else
    {
        while (distance++ < ft_stack_last_element(stack_b))
            if (stack_a[0].pos < stack_b[distance - 1].pos &&
                stack_a[0].pos > stack_b[distance].pos)
                return (distance + 1);
    }
    return (-1);
}

int     ft_dist_b_down(t_element *stack_a, t_element *stack_b)  
{
    int distance;
    int min[2];
    int max[2];

    distance = 0;
    ft_stack_min(stack_b, min);
    ft_stack_max(stack_b, max);
    if (stack_a[0].value < min[0])
        return (ft_stack_last_element(stack_b) - min[1] + 1);
    else if (stack_a[0].value > max[0])
        return (ft_stack_last_element(stack_b) - max[1] + 2);
    else
    {
        while (distance++ < ft_stack_last_element(stack_b))
            if (stack_a[0].pos < stack_b[distance - 1].pos &&
                stack_a[0].pos > stack_b[distance].pos)
                return (ft_stack_last_element(stack_b) - distance + 1 + 1);
    }
    return (-1);
}
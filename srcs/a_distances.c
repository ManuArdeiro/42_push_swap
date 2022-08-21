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

/*  ft_returning_b calculates the number of movements needed to push the first
    element of b to stack a. */

int     ft_returning_b(t_element *stack_a, t_element *stack_b)
{
    int distance;
    int last_a;
    int min[2];

    last_a = ft_stack_last_element(stack_a);
    distance = 0;
    ft_stack_min(stack_a, min);
    if (stack_b[0].value < min[0])
        return (-1);
    while(stack_b[0].pos < stack_a[last_a - distance].pos && distance <= last_a)
        distance = distance + 1;
    return (2 * distance + 2);
}

/*  ft_dist_a_down calculates the number of movements needed to move the first
    element from stack a to the end of stack a, into the properly position. */

int     ft_dist_a_down(t_element *stack_a)
{
    int distance;
    int last_a;
    int min[2];

    distance = 0;
    last_a = ft_stack_last_element(stack_a);
    ft_stack_min(stack_a, min);
    if (stack_a[0].value == min[0])
        return (-1);
    while(stack_a[0].pos < stack_a[last_a - distance].pos)
        distance++;
    return (2 * distance + 3);
}

/*  ft_dist_b_up calculates the number of movements needed to move the first
    element from stack a to stack b via rotating stack b, into the properly 
    position. */

int     ft_dist_b_up(t_element *stack_a, t_element *stack_b)  
{
    int distance;
    int max_a[2];
    int min_b[2];
    int max_b[2];

    distance = 0;
    ft_stack_max(stack_a, max_a);
    ft_stack_min(stack_b, min_b);
    ft_stack_max(stack_b, max_b);
    if(stack_a[0].value == max_a[0])
        return (-1);
    else if(stack_a[0].value < min_b[0])
        return (min_b[1] + 2);
    else if(stack_a[0].value > max_b[0])
        return (max_b[1] + 1);
    else if(stack_a[0].pos > stack_b[0].pos && stack_a[0].pos < 
        stack_b[ft_stack_last_element(stack_b)].pos)
        return (1);
    else
        while (distance++ < ft_stack_last_element(stack_b))
            if (stack_a[0].pos < stack_b[distance - 1].pos &&
                stack_a[0].pos > stack_b[distance].pos)
                return (distance + 1);
    return (-1);
}

/*  ft_dist_b_down calculates the number of movements needed to move the first
    element from stack a to stack b via reverse rotating stack b, into the
    properly position. */

int     ft_dist_b_down(t_element *stack_a, t_element *stack_b)  
{
    int distance;
    int max_a[2];
    int min_b[2];
    int max_b[2];

    distance = 0;
    ft_stack_max(stack_a, max_a);
    ft_stack_min(stack_b, min_b);
    ft_stack_max(stack_b, max_b);
    if(stack_a[0].value == max_a[0])
        return (-1);
    else if (stack_a[0].value < min_b[0])
        return (ft_stack_last_element(stack_b) - min_b[1] + 1);
    else if (stack_a[0].value > max_b[0])
        return (ft_stack_last_element(stack_b) - max_b[1] + 2);
    else
    {
        while (distance++ < ft_stack_last_element(stack_b))
            if (stack_a[0].pos < stack_b[distance - 1].pos &&
                stack_a[0].pos > stack_b[distance].pos)
                return (ft_stack_last_element(stack_b) - distance + 1 + 1);
    }
    return (-1);
}
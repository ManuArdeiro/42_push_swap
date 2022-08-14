/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 23:54:26 by marvin            #+#    #+#             */
/*   Updated: 2022/08/11 23:54:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"
#include "../includes/42_ft_printf/includes/ft_printf.h"
#include "../includes/42_libft/libft.h"

void    ft_best_option(int *best, int **better)
{
    int i;
    
    i = 0;
    best[0] = 0;
    best[1] = INT_MAX;
    while (i < better[0][1])
    {
        if(better[i][2] == 3 && 
            better[i][1] > i && (i + better[i][1] + 1) < best[1])
        {
            best[0] = i;
            best[1] = better[i][1];
        }
        else if(better[i][2] == 3 &&
            better[i][1] <= i && (2 * i + 1) < best[1])
        {
            best[0] = i;
            best[1] = better[i][1];
        }
        else if(better[i][2] == 4 && (2 * i + better[i][1] + 1) < best[1])
        {
            best[0] = i;
            best[1] = better[i][1];
        }
        i++;
    }
}

void    ft_stack_reduce(t_element *stack_a, t_element *stack_temp)
{
    int i;

    i = 1;
    while (i <= ft_stack_last_element(stack_a))
    {
        stack_temp[i - 1].pos = stack_a[i].pos;
        stack_temp[i - 1].value = stack_a[i].value;
        stack_temp[i - 1].empty = stack_a[i].empty;
        i++;
    }
    stack_temp[i].pos = -1;
    stack_temp[i].value = -1;
    stack_temp[i].empty= 'Y';
    return ;
}

void    ft_better_malloc(int *move, int **better)
{
    int i;

    i = 0;
    better[0] = malloc(sizeof(int) * 3);
    better[0][0] = 0;
    better[0][1] = move[0];
    better[0][2] = move[1];
    while (i++ < better[0][1])
    {
        better[i] = malloc(sizeof(int) * 3);
        if (!better[i])
            ft_print_error();
    }
    return ;
}

void    ft_better_free(int **better)
{
    int i;

    i = 0;
    while (i++ < better[0][1])
        free(better[i]);
    free(better[0]);
    free(better);
    return ;
}
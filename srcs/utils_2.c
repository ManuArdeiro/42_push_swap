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

/*  ft_stack_reduce reduce the stack a deleting the first element and moving
    others up (to stack temp). */

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
    stack_temp[i - 1].pos = -1;
    stack_temp[i - 1].value = -1;
    stack_temp[i - 1].empty= 'Y';
    return ;
}

/*  ft_better_malloc allocates memory for better double pointer and initialize
    the first pointer element. */

void    ft_better_malloc(int *move, int **better)
{
    int i;

    i = 0;
    better[0] = malloc(sizeof(int) * 3);
    better[0][0] = 0;
    better[0][1] = move[0];
    better[0][2] = move[1];
    while (i++ < better[0][1] - 1)
    {
        better[i] = malloc(sizeof(int) * 3);
        if (!better[i])
            ft_print_error();
    }
    return ;
}

/*  ft_better_free frees all memory for better double pointer. */

void    ft_better_free(int **better)
{
    int i;

    i = better[0][1];
    while (i-- > 1)
        free(better[i]);
    free(better);
    return ;
}

/*  ft_init_stack_b creates a empty stack b with the correct number
    of elements. */

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

/*  ft_hits_count returns the number of ordered elements in stack argument. */

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
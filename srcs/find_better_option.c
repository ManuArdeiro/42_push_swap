/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_better_option.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 19:41:32 by marvin            #+#    #+#             */
/*   Updated: 2022/08/10 19:41:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"
#include "../includes/42_ft_printf/includes/ft_printf.h"
#include "../includes/42_libft/libft.h"

/*  ft_find_better analyzes if next elements on stack a can be better options
    than stack a first element. If so, ft_find_better manages it:
    1.  ft_moves_next: calculates the number of movements needed for the second
        element on a, for the third, ...
    2.  ft_best_option: chooses the best option, it means the element which needs
        the fewer quantity of movements.
    3.  ft_manage_best_options: applies all the movements needed to do the
        chosed best option. */

int     ft_find_better(t_element *stack_a, t_element *stack_b, int *moves)
{
    int         i;
    int         best[2];
    int         *move;
    int         **better;
    t_element   *stack_temp;
    
    move = malloc(sizeof(int) * 2);
    ft_lowest_number(ft_returning_b(stack_a, stack_b), ft_dist_a_down(stack_a),
        ft_dist_b_up(stack_a, stack_b), ft_dist_b_down(stack_a, stack_b), move);
    better = malloc(sizeof(int *) * move[0]);
    i = ft_stack_last_element(stack_a);
    stack_temp = malloc(sizeof(t_element) * (i + 1));
    if(!move || !stack_temp || !better)
        return (ft_print_error());
    ft_better_malloc(move, better);
    ft_stack_reduce(stack_a, stack_temp);
    ft_moves_next(stack_b, stack_temp, move, better);
    ft_best_option(best, better);
    ft_manage_best_options(stack_a, stack_b, best, better, moves);
    ft_better_free(better);
    free(stack_temp);
    free(move);
    if(best[0] == 0)
        return (-1);
    return (0);
}

void    ft_moves_next(t_element *stack_b, t_element *stack_temp,
        int *move, int **better)
{
    int i;

    i = 0;
    while (i++ < better[0][1] - 1)
    {
        if(ft_hits_count(stack_temp) == ft_stack_last_element(stack_temp))
        {
            better[i][0] = i;
            better[i][1] = INT16_MAX;
            better[i][2] = -1;
        }
        else
        {
            ft_lowest_number(INT_MAX, INT_MAX , 
                ft_dist_b_up(stack_temp, stack_b),
                ft_dist_b_down(stack_temp, stack_b), move);
            better[i][0] = i;
            better[i][1] = move[0];
            better[i][2] = move[1];
        }
        ft_stack_reduce(stack_temp, stack_temp);
    }
}

void    ft_best_option(int *best, int **better)
{
    int i;
    
    i = 0;
    best[0] = 0;
    best[1] = better[0][1];
    while (i++ < better[0][1] - 1)
    {
        if(better[i][2] == 3 && 
            better[i][1] > i && (better[i][1] + 1) < best[1])
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
    }
}

void    ft_manage_best_options(t_element *stack_a, t_element *stack_b,
        int *best, int **better, int *moves)
{
    int i;

    i = 0;
    if(best[0] == 0)
        return ;
    else if(better[best[0]][2] == 3 && best[1] > best[0])
        ft_manage_b_up_1(stack_a, stack_b, moves, best);
    else if(better[best[0]][2] == 3 && best[0] > best[1])
        ft_manage_b_up_2(stack_a, stack_b, moves, best);
    else if(better[best[0]][2] == 3 && best[0] == best[1])
    {
        ft_rotate_a(stack_a, moves, 'Y');
        while (++i < best[1])
            ft_rotate_all(stack_a, stack_b, moves);
        ft_push_b(stack_a, stack_b, moves);
    }
    else if(better[best[0]][2] == 4)
        ft_no_synergies(stack_a, stack_b, best, moves);
    
    i = 0;
    while (i++ < best[0])
        ft_reverse_rotate_a(stack_a, moves, 'Y');
    return ;
}
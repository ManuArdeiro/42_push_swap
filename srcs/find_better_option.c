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

int     ft_find_better(t_element *stack_a, t_element *stack_b, int *moves)
{
    int         i;
    int         best[2];
    int         *move;
    int         **better;
    t_element   *stack_temp;
    
    //printf("find_better\n");
    move = malloc(sizeof(int) * 2);
    ft_lowest_number(ft_returning_b(stack_a, stack_b), ft_dist_a_down(stack_a),ft_dist_b_up(stack_a, stack_b), ft_dist_b_down(stack_a, stack_b), move);
    better = malloc(sizeof(int *) * move[0]);
    stack_temp = malloc(sizeof(t_element) * (ft_stack_last_element(stack_a) + 1));
    if(!move || !stack_temp || !better)
        return (ft_print_error());
    ft_better_malloc( move, better);
    //printf("better_malloc.\n");
    ft_stack_reduce(stack_a, stack_temp);
    //printf("stack_reduce.\n");
    i = 0;
    //printf("better[0][1] = %d\n", better[0][1]);
    ft_moves_next(stack_b, stack_temp, move, better);
    //printf("moves_next.\n");
    ft_best_option(best, better);
    //printf("best[0] = i = %d    best[1] = moves = %d\n", best[0], best[1]);
    ft_manage_best_options(stack_a, stack_b, best, better, moves);
    //printf("manage_best_options.\n");
    i = 0;
    while (i++ < best[0])
        ft_reverse_rotate_a(stack_a, moves, 'Y');
    ft_better_free(better);
    //printf("better_free.\n");
    free(stack_temp);
    //printf("stack_temp.\n");
    free(move);
    //printf("move.\n");
    if(best[0] == 0)
        return (-1);
    return (0);
}

void    ft_manage_best_options(t_element *stack_a, t_element *stack_b,
        int *best, int **better, int *moves)
{
    int i;

    i = 0;
    //printf("best[0] = %d best[1] = %d\n", best[0], best[1]);
    //printf("better[best[0]][2] = %d\n", better[best[0]][2]);
    if(best[0] == 0)
        return ;
    else if(better[best[0]][2] == 3 && best[1] > best[0])
    {
        while (i++ < best[0])
            ft_rotate_all(stack_a, stack_b, moves);
        while (i++ < best[1])
            ft_rotate_b(stack_b, moves, 'Y');
        ft_push_b(stack_a, stack_b, moves);
    }
    else if(better[best[0]][2] == 3 && best[0] >= best[1])
    {
        while (i++ < best[1])
            ft_rotate_all(stack_a, stack_b, moves);
        while (i++ < best[0])
            ft_rotate_a(stack_a, moves, 'Y');
        ft_push_b(stack_a, stack_b, moves);
    }
    else if(better[best[0]][2] == 4)
        ft_no_synergies(stack_a, stack_b, best, moves);
    return ;
}

void    ft_no_synergies(t_element *stack_a, t_element *stack_b,
        int *best, int *moves)
{
    int i;

    i = 0;
    while (i++ < best[0])
        ft_rotate_a(stack_a, moves, 'Y');
    i = 0;
    while (i++ < best[1] - 1)
        ft_reverse_rotate_b(stack_b, moves, 'Y');
    ft_push_b(stack_a, stack_b, moves);
    return ;
}

void    ft_moves_next(t_element *stack_b, t_element *stack_temp,
        int *move, int **better)
{
    int i;

    i = 0;
    while (i++ < better[0][1] - 1)
    {
        ft_lowest_number(INT_MAX, INT_MAX ,ft_dist_b_up(stack_temp, stack_b), ft_dist_b_down(stack_temp, stack_b), move);
        better[i][0] = i;
        better[i][1] = move[0];
        better[i][2] = move[1];
    //printf("i = %d better[%d][0] = %d better[%d][1] = %d better[%d][2] = %d\n", i, i, better[i][0], i, better[i][1], i, better[i][2]);
        ft_stack_reduce(stack_temp, stack_temp);
    }
    
}
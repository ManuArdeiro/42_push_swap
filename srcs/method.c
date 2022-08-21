/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 22:08:55 by marvin            #+#    #+#             */
/*   Updated: 2022/07/06 22:08:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"
#include "../includes/42_ft_printf/includes/ft_printf.h"
#include "../includes/42_libft/libft.h"

/*  ft_method function:
    hits        ->  number of ordered elements in stack a, meaning the number of
                    elements bigger than previous one and fewer than next one
                    (using ft_hits_count function in utils.c file).
    elements    ->  ft_stack_last_element function in utils.c file returns the last
                    element of the stack passed as argument. Notice that elements
                    number is result + 1 because elements start in 0.
    1.  If all the stack a elements are ordered, ft_returning_from_b function is 
        called to return all the stack b elements.
    2.  If not all the stack a elements are ordered ft_next_step function is called
        to analyze what to do next.
    3.  It will work as long as number of hits is fewer than elements.
*/

int     ft_method(t_element *stack_a, t_element *stack_b, int *moves, int argc)
{
    int max[2];

    while (ft_hits_count(stack_a) < argc - 2)
    {
                                /*int i = 0;
                                while (i < argc - 90)
                                {
                                    ft_printf("Stack A -> i = %d value = %d pos = %d empty = %c      Stack B -> value = %d pos = %d empty = %c\n",
                                    i, stack_a[i].value, stack_a[i].pos, stack_a[i].empty, stack_b[i].value, stack_b[i].pos, stack_b[i].empty);
                                    i++;
                                }
                                ft_printf("...........................................\n");
                                i = argc - 10 - ft_stack_last_element(stack_b);
                                while (i < argc - 1 - ft_stack_last_element(stack_b))
                                {
                                    ft_printf("Stack A -> i = %d value = %d pos = %d empty = %c      Stack B -> value = %d pos = %d empty = %c\n",
                                    i, stack_a[i].value, stack_a[i].pos, stack_a[i].empty, stack_b[i].value, stack_b[i].pos, stack_b[i].empty);
                                    i++;
                                }
                                ft_printf("elementos a: %d hits = %d argc = %d\n", ft_stack_last_element(stack_a), ft_hits_count(stack_a), argc);
                                if (*moves > 700)
                                {
                                    i = 0;
                                while (i < argc - 2)
                                    {
                                        ft_printf("Stack A -> i = %d value = %d pos = %d empty = %c      Stack B -> value = %d pos = %d empty = %c\n",
                                        i, stack_a[i].value, stack_a[i].pos, stack_a[i].empty, stack_b[i].value, stack_b[i].pos, stack_b[i].empty);
                                        i++;
                                    }
                                    return (ft_print_error());
                                }
                                printf("moves = %d\n", *moves);*/
        //printf("ft_hits_count(stack_a) = %d ft_stack_last_element(stack_a) = %d\n", ft_hits_count(stack_a), ft_stack_last_element(stack_a));
        ft_stack_max(stack_a, max);
        if(ft_hits_count(stack_a) == ft_stack_last_element(stack_a))
            return (ft_returning_from_b(stack_a, stack_b, moves, argc));
        else if(ft_hits_count(stack_a) == (ft_stack_last_element(stack_a) - 1) &&
            stack_a[0].value == max[0])
            ft_rotate_a(stack_a, moves, 'Y');
        else if(ft_hits_count(stack_a) ==  (ft_stack_last_element(stack_a) - 1) &&
            stack_a[0].pos > stack_a[1].pos)
            ft_swap_a(stack_a, moves, 'Y');
        else if(ft_next_step(stack_a, stack_b, moves) < 0)
            return (-1);
        if (ft_hits_count(stack_a) == argc - 2)
            return (0);
        else if(ft_hits_count(stack_a) == ft_stack_last_element(stack_a))
            return (ft_returning_from_b(stack_a, stack_b, moves, argc));
    }
    return (0);
}

/*  ft_next_step function:
    1.  If stack a
*/

int ft_next_step(t_element *stack_a, t_element *stack_b, int *moves)
{
    int last_a;
    int last_b;

    last_a = ft_stack_last_element(stack_a);
    last_b = ft_stack_last_element(stack_b);
    if (stack_a[0].pos > stack_a[last_a].pos)
        ft_rotate_a(stack_a, moves, 'Y');
    else if (last_b <= 0)
        ft_push_b(stack_a,stack_b, moves);
    else if (stack_a[0].pos > stack_b[0].pos)
    {
        if (stack_a[0].pos < stack_b[last_b].pos)
            ft_push_b(stack_a, stack_b, moves);
        else
            if (ft_case_selection(stack_a, stack_b, moves) < 0) 
                return (ft_print_error());
    }
    else
        if (ft_case_selection(stack_a, stack_b, moves) < 0) 
            return (ft_print_error());
    return (0);        
}

int    ft_case_selection(t_element *stack_a, t_element *stack_b, int *moves)
{
    int move[2];

    ft_lowest_number(ft_returning_b(stack_a, stack_b), ft_dist_a_down(stack_a),
        ft_dist_b_up(stack_a, stack_b), ft_dist_b_down(stack_a, stack_b), move);
    if(move[0] < 4)
        return (ft_option_selection(stack_a, stack_b, moves, move) < 0);
    else if (move[0] > 3)
    {
        if(ft_find_better(stack_a, stack_b, moves) < 0)
        {
            ft_lowest_number(ft_returning_b(stack_a, stack_b), ft_dist_a_down(stack_a),
                ft_dist_b_up(stack_a, stack_b), ft_dist_b_down(stack_a, stack_b), move);
            return (ft_option_selection(stack_a, stack_b, moves, move));
        }
        return (0);
    }
    return (0);
}

int     ft_option_selection(t_element *stack_a, t_element *stack_b, int *moves, int *move)
{
    switch (move[1])
    {
    case 1:
        return (ft_case_1(stack_a, stack_b, moves));
        break;
    case 2:
        return (ft_case_2(stack_a, stack_b, moves));
        break;
    case 3:
        return (ft_case_3(stack_a, stack_b, moves));
        break;
    case 4:
        return (ft_case_4(stack_a, stack_b, moves));
        break;
    default:
        return (-1);
        break;
    }
    return (0);
}

// FILE returning_from_b.c

int     ft_returning_from_b(t_element *stack_a, t_element *stack_b, int *moves, int argc)
{
    int b_elements;
    int *max;
    int *move;

    b_elements = ft_stack_last_element(stack_b);
    max = malloc(sizeof(int) * 2);
    move = malloc(sizeof(int) * 2);
    if (!move || !max)
        return (ft_print_error());
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
        if(stack_b[0].pos < stack_a[0].pos && stack_b[0].pos > stack_a[ft_stack_last_element(stack_a)].pos)
            ft_push_a(stack_a, stack_b, moves);
        else if(stack_b[0].pos < stack_a[0].pos && stack_a[ft_stack_last_element(stack_a)].value == max[0])
            ft_push_a(stack_a, stack_b, moves);
        else
            ft_reverse_rotate_a(stack_a, moves, 'Y');
    }
    return (0);
}

// FILE find_better option

int     ft_find_better(t_element *stack_a, t_element *stack_b, int *moves)
{
    int         i;
    int         best[2];
    int         *move;
    int         **better;
    t_element   *stack_temp;
    
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
    /*printf("best[0] = %d best[1] = %d\n", best[0], best[1]);
    printf("better[best[0]][2] = %d\n", better[best[0]][2]);
    printf("moves = %d\n", *moves);*/
    if(best[0] == 0)
        return ;
    else if(better[best[0]][2] == 3 && best[1] > best[0])
    {
        while (i < best[0])
        {
            ft_rotate_all(stack_a, stack_b, moves);
            i++;
        }
        while (i++ < best[1] - 1)
            ft_rotate_b(stack_b, moves, 'Y');
        ft_push_b(stack_a, stack_b, moves);
    }
    else if(better[best[0]][2] == 3 && best[0] > best[1])
    {
        while (i < best[1] - 1)
        {
            ft_rotate_all(stack_a, stack_b, moves);
            i++;
        }
        while (i++ < best[0])
            ft_rotate_a(stack_a, moves, 'Y');
        ft_push_b(stack_a, stack_b, moves);
    }
    else if(better[best[0]][2] == 3 && best[0] == best[1])
    {
        ft_rotate_a(stack_a, moves, 'Y');
        while (++i < best[1])
            ft_rotate_all(stack_a, stack_b, moves);
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
        if(ft_hits_count(stack_temp) == ft_stack_last_element(stack_temp))
        {
            better[i][0] = i;
            better[i][1] = INT16_MAX;
            better[i][2] = -1;
        }
        else
        {
            ft_lowest_number(INT_MAX, INT_MAX ,ft_dist_b_up(stack_temp, stack_b), ft_dist_b_down(stack_temp, stack_b), move);
            better[i][0] = i;
            better[i][1] = move[0];
            better[i][2] = move[1];
        }
    //printf("i = %d better[%d][0] = %d better[%d][1] = %d better[%d][2] = %d\n", i, i, better[i][0], i, better[i][1], i, better[i][2]);
        ft_stack_reduce(stack_temp, stack_temp);
    }
    
}

//FILE utils_2.c

void    ft_best_option(t_element *stack_a, t_element *stack_b, int *moves, int *best, int **better)
{
    int i;
    
    //printf("best_option.\n");
    i = 1;
    best[0] = 0;
    best[1] = better[0][1];
    //printf("better[0][1] = %d\n", better[0][1]);
    while (i < better[0][1])
    {
    //printf("i = %d better[i][0] = %d better[i][1] = %d better[i][2] = %d\n", i, better[i][0], better[i][1], better[i][2]);
        if(better[i][2] == 3 && 
            better[i][1] > i && (better[i][1] + 1) < best[1])
        {
            best[0] = i;
            best[1] = better[i][1];
    //printf("1. better[0][1] = %d\n", better[0][1]);
        }
        else if(better[i][2] == 3 &&
            better[i][1] <= i && (2 * i + 1) < best[1])
        {
            best[0] = i;
            best[1] = better[i][1];
    //printf("2. better[0][1] = %d\n", better[0][1]);
        }
        else if(better[i][2] == 4 && (2 * i + better[i][1] + 1) < best[1])
        {
            best[0] = i;
            best[1] = better[i][1];
    //printf("3. better[0][1] = %d\n", better[0][1]);
        }
        i++;
    }
    ft_manage_best_options(stack_a, stack_b, best, better, moves);
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
    //printf("stack_a[%d].pos = %d stack_a[%d].value = %d stack_a[%d].empty = %d\n", i, stack_a[i].pos, i, stack_a[i].value, i, stack_a[i].empty);
    //printf("stack_temp[%d].pos = %d stack_temp[%d].value = %d stack_temp[%d].empty = %d\n", i - 1, stack_temp[i - 1].pos, i, stack_temp[i - 1].value, i, stack_temp[i - 1].empty);
        i++;
    }
    stack_temp[i - 1].pos = -1;
    stack_temp[i - 1].value = -1;
    stack_temp[i - 1].empty= 'Y';
    //printf("stack_temp[%d].pos = %d stack_temp[%d].value = %d stack_temp[%d].empty = %d\n", i - 1, stack_temp[i - 1].pos, i - 1, stack_temp[i - 1].value, i - 1, stack_temp[i - 1].empty);
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
    while (i++ < better[0][1] - 1)
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

    i = better[0][1];
    while (i-- > 1)
        free(better[i]);
    free(better);
    return ;
}
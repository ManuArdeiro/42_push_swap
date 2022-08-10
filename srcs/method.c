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

void    ft_method(t_element *stack_a, t_element *stack_b, int *moves, int argc)
{
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
                                printf("moves = %d\n", *moves);*/
       if (ft_hits_count(stack_a) == ft_stack_last_element(stack_a))
            ft_returning_from_b(stack_a, stack_b, moves); 
                                        /*i = 0;
                                while (i < argc - 1)
                                {
                                    ft_printf("Stack A -> i = %d value = %d pos = %d empty = %c      Stack B -> value = %d pos = %d empty = %c\n",
                                    i, stack_a[i].value, stack_a[i].pos, stack_a[i].empty, stack_b[i].value, stack_b[i].pos, stack_b[i].empty);
                                    i++;
                                }
                                ft_printf("elementos a: %d hits = %d argc = %d\n", ft_stack_last_element(stack_a), ft_hits_count(stack_a), argc);*/
        else if (ft_next_step(stack_a, stack_b, moves) < 0)
            return ;
                                /*i = 0;
                                while (i < argc - 1)
                                {
                                    ft_printf("Stack A -> i = %d value = %d pos = %d empty = %c      Stack B -> value = %d pos = %d empty = %c\n",
                                    i, stack_a[i].value, stack_a[i].pos, stack_a[i].empty, stack_b[i].value, stack_b[i].pos, stack_b[i].empty);
                                    i++;
                                }
                                ft_printf("elementos a: %d hits = %d argc = %d\n", ft_stack_last_element(stack_a), ft_hits_count(stack_a), argc);*/
        if (ft_hits_count(stack_a) == argc - 2)
            return ;
        else if (ft_hits_count(stack_a) == ft_stack_last_element(stack_a))
            ft_returning_from_b(stack_a, stack_b, moves);
    }
    return ;
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
    /*else if (stack_a[0].pos > stack_a[1].pos && ft_stack_last_element(stack_b) != -1)
        ft_swap_a(stack_a, moves, 'Y');*/
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
    int *move;
    int *rotate;
    int i;
    int **better;

    i = 1;
    move = malloc(sizeof(int) * 2);
    if (!move)
        return (ft_print_error());
    ft_lowest_number(ft_returning_b(stack_a, stack_b), ft_dist_a_down(stack_a),
        ft_dist_b_up(stack_a, stack_b), ft_dist_b_down(stack_a, stack_b), move);
    /*printf("ft_returning_b = %d, ft_dist_a_down = %d, ft_dist_b_up = %d, ft_dist_b_down = %d\n",
        ft_returning_b(stack_a, stack_b), ft_dist_a_down(stack_a), ft_dist_b_up(stack_a, stack_b), ft_dist_b_down(stack_a, stack_b));*/
    better = malloc(sizeof(int *) * move[0]);
    if (!better)
        return (ft_print_error());
    better[0] = malloc(sizeof(int) * 2);
    better[0][0] = 0;
    better[0][1] = move[0];
    //printf("Antes. move[0] = %d move[1] = %d\n", better[0][1], move[1]);
    if (better[0][1] > 3)
    {
    //printf("Comienzo. better[0][1] = %d\n", better[0][1]);
        while (i < better[0][1])
        {
            better[i] = malloc(sizeof(int) * 2);
            if (!better[i])
                return (ft_print_error());
            ft_rotate_a(stack_a, moves, 'N');
            ft_lowest_number(ft_returning_b(stack_a, stack_b), ft_dist_a_down(stack_a),
                ft_dist_b_up(stack_a, stack_b), ft_dist_b_down(stack_a, stack_b), move);
            better[i][0] = i;
            better[i][1] = move[0];
            i++;
        }
        i = 1;
        while (i < better[0][1])
        {
            ft_reverse_rotate_a(stack_a, moves, 'N');
            i++;
        }
        //printf("Posición inicial.\n");
        i = 1;
        rotate = malloc(sizeof(int) * 2);
        if (!rotate)
            return (ft_print_error());
        rotate[0] = better[0][1];
        //printf("Inicio búsqueda mejor opción.\n");
        while (i < better[0][1])
        {
            if ((better[i][1] + i) < rotate[0])
            {
                //printf("mejor opción: %d\n", i);
                rotate[0] = better[i][1] + i;
                rotate[1] = better[i][0];
            }
            i++;
        }
        i = 0;
        while (i < rotate[0])
        {
            ft_rotate_a(stack_a, moves, 'Y');
            i++;
        }
        ft_lowest_number(ft_returning_b(stack_a, stack_b), ft_dist_a_down(stack_a),
            ft_dist_b_up(stack_a, stack_b), ft_dist_b_down(stack_a, stack_b), move);
        /*printf("ft_returning_b = %d, ft_dist_a_down = %d, ft_dist_b_up = %d, ft_dist_b_down = %d\n",
            ft_returning_b(stack_a, stack_b), ft_dist_a_down(stack_a), ft_dist_b_up(stack_a, stack_b), ft_dist_b_down(stack_a, stack_b));*/
        while (better[0][1]-- > 1)
            free (better[better[0][1]]);
        free (rotate);
    //printf("Final\n");
    }
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
    /*i = 0;
    while (i < better[0][1])
        free (better[i++]);
    free (move);
    free (better);
    return (ft_print_error());*/
}

void    ft_returning_from_b(t_element *stack_a, t_element *stack_b, int *moves)
{
    int i;
    int b_elements;
    int *move;

    i = 0;
    b_elements = ft_stack_last_element(stack_b);
    move = malloc(sizeof(int) * 2);
    if (!move)
    {
        ft_print_error();
        return ;
    }
    while (b_elements >= 0)
    {
        ft_lowest_number(ft_dist_b_to_a_up(stack_a, stack_b),
            ft_dist_b_to_a_down(stack_a, stack_b), INT_MAX, INT_MAX, move);
        if (move[1] == 1)
        {
            while (stack_b[0].pos > stack_a[0].pos)
                ft_rotate_a(stack_a, moves, 'Y');
            ft_push_a(stack_a, stack_b, moves);        
        }
        if (move[1] == 2)
        {
            i = ft_dist_b_to_a_down(stack_a, stack_b) - 1;
            while (i > 0)
            {
                ft_reverse_rotate_a(stack_a, moves, 'Y');
                i--;
            }
            ft_push_a(stack_a, stack_b, moves);
        }
        b_elements = ft_stack_last_element(stack_b);
    }
    free (move);
}
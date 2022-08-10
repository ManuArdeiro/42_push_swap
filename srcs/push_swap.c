/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:34:16 by marvin            #+#    #+#             */
/*   Updated: 2022/06/28 19:34:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"
#include "../includes/42_ft_printf/includes/ft_printf.h"
#include "../includes/42_libft/libft.h"

/*  Main function:
    1.  Allocating memory
    2.  Reading the initial number series (ft_read_stack function)  and save it to
        stack int pointer.
    3.  Ordering the initial stack (ft_order_init_stack function) to know the final
        position of each number.
    4.  Building stack a with the complete series numbers, their positions and a
        field to know how many "gaps"" there are in stack a (ft_build_stack_a function).
    5.  Finally main function calls to ft_ordering_stack function (split_cases.c file),
        deallocate memory and return 0 if no errors.
*/

int main(int argc, char **argv)
{
    int         *stack;
    int         *ordered;
    t_element   *stack_a;
    int sol;
    
    if (!argc || !argv)
        return (ft_print_error());
    if (argc <= 2)
        return (0);
    stack = malloc(sizeof(int) * argc);
    ordered = malloc(sizeof(int) * argc);
    stack_a = malloc(sizeof(t_element) * argc);
    if (!stack || !ordered || !stack_a)
        return (ft_print_error());
    if (ft_read_stack(argc, argv, stack) == -1)
        return (-1);
    ordered = ft_order_init_stack(stack, ordered, argc);
    ft_build_stack_a(stack, ordered, stack_a, argc);
    sol = ft_ordering_stack(stack_a, argc);
                                /*i = 0;
                                while (i < argc - 1)
                                {
                                    ft_printf("Stack A -> i = %d value = %d pos = %d empty = %c\n",
                                    i, stack_a[i].value, stack_a[i].pos, stack_a[i].empty);
                                    i++;
                                }*/
    free (stack);
    free (ordered);
    free (stack_a);
    return (sol);
}

int ft_read_stack(int argc, char **argv, int *stack)
{
    int             i;
    int             j;
    long   atoi;

    i = 0;
    while (i < argc - 1)
    {
        j = 0;
        while (argv[i + 1][j] != 0)
        {
            if (((argv[i + 1][j] >= 43 && argv[i + 1][j] <= 46) || (argv[i + 1][j] >= 48 && argv[i + 1][j] <= 57)) == 0)
                return (ft_print_error());
            j++;
        }
        atoi = ft_atoi(argv[i + 1]);
        if (atoi > INT_MAX)
            return (ft_print_error());
        stack[i]= (int)atoi;
        j = 0;
        while (j++ <= i - 1)
            if (stack[j - 1] == (int)atoi)
                return (ft_print_error());
        i++;
    }
    return (0);
}

int *ft_order_init_stack(int *stack, int *ordered, int argc)
{
    int i;
    int j;
    int aux;

    i = -1;
    while (++i < argc - 1)
        ordered[i] = stack[i];
    i = 0;
    while (i < argc - 1)
    {
        j = 0;
        while (j < argc - i - 2)
        {
            if (ordered[j] > ordered[j + 1])
            {
                aux = ordered[j];
                ordered[j] = ordered[j + 1];
                ordered[j + 1] = aux;
            }
            j++;
        }
        i++;
    }
    return (ordered);
}

void    ft_build_stack_a(int *stack, int *ordered, t_element *stack_a, int argc)
{
    int i;
    int j;

    i = 0;
    while (i < argc - 1)
    {
        j = 0;
        while (j < argc - 1)
        {
            if (stack[i] == ordered[j])
            {
                stack_a[i].value = stack[i];
                stack_a[i].pos = j;
                stack_a[i].empty = 'N';
            }
            j++;
        }
        i++;
    }    
}
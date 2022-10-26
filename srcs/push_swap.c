/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:34:16 by marvin            #+#    #+#             */
/*   Updated: 2022/10/26 18:21:32 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"
#include "../includes/42_ft_printf/includes/ft_printf.h"
#include "../includes/42_libft/libft.h"

/*  Main function:
	1.  Allocating memory
	2.  Reading the initial number series (ft_read_stack function)  and save it
	to stack int pointer.
	3.  Ordering the initial stack (ft_order_init_stack function) to know the
		final position of each number.
	4.  Building stack a with the complete series numbers, their positions and
		a field to know how many "gaps"" there are in stack a (ft_build_stack_a
		function).
	5.  Finally main function calls to ft_ordering_stack function (split_cases.c
		file), deallocate memory and return 0 if no errors.
*/

int	main(int argc, char **argv)
{
	int			*stack;
	int			*ordered;
	t_element	*stack_a;
	int			sol;

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
	free (stack);
	free (ordered);
	free (stack_a);
	return (sol);
}

/*  ft_ordering_stack function:
	1.  Allocating memory for stack b.
	2.  Creating stack b with empty elements (same number than initial stack
		numbers).
	3.  Depending on the elements number it calls to ft_three_elements function
		(elements < 4) or ft_method function.
	4.  Deallocating stack b memory and returning 0 to main if no errors. */

int	ft_ordering_stack(t_element *stack_a, int argc)
{
	t_element	*stack_b;
	int			moves;

	moves = 0;
	stack_b = malloc(sizeof(t_element) * argc);
	if (!stack_b)
		return (ft_print_error());
	ft_init_stack_b(stack_b, argc);
	if (argc > 4)
	{
		if (ft_method(stack_a, stack_b, &moves, argc) == -1)
			return (-1);
	}
	else if (argc <= 4)
		ft_three_elements(stack_a, stack_b, &moves, argc);
	free (stack_b);
	return (0);
}

/*  function to get the main arguments and place them in stack a. */

int	ft_read_stack(int argc, char **argv, int *stack)
{
	int		i;
	int		j;
	long	atoi;

	i = 0;
	while (i < argc - 1)
	{
		j = -1;
		while (argv[i + 1][++j] != 0)
			if (((argv[i + 1][j] >= 43 && argv[i + 1][j] <= 46) ||
				(argv[i + 1][j] >= 48 && argv[i + 1][j] <= 57)) == 0)
				return (ft_print_error());
		atoi = ft_atoi(argv[i + 1]);
		if (atoi > INT_MAX)
			return (ft_print_error());
		stack[i] = (int)atoi;
		j = 0;
		while (j++ <= i - 1)
			if (stack[j - 1] == (int)atoi)
				return (ft_print_error());
		i++;
	}
	return (0);
}

/*  function to order the arguments, i.e., the initial stack. */

int	*ft_order_init_stack(int *stack, int *ordered, int argc)
{
	int	i;
	int	j;
	int	aux;

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

/*  function to build stack a. */

void	ft_build_stack_a(int *stack, int *ordered,
		t_element *stack_a, int argc)
{
	int	i;
	int	j;

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

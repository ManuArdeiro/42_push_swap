/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 01:21:59 by marvin            #+#    #+#             */
/*   Updated: 2022/10/19 19:22:55 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"
#include "../includes/42_ft_printf/includes/ft_printf.h"
#include "../includes/42_libft/libft.h"

/*  ft_stack_last_element returns the last element position. */

int	ft_stack_last_element(t_element *stack)
{
	int	i;

	i = 0;
	while (stack[i].empty == 'N')
		i++;
	return (i - 1);
}

int	ft_print_error(void)
{
	ft_printf("Error\n");
	return (-1);
}

/*  ft_lowest_number returns the lowest number of arguments received and 
    its position in sol pointer. */

void	ft_lowest_number(int number_1, int number_2, int number_3,
		int number_4, int *sol)
{
	sol[0] = INT_MAX;
	sol[1] = -1;
	if (number_1 > 0)
	{
		sol[0] = number_1;
		sol[1] = 1;
	}
	if (number_2 < sol[0] && number_2 > 0)
	{
		sol[0] = number_2;
		sol[1] = 2;
	}
	if (number_3 < sol[0] && number_3 > 0)
	{
		sol[0] = number_3;
		sol[1] = 3;
	}
	if (number_4 < sol[0] && number_4 > 0)
	{
		sol[0] = number_4;
		sol[1] = 4;
	}
}

/*  ft_stack_min returns the value and its position of the lowest element of
    stack argument via min pointer.*/

void	ft_stack_min(t_element *stack, int *min)
{
	int	i;
	int	b_elements;

	i = 0;
	b_elements = ft_stack_last_element(stack);
	min[0] = INT_MAX;
	min[1] = -1;
	while (i++ <= b_elements)
	{
		if (stack[i - 1].value < min[0])
		{
			min[0] = stack[i - 1].value;
			min[1] = i - 1;
		}
	}
	return ;
}

/*  ft_stack_max returns the value and its position of the biggest element of
    stack argument via max pointer.*/

void	ft_stack_max(t_element *stack, int *max)
{
	int	i;
	int	b_elements;

	i = 0;
	b_elements = ft_stack_last_element(stack);
	max[0] = INT_MIN;
	max[1] = -1;
	while (i++ <= b_elements)
	{
		if (stack[i - 1].value > max[0])
		{
			max[0] = stack[i - 1].value;
			max[1] = i - 1;
		}
	}
	return ;
}

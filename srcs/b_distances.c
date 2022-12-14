/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_distances.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 23:29:42 by marvin            #+#    #+#             */
/*   Updated: 2022/10/19 20:34:22 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"
#include "../includes/42_ft_printf/includes/ft_printf.h"
#include "../includes/42_libft/libft.h"

/*  ft_dist_b_to_a_up calculates the number of movements needed to move the
	first element from stack b to stack a into the b properly position. */

int	ft_dist_b_to_a_up(t_element *stack_a, t_element *stack_b)
{
	int	i;
	int	dif;
	int	pos;
	int	last_a;

	i = 0;
	last_a = ft_stack_last_element(stack_a);
	dif = INT_MAX;
	while (i <= last_a)
	{
		if (stack_a[i].pos - stack_b[0].pos > 0 && stack_a[i].pos
			- stack_b[0].pos < dif)
		{
			dif = stack_a[i].pos - stack_b[0].pos;
			pos = i;
		}
		i++;
	}
	return (pos + 1);
}

int	ft_dist_b_to_a_down(t_element *stack_a, t_element *stack_b)
{
	int	i;
	int	dif;
	int	pos;
	int	last_a;

	i = 0;
	last_a = ft_stack_last_element(stack_a);
	dif = INT_MAX;
	while (i <= last_a)
	{
		if (stack_a[i].pos - stack_b[0].pos > 0 && stack_a[i].pos
			- stack_b[0].pos < dif)
		{
			dif = stack_a[i].pos - stack_b[0].pos;
			pos = i;
		}
		i++;
	}
	return (last_a - pos + 1 + 1);
}

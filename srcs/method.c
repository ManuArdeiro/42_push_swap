/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 22:08:55 by marvin            #+#    #+#             */
/*   Updated: 2022/10/26 18:17:13 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"
#include "../includes/42_ft_printf/includes/ft_printf.h"
#include "../includes/42_libft/libft.h"

/*  ft_method function:
	hits        ->  number of ordered elements in stack a, meaning the number of
					elements bigger than previous one and fewer than next one
					(using ft_hits_count function in utils.c file).
	elements    ->  ft_stack_last_element function in utils.c file returns the 
					last element of the stack passed as argument. Notice that
					elements number is result + 1 because elements start in 0.
	1.  If all the stack a elements are ordered, ft_returning_from_b function is 
		called to return all the stack b elements.
	2.  If not all the stack a elements are ordered ft_next_step function is 
		called to analyze what to do next.
	3.  It will work as long as number of hits is fewer than elements.
*/

int	ft_method(t_element *stack_a, t_element *stack_b, int *moves, int argc)
{
	int	max[2];

	while (ft_hits_count(stack_a) < argc - 2)
	{
		ft_stack_max(stack_a, max);
		if (ft_hits_count(stack_a) == ft_stack_last_element(stack_a))
			return (ft_returning_from_b(stack_a, stack_b, moves, argc));
		else if (ft_hits_count(stack_a) == (ft_stack_last_element(stack_a) - 1)
			&& stack_a[0].value == max[0])
			ft_rotate_a(stack_a, moves, 'Y');
		else if (ft_hits_count(stack_a) == (ft_stack_last_element(stack_a) - 1)
			&& stack_a[0].pos > stack_a[1].pos)
			ft_swap_a(stack_a, moves, 'Y');
		else if (ft_next_step(stack_a, stack_b, moves) < 0)
			return (-1);
		if (ft_hits_count(stack_a) == argc - 2)
			return (0);
		else if (ft_hits_count(stack_a) == ft_stack_last_element(stack_a))
			return (ft_returning_from_b(stack_a, stack_b, moves, argc));
	}
	return (0);
}

/*  ft_next_step function:
	1.  If stack a first element is bigger than last one, function rotates a.
	2.  If not, if stack has 1 element or less, function pushes a first element
		to b.
	3.  If not it calls to ft_case_selection to decide what to do (unless the
		stack b is already ready to receive the stack a first element). */

int	ft_next_step(t_element *stack_a, t_element *stack_b, int *moves)
{
	int	last_a;
	int	last_b;

	last_a = ft_stack_last_element(stack_a);
	last_b = ft_stack_last_element(stack_b);
	if (stack_a[0].pos > stack_a[last_a].pos)
		ft_rotate_a(stack_a, moves, 'Y');
	else if (last_b <= 0)
		ft_push_b(stack_a, stack_b, moves);
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

/*  ft_case_selection function: It calculates the number of movements for each
	of these options:
	1.  Pushing the first b element to the a bottom (in the properly position).
	2.  Moving the first a element to the a bottom (in the properly position).
	3.  Moving the first a element to b via rotating b (in the properly
		position).
	4.  Moving the first a element to b via reverse rotating b (in the properly
		position).
	If it requires less than 4 movements to "replace" first a element, it will
	be done (for ft_option_selection function), if not ft_find_better function
	will be called. */

int	ft_case_selection(t_element *stack_a, t_element *stack_b, int *moves)
{
	int	move[2];

	ft_lowest_number(ft_returning_b(stack_a, stack_b), ft_dist_a_down(stack_a),
		ft_dist_b_up(stack_a, stack_b), ft_dist_b_down(stack_a, stack_b), move);
	if (move[0] < 4)
		return (ft_option_selection(stack_a, stack_b, moves, move) < 0);
	else if (move[0] > 3)
	{
		if (ft_find_better(stack_a, stack_b, moves) < 0)
		{
			ft_lowest_number(ft_returning_b(stack_a, stack_b), move,
				ft_dist_a_down(stack_a), ft_dist_b_up(stack_a, stack_b),
				ft_dist_b_down(stack_a, stack_b));
			return (ft_option_selection(stack_a, stack_b, moves, move));
		}
		return (0);
	}
	return (0);
}

/*  ft_option_selection function: calls the appropiate function to make the
	next movements. */

int	ft_option_selection(t_element *stack_a, t_element *stack_b, int *moves,
		int *move)
{
	if (move[1] == 1)
		return (ft_case_1(stack_a, stack_b, moves));
	else if (move[1] == 2)
		return (ft_case_2(stack_a, stack_b, moves));
	else if (move[1] == 3)
		return (ft_case_3(stack_a, stack_b, moves));
	else if (move[1] == 4)
		return (ft_case_4(stack_a, stack_b, moves));
	else
		return (-1);
	return (0);
}

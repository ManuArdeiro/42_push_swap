/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:05:33 by jolopez-          #+#    #+#             */
/*   Updated: 2022/04/08 20:40:34 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static int		ft_spaces(const char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int		ft_number(const char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	return (-1);
}

long	ft_atoi(const char *str)
{
	int				i;
	long	res;
	int				is_neg;

	res = 0;
	i = 0;
	is_neg = 1;
	while (ft_spaces(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i] == '-')
		{
			is_neg = -1;
			i++;
		}
	if (str[i] && ft_number(str[i]) == -1)
		return ((long)INT_MAX + 1);
	while (str[i])
	{
		res = res * 10 + ft_number(str[i]);
		if (res > (long)INT_MAX || res < (long)INT_MIN)
			return ((long)INT_MAX + 1);
		i++;
	}
	return (res * is_neg);
}

/*int	main(void)
{
	char	n[40] = "+\t\v\f\r\n \f1234";
	char	m[40] = "2147483648";

	int		i;
	int		j;

	i = ft_atoi(n);
	j = atoi(n);
	printf ("atoi = %d\nft_atoi = %d\n", j, i);
	i = ft_atoi(m);
	j = atoi(m);
	printf ("atoi = %d\nft_atoi = %d\n", j, i);
	return (0);
}*/

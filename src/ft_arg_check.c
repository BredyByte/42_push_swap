/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:03:44 by marvin            #+#    #+#             */
/*   Updated: 2023/08/28 12:20:31 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_num(char *arg)
{
	int	num;

	num = ft_atoi(arg);
	if (num == 0 && arg[0] != '\0')
		return (0);
	return (1);
}

static int	ft_check_range(int num)
{
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

static int	ft_check_duplicate(int *values, int num, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (values[i] == num)
			return (0);
		i++;
	}
	return (1);
}

int	ft_arg_check(int argc, char **argv, int *values)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!ft_check_num(argv[i]))
			return (0);
		if (!ft_check_range(ft_atoi(argv[i])))
			return (0);
		if (!ft_check_duplicate(values, ft_atoi(argv[i]), i))
			return (0);
		values[i] = ft_atoi(argv[i]);
		i++;
	}
	return (1);
}

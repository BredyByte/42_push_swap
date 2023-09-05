/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:03:44 by marvin            #+#    #+#             */
/*   Updated: 2023/09/05 14:40:04 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_num(char *arg)
{
	if (!(ft_isdigit(arg)))
		return (0);
	ft_atoi(arg);
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

void	ft_arg_check(int argc, char **argv, int *values)
{
	int	i;

	if (argc < 2)
	{
		ft_arg_error(values);
	}
	i = 0;
	while (i < argc)
	{
		if (!ft_check_num(argv[i]))
			ft_arg_error(values);
		if (!ft_check_range(ft_atoi(argv[i])))
			ft_arg_error(values);
		if (!ft_check_duplicate(values, ft_atoi(argv[i]), i))
			ft_arg_error(values);
		values[i] = ft_atoi(argv[i]);
		i++;
	}
	values[i] = '\0';
}

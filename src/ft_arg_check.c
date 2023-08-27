/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:03:44 by marvin            #+#    #+#             */
/*   Updated: 2023/08/27 18:09:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_error(void)
{
	ft_printf("Arguments Error!\n");
}

int	ft_check_num(char *arg)
{
	int	num;

	num = ft_atoi(arg);
	if (num == 0 && arg[0] != '\0')
		return (0);
	return (1);
}

int	ft_check_range(int num)
{
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

int	ft_check_duplicate(int *values, int num, int size)
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

	i = 1;
	while (i < argc)
	{
		if (!ft_check_num(argv[i]))
		{
			ft_print_error();
			return ;
		}
		if (!ft_check_range(ft_atoi(argv[i])))
		{
			ft_print_error();
			return ;
		}
		if (!ft_check_duplicate(values, ft_atoi(argv[i]), i - 1))
		{
			ft_print_error();
			return ;
		}
		values[i - 1] = ft_atoi(argv[i]);
		i++;
	}
}

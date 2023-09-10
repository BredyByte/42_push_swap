/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:03:44 by marvin            #+#    #+#             */
/*   Updated: 2023/09/10 19:58:16 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_num(char *arg)
{
	if (!ft_isdigit(arg))
		return (0);
	return (1);
}

static int	ft_check_range(int num)
{
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

static int	are_strings_equal(char *s1, char *s2)
{
	return (ft_strcmp(s1, s2) == 0);
}

static int	ft_check_duplicate(char **argv)
{
	char	**start;
	char	**current;

	start = argv;
	while (*start)
	{
		current = start + 1;
		while (*current)
		{
			if (are_strings_equal(*start, *current))
				return (0);
			current++;
		}
		start++;
	}
	return (1);
}

void	ft_arg_check(int argc, char **argv)
{
	char	**current;

	current = argv;
	(void)argc;
	while (*current)
	{
		if (!ft_check_num(*current))
			ft_arg_error();
		if (!ft_check_range(ft_atoi(*current)))
			ft_arg_error();
		if (!ft_check_duplicate(argv))
			ft_arg_error();
		current++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:03:44 by marvin            #+#    #+#             */
/*   Updated: 2023/09/14 11:59:58 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_check_range(char *str)
{
	size_t	len;

	len = ft_strlen(str, 's');
	if (len > 11)
		return (0);
	else if (len == 11 && str[0] != '-' && str[0] != '+')
		return (1);
	else if (len == 11 && str[0] == '-')
	{
		if (ft_strncmp("-2147483648", str, 12) < 0)
			return (0);
	}
	else if (len == 11 && str[0] == '+')
	{
		if (ft_strncmp("+2147483647", str, 12) < 0)
			return (0);
	}
	else if (len == 10 && str[0] != '-' && str[0] != '+')
	{
		if (ft_strncmp("2147483647", str, 10) < 0)
			return (0);
	}
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

void	ft_arg_check(char **argv)
{
	char	**current;

	current = argv;
	while (*current)
	{
		if (!ft_is_valid_number(*current))
			ft_arg_error();
		if (!ft_check_range(*current))
			ft_arg_error();
		if (!ft_check_duplicate(argv))
			ft_arg_error();
		current++;
	}
}

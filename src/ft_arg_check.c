/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:03:44 by marvin            #+#    #+#             */
/*   Updated: 2023/09/14 14:25:46 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_check_int_len(size_t len, char sig, char *str)
{
	if (len > 11)
		return (1);
	else if (len == 11 && sig != '-' && str[0] != '+')
		return (1);
	else if (len == 11 && sig == '-')
	{
		if (ft_strncmp("-2147483648", str, 15) < 0)
			return (1);
	}
	else if (len == 11 && sig != '+')
	{
		if (ft_strncmp("+2147483647", str, 15) < 0)
			return (1);
	}
	else if (len == 10 && sig != '-' && sig != '+')
	{
		if (ft_strncmp("2147483647", str, 15) < 0)
			return (1);
	}
	return (0);
}

size_t	ft_check_int(int argc, char **argv)
{
	int		i;
	size_t	len;

	i = 0;
	while (i < argc)
	{
		len = ft_strlen(argv[i], 's');
		if (ft_check_int_len(len, argv[i][0], argv[i]))
			return (1);
		i++;
	}
	return (0);
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
	if (ft_check_digit(argc, argv) == 1)
		ft_arg_error();
	if (ft_check_int(argc, argv) == 1)
		ft_arg_error();
	if (!ft_check_duplicate(argv))
		ft_arg_error();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:26:06 by dbredykh          #+#    #+#             */
/*   Updated: 2023/09/14 14:26:20 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_check_digit(int argc, char *argv[])
{
	int		i;
	size_t	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (j == 0 && (argv[i][0] == '-' || argv[i][0] == '+'))
				j++;
			if (!ft_isdigitchar(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:10:08 by marvin            #+#    #+#             */
/*   Updated: 2023/08/29 13:13:05 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(int *values)
{
	int	i;
	int	j;
	int	ind_fin;

	i = 0;
	while (values[i])
	{
		j = 0;
		ind_fin = 0;
		while (values[j])
		{
			if (values[i] > values[j])
				ind_fin++;
			j++;
		}
		printf ("num: %d, fin_index: %d\n",values[i], ind_fin);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	*values;
	int	len;

	values = malloc(sizeof(int) * argc - 1);
	if (!values)
		return (1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		len = ft_dstrlen(argv);
		ft_arg_check(len, argv, values);
	}
	else
		ft_arg_check(argc - 1, argv + 1, values);
	/* init(values); */
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:10:08 by marvin            #+#    #+#             */
/*   Updated: 2023/08/27 18:11:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{	
	int *values;

	values = malloc(sizeof(int) * argc - 1);
	if (!values)
		return (0);
	ft_arg_check(argc, argv, values);
	return (0);
}

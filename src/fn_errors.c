/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:20:34 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/30 14:05:16 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_memory_error(t_list **stack_a, t_list **stack_b)
{
	size_t	error;

	error = 0;
	if (!stack_a)
		error = 1;
	if (!stack_b)
	{
		ft_lstclear(stack_a);
		error = 1;
	}
	if (error == 1)
		write(2, "Error\n", 6);
	return (error);
}

void	ft_arg_error(int *values)
{
	ft_printf("Arguments Error!!\n");
	free(values);
	exit(1);
}

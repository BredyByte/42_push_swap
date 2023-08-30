/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:10:08 by marvin            #+#    #+#             */
/*   Updated: 2023/08/30 14:10:50 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*values;
	int		len;
	t_list	**stack_a;
	t_list	**stack_b;

	stack_a = NULL;
	stack_b = calloc(1, sizeof(t_list *));
	values = malloc(sizeof(int) * argc);
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
	stack_a = ft_create_stack(values, stack_a);
	if (ft_memory_error(stack_a, stack_b))
		return (1);
	ft_free_all(stack_a, stack_b);
	return (0);
}

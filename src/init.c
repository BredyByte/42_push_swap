/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:10:08 by marvin            #+#    #+#             */
/*   Updated: 2023/09/14 11:51:28 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_resources(t_list ***stack_a, t_list ***stack_b)
{
	*stack_a = NULL;
	*stack_b = calloc(1, sizeof(t_list *));
}

static char	**process_args(int argc, char **argv)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		ft_arg_check(args);
		return (args);
	}
	else
	{
		ft_arg_check(argv + 1);
		return (argv + 1);
	}
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	**values;

	init_resources(&stack_a, &stack_b);
	values = process_args(argc, argv);
	stack_a = ft_create_stack(values, stack_a);
	if (ft_memory_error(stack_a, stack_b))
		return (1);
	ft_fill_ind_fin(stack_a);
	push_swap(stack_a, stack_b, ft_lstsize(*stack_a));
	ft_free_all(stack_a, stack_b, values, argc);
	return (0);
}

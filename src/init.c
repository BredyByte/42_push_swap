/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:10:08 by marvin            #+#    #+#             */
/*   Updated: 2023/08/29 17:17:35 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	error_memory(t_list **stack_a, t_list **stack_b)
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

t_list	**ft_create_list(int *values, t_list **stack_a)
{
	int		i;
	int		j;
	int		ind_fin;
	t_list	*temp;

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
		temp = ft_lstnew(values[i], ind_fin, j);
		if (i == 0)
			ft_lstadd_front(stack_a, temp);
		else
			ft_lstadd_back(stack_a, temp);
		i++;
	}
	return (stack_a);
}

void	ft_free_all(t_list **stack_a, t_list **stack_b)
{
	ft_lstclear(stack_a);
	free(stack_a);
	ft_lstclear(stack_b);
	free(stack_b);
}

int	main(int argc, char **argv)
{
	int		*values;
	int		len;
	t_list	**stack_a;
	t_list	**stack_b;

	stack_a = NULL;
	stack_b = ft_calloc(1, sizeof(t_list *));
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
	stack_a = ft_create_list(values, stack_a);
	if (error_memory(stack_a, stack_b))
		return (1);
	return (0);
}

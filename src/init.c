/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:10:08 by marvin            #+#    #+#             */
/*   Updated: 2023/09/05 14:40:32 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_resources(t_list ***stack_a,
						t_list ***stack_b, int argc, int **values)
{
	*stack_a = NULL;
	*stack_b = calloc(1, sizeof(t_list *));
	*values = malloc(sizeof(int) * argc);
	if (!*values)
		exit(1);
}

void	process_args(int argc, char **argv, int *values)
{
	int	len;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		printf ("davyd %c\n", argv[0][1]);
		len = ft_dstrlen(argv);
    	for (int i = 0; argv[i]; i++)
        	printf("argv[%d] = %s\n", i, argv[i]);
		ft_arg_check(len, argv, values);
	}
	else
		ft_arg_check(argc - 1, argv + 1, values);
}

int	main(int argc, char **argv)
{
	int		*values;
	t_list	**stack_a;
	t_list	**stack_b;

	init_resources(&stack_a, &stack_b, argc, &values);
	process_args(argc, argv, values);
	stack_a = ft_create_stack(values, stack_a);
	if (ft_memory_error(stack_a, stack_b))
		return (1);
	push_swap(stack_a, stack_b, ft_strlen(values, 'n'));
	t_list	*tmp;
	tmp = *stack_a;
	while (tmp)
	{
		printf("value: %d, ", tmp->n);
		printf("fin_index: %d, \n", tmp->fin_ind);
		tmp = tmp->next;
	}
	ft_free_all(stack_a, stack_b, values);
	return (0);
}

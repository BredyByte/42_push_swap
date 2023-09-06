/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:10:08 by marvin            #+#    #+#             */
/*   Updated: 2023/09/06 12:50:17 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_resources(t_list ***stack_a,
						t_list ***stack_b)
{
	*stack_a = NULL;
	*stack_b = calloc(1, sizeof(t_list *));
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		word_count;
	int		i;
	int		j;
	int		k;

	word_count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			word_count++;
		while (s[i] && s[i] != c)
			i++;
	}
	if (!(arr = (char **)malloc(sizeof(char *) * (word_count + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			j = 0;
			while (s[i + j] && s[i + j] != c)
				j++;
			arr[k] = strndup(&s[i], j);
			k++;
			i += j;
		}
	}
	arr[k] = NULL;
	return (arr);
}

char	**process_args(int argc, char **argv)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		ft_arg_check(argc - 1, args);
		return (args);
	}
	else
	{
		ft_arg_check(argc - 1, argv + 1);
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
	push_swap(stack_a, stack_b, ft_lstsize(*stack_a));
	t_list	*tmp;
	tmp = *stack_a;
	while (tmp)
	{
		printf("value: %d, ", tmp->n);
		printf("fin_index: %d, \n", tmp->fin_ind);
		tmp = tmp->next;
	}
	ft_free_all(stack_a, stack_b, values, argc);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:06:51 by dbredykh          #+#    #+#             */
/*   Updated: 2023/09/10 19:49:38 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp && tmp->next)
	{
		if (tmp->n > tmp->next->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	max_fin_ind(t_list **stack_a)
{
	t_list	*tmp;
	int		max;

	tmp = *stack_a;
	max = tmp->fin_ind;
	while (tmp)
	{
		if (tmp->fin_ind > max)
			max = tmp->fin_ind;
		tmp = tmp->next;
	}
	return (max);
}

static int	ft_find_ind_fin(t_list **stack_a, int value)
{
	t_list	*tmp;
	int		fin_ind;

	tmp = *stack_a;
	fin_ind = 1;
	while (tmp)
	{
		if (value > tmp->n)
			fin_ind++;
		tmp = tmp->next;
	}
	return (fin_ind);
}

void	ft_fill_ind_fin(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		tmp->fin_ind = ft_find_ind_fin(stack_a, tmp->n);
		tmp = tmp->next;
	}
}

void	ft_free_all(t_list **stack_a, t_list **stack_b, char **values,
		int v_case)
{
	int	i;

	ft_lstclear(stack_a);
	free(stack_a);
	ft_lstclear(stack_b);
	free(stack_b);
	if (v_case == 2)
	{
		i = 0;
		while (values[i])
		{
			free(values[i]);
			i++;
		}
		free(values);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_algorithms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:31:34 by dbredykh          #+#    #+#             */
/*   Updated: 2023/09/06 14:32:50 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_alg_two(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (tmp->n > tmp->next->n)
		ft_swap(stack_a, NULL, 'a');
}

void	ft_alg_three(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (tmp->n > tmp->next->n && tmp->n < tmp->next->next->n)
		ft_swap(stack_a, NULL, 'a');
	else if (tmp->n > tmp->next->n
		&& tmp->next->n > tmp->next->next->n
		&& tmp->n > tmp->next->next->n)
	{
		ft_swap(stack_a, NULL, 'a');
		ft_rev_rotate(stack_a, NULL, 'a');
	}
	else if (tmp->n > tmp->next->n
		&& tmp->next->n < tmp->next->next->n
		&& tmp->n > tmp->next->next->n)
		ft_rotate(stack_a, NULL, 'a');
	else if (tmp->next->next->n > tmp->n && tmp->next->n > tmp->next->next->n)
	{
		ft_swap(stack_a, NULL, 'a');
		ft_rotate(stack_a, NULL, 'a');
	}
	else if (tmp->n > tmp->next->next->n && tmp->next->n > tmp->n)
		ft_rev_rotate(stack_a, NULL, 'a');
}

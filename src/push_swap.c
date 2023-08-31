/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:14:55 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/31 18:41:39 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_alg_two(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (tmp->n > tmp->next->n)
		ft_swap(stack_a, NULL, 'a');
}

static	void	ft_alg_three(t_list **stack_a)
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

void	push_swap(t_list **stack_a, t_list **stack_b, int len)
{
	(void) stack_b;
	if (len == 2)
		ft_alg_two(stack_a);
	if (len == 3)
		ft_alg_three(stack_a);
}

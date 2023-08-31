/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:06:51 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/31 16:19:48 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_all(t_list **stack_a, t_list **stack_b, int *values)
{
	ft_lstclear(stack_a);
	free(stack_a);
	ft_lstclear(stack_b);
	free(stack_b);
	free(values);
}

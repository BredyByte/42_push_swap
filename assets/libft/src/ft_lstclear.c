/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:57:55 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/30 13:27:49 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*node;
	t_list	*aux;

	node = *lst;
	while (node != NULL)
	{
		aux = node;
		node = node->next;
		free(aux);
	}
	*lst = node;
}

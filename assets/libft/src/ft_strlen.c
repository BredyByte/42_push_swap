/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:19:08 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/31 16:22:19 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const void *s, char type)
{
	size_t	i;

	i = 0;
	if (type == 's')
	{
		while (((char *)s)[i])
			i++;
	}
	else if (type == 'n')
	{
		while (((int *)s)[i])
			i++;
	}
	return (i);
}

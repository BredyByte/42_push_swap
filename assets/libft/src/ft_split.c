/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:55:53 by dbredykh          #+#    #+#             */
/*   Updated: 2023/09/06 12:32:15 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	word_count;
	int	i;

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
	return (word_count);
}

static void	split_words(const char *s, char c, char **arr)
{
	int	i;
	int	j;
	int	k;

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
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	int		word_count;

	word_count = count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!arr)
		return (NULL);
	split_words(s, c, arr);
	arr[word_count] = NULL;
	return (arr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 05:56:04 by anoteris          #+#    #+#             */
/*   Updated: 2024/10/20 07:50:52 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	res;

	while (*s == c && *s)
		s++;
	res = 0;
	while (*s)
	{
		while (*s != c && *s)
			s++;
		res++;
		while (*s == c && *s)
			s++;
	}
	return (res);
}

static void	free_split(char **to_free, int nb_free)
{
	while (nb_free >= 0)
	{
		free(to_free[nb_free]);
		nb_free--;
	}
	free(to_free);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	res = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			j = 0;
			while (s[j] != c && s[j])
				j++;
			res[i++] = ft_substr(s, 0, j);
			if (!res[i - 1])
				return (free_split(res, i - 1), NULL);
			s += j;
		}
		if (*s)
			s++;
	}
	res[i] = (NULL);
	return (res);
}

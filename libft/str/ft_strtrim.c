/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 05:02:48 by anoteris          #+#    #+#             */
/*   Updated: 2024/10/20 10:35:20 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_part_of(char c, char const *set) // return 1/0 if c in/not in set
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		trim_start;
	int		trim_end;

	trim_start = 0;
	while (is_part_of(s1[trim_start], set))
		trim_start++;
	trim_end = ft_strlen(s1) - 1;
	while (is_part_of(s1[trim_end], set))
		trim_end--;
	if (trim_start > trim_end)
		return (ft_strdup(""));
	res = ft_substr(s1, trim_start, ((trim_end + 1) - trim_start));
	return (res);
}

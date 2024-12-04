/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 04:03:29 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/12 21:44:00 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		len_s1;
	int		len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	res = malloc(len_s1 + len_s2 + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, len_s1 + 1);
	ft_strlcat(res, s2, (len_s1 + len_s2 + 1));
	return (res);
}

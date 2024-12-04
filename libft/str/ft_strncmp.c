/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:01:12 by anoteris          #+#    #+#             */
/*   Updated: 2024/10/19 07:05:49 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0 ;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++ ;
	if (i == n)
		return (0);
	return (((unsigned char *) s1)[i] - ((unsigned char *) s2)[i]);
}

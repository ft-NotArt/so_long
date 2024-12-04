/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:07:08 by anoteris          #+#    #+#             */
/*   Updated: 2024/10/20 06:55:47 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	if (n <= 0)
		return (NULL);
	i = 0;
	while (i + 1 < n && ((unsigned char *) s)[i] != (unsigned char) c)
		i++;
	if (((unsigned char *) s)[i] == (unsigned char) c)
		return ((char *)(s + i));
	return (NULL);
}

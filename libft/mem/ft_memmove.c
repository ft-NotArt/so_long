/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 08:11:20 by anoteris          #+#    #+#             */
/*   Updated: 2024/10/20 16:41:00 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest <= src)
	{
		while (i < n)
		{
			((unsigned char *) dest)[i] = ((unsigned char *) src)[i];
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			i++;
			((unsigned char *)dest)[n - i] = ((unsigned char *)src)[n - i];
		}
	}
	return (dest);
}

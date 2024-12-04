/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:15:48 by anoteris          #+#    #+#             */
/*   Updated: 2024/10/20 06:54:40 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((unsigned char *) s1)[i] == ((unsigned char *) s2)[i])
		i++;
	if (i == n)
		return (0);
	return (((unsigned char *) s1)[i] - (((unsigned char *) s2)[i]));
}

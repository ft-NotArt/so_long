/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 09:13:08 by anoteris          #+#    #+#             */
/*   Updated: 2024/10/20 15:34:51 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0 ;
	while (s[i])
		i++ ;
	while (i > 0 && s[i] != (char) c)
		i-- ;
	if (s[i] == (char) c)
		return ((char *)(s + i));
	return (NULL);
}

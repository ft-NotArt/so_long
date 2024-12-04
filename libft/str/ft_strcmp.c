/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 08:50:55 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/26 08:58:49 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0 ;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++ ;
	return (((unsigned char *) s1)[i] - ((unsigned char *) s2)[i]);
}

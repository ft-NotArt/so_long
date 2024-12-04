/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 05:17:02 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/14 05:20:19 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	long	res ;
	int		sign ;

	res = 0 ;
	sign = 1 ;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++ ;
	if (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			sign = -1 ;
	while (*nptr >= '0' && *nptr <= '9')
		res = res * 10 + (*(nptr++) - '0');
	return (res * sign);
}

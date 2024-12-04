/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:02:53 by anoteris          #+#    #+#             */
/*   Updated: 2024/10/20 15:25:12 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	res ;
	int	sign ;

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 07:30:30 by anoteris          #+#    #+#             */
/*   Updated: 2024/10/20 15:41:45 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		digits;
	long	n_abs;
	char	*res;

	if (n == 0)
		return (ft_strdup("0"));
	n_abs = ((long) n * (1 + ((n < 0) * (-2))));
	digits = n < 0;
	while (n_abs > 0)
	{
		n_abs /= 10;
		digits++;
	}
	res = ft_calloc(digits + 1, sizeof(char));
	if (!res)
		return (NULL);
	if (n < 0)
		res[0] = '-';
	n_abs = (long) n * (1 + ((n < 0) * (-2)));
	while (n_abs > 0)
	{
		res[--digits] = (n_abs % 10) + '0';
		n_abs /= 10;
	}
	return (res);
}

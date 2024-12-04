/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:39:39 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/05 06:40:47 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexlen(unsigned long nb)
{
	int		digits ;

	digits = nb == 0 ;
	while (nb > 0)
	{
		nb /= 16;
		digits++;
	}
	return (digits);
}

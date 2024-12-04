/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:35:21 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/05 06:40:36 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int nb)
{
	int		digits ;
	long	n_abs ;

	n_abs = ((long) nb * (1 + ((nb < 0) * (-2))));
	digits = nb <= 0;
	while (n_abs > 0)
	{
		n_abs /= 10;
		digits++;
	}
	return (digits);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 00:13:27 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/05 06:41:11 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_uintlen(unsigned int nb)
{
	int		digits ;

	digits = nb == 0 ;
	while (nb > 0)
	{
		nb /= 10;
		digits++;
	}
	return (digits);
}

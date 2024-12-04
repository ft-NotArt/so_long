/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_field_address.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:49:35 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/12 20:01:50 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_field_address(va_list args, t_percent *percent)
{
	unsigned long	nbr ;
	int				len ;
	int				written ;
	int				space ;

	nbr = va_arg(args, unsigned long);
	len = 5 ;
	if (nbr)
		len = ft_hexlen(nbr);
	written = 5 * (nbr == 0);
	space = percent->field.min - len ;
	while ((!percent->zero || percent->field.period)
		&& !percent->minus && space-- > (2 * !!nbr))
		written += ft_write_field(percent);
	if (nbr)
		written += ft_write_0x(percent);
	while (percent->zero && !percent->minus && space-- > (2 * !!nbr))
		written += ft_write_field(percent);
	if (nbr)
		written += ft_puthexnbr_fd(nbr, STDOUT_FILENO, MIN);
	else
		write(STDOUT_FILENO, "(nil)", 5);
	while (percent->minus && space-- > (2 * !!nbr))
		written += ft_write_field(percent);
	return (percent->format = 0, written);
}

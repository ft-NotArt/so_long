/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_identifier_address.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 00:46:05 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/12 20:23:54 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_id_p(va_list args)
{
	unsigned long	nb ;
	int				written ;

	written = 0 ;
	nb = va_arg(args, unsigned long);
	if (!nb)
		return (write(STDOUT_FILENO, "(nil)", 5));
	written += write(STDOUT_FILENO, "0x", 2);
	written += ft_puthexnbr_fd(nb, STDOUT_FILENO, MIN);
	return (written);
}

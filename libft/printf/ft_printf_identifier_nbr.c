/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_identifier_nbr.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:41:52 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/12 20:22:59 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_id_d(va_list args)
{
	int	nb ;
	int	written ;

	written = 0 ;
	nb = va_arg(args, int);
	written += ft_putnbr_fd(nb, STDOUT_FILENO);
	return (written);
}

int	ft_id_u(va_list args)
{
	unsigned int	nb ;
	int				written ;

	written = 0 ;
	nb = va_arg(args, unsigned int);
	written += ft_putunbr_fd(nb, STDOUT_FILENO);
	return (written);
}

int	ft_id_x(va_list args)
{
	unsigned int	nb ;
	int				written ;

	written = 0 ;
	nb = va_arg(args, unsigned int);
	written += ft_puthexnbr_fd((unsigned long) nb, STDOUT_FILENO, MIN);
	return (written);
}

int	ft_id_xx(va_list args)
{
	unsigned int	nb ;
	int				written ;

	written = 0 ;
	nb = va_arg(args, unsigned int);
	written += ft_puthexnbr_fd((unsigned long) nb, STDOUT_FILENO, MAJ);
	return (written);
}

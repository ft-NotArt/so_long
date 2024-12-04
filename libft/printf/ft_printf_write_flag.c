/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_flag.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:41:48 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/12 20:13:09 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_field(t_percent *percent)
{
	if (percent->zero && !percent->field.period)
		write(STDOUT_FILENO, "0", 1);
	else
		write(STDOUT_FILENO, " ", 1);
	return (1);
}

int	ft_write_sign(int nb, t_percent *percent)
{
	int	written ;

	written = 0 ;
	if (nb < 0)
		write(STDOUT_FILENO, "-", 1);
	else
	{
		if (percent->plus)
			written += write(STDOUT_FILENO, "+", 1);
		if (percent->blank)
			written += write(STDOUT_FILENO, " ", 1);
	}
	return (written);
}

int	ft_write_0x(t_percent *percent)
{
	int	written ;

	written = 0 ;
	if (percent->format == 'p')
		written += write(STDOUT_FILENO, "0x", 2);
	if (percent->hashtag)
	{
		if (percent->format == 'x')
			written += write(STDOUT_FILENO, "0x", 2);
		if (percent->format == 'X')
			written += write(STDOUT_FILENO, "0X", 2);
	}
	return (written);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_field_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 05:33:43 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/12 20:26:58 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_field_char(va_list args, t_percent *percent)
{
	int		written ;
	char	c ;

	written = 0 ;
	c = (char) va_arg(args, int);
	if (percent->minus)
		written += write(STDOUT_FILENO, &c, 1);
	while (percent->field.min-- > 1)
		written += write(STDOUT_FILENO, " ", 1);
	if (!percent->minus)
		written += write(STDOUT_FILENO, &c, 1);
	percent->format = 0 ;
	return (written);
}

static int	ft_putstr_max_precision(t_percent *percent, char **str, int len)
{
	int	written ;

	written = 0 ;
	if (percent->field.max < len && percent->field.period)
	{
		while (percent->field.max-- > 0)
			written += write(STDOUT_FILENO, (*str)++, 1);
	}
	else
		written += write(STDOUT_FILENO, *str, len);
	return (written);
}

int	ft_field_str(va_list args, t_percent *percent)
{
	char	*str ;
	int		len ;
	int		written ;

	str = va_arg(args, char *);
	written = 0 ;
	len = 0 ;
	if (!str)
	{
		if (!percent->field.period || percent->field.max >= 6)
			len = 6 ;
	}
	else
		len = ft_strlen(str);
	if (percent->field.max < len && percent->field.period)
		len = percent->field.max ;
	while (!percent->minus && percent->field.min-- > len)
		written += write(STDOUT_FILENO, " ", 1);
	if (!str && (!percent->field.period || percent->field.max >= 6))
		written += write(STDOUT_FILENO, "(null)", len);
	else
		written += ft_putstr_max_precision(percent, &str, len);
	while (percent->minus && percent->field.min-- > len)
		written += write(STDOUT_FILENO, " ", 1);
	return (percent->format = 0, written);
}

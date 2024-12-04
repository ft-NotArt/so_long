/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_identifiers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:58:21 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/12 20:22:04 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int (*const	g_identifiers[UCHAR_MAX + 1])(va_list args) = {
['c'] = ft_id_c, ['s'] = ft_id_s, ['p'] = ft_id_p,
['d'] = ft_id_d, ['i'] = ft_id_d, ['u'] = ft_id_u,
['x'] = ft_id_x, ['X'] = ft_id_xx, ['%'] = ft_id_percent};

static int (*const	g_field[UCHAR_MAX + 1])(va_list args, t_percent *percent)
	= {
['c'] = ft_field_char, ['s'] = ft_field_str,
['d'] = ft_field_int, ['i'] = ft_field_int,
['u'] = ft_field_uint,
['x'] = ft_field_hex, ['X'] = ft_field_hex, ['p'] = ft_field_address};

static int	ft_printf_field_handling(va_list args, t_percent *percent)
{
	if (percent->field.min
		|| percent->field.period
		|| percent->field.max
		|| percent->minus
		|| percent->zero
		|| percent->plus
		|| percent->blank
		|| percent->hashtag)
	{
		if (!g_field[percent->format])
			return (0);
		return (g_field[percent->format](args, percent));
	}
	return (0);
}

static int	ft_printf_format_handling(va_list args, t_percent *percent)
{
	if (!g_identifiers[percent->format])
		return (0);
	return (g_identifiers[percent->format](args));
}

int	ft_printf_format(va_list args, t_percent *percent)
{
	int	written ;

	written = 0 ;
	written += ft_printf_field_handling(args, percent);
	written += ft_printf_format_handling(args, percent);
	return (written);
}

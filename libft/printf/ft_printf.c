/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:16:24 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/12 20:29:37 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percent(char **format, va_list args)
{
	t_percent	percent ;

	(*format)++;
	percent = ft_percent_init(format, args);
	return (ft_printf_format(args, &percent));
}

__attribute__ ((format(printf, 1, 2))) int	ft_printf(const char *format, ...)
{
	char	*browseable_format ;
	va_list	args ;
	int		written ;

	if (!format)
		return (-1);
	va_start(args, format);
	browseable_format = (char *) format ;
	written = 0 ;
	while (*browseable_format != '\0')
	{
		if (*browseable_format == '%')
			written += ft_percent((&browseable_format), args);
		else
		{
			written += write(STDOUT_FILENO, browseable_format, 1);
			browseable_format++ ;
		}
	}
	va_end(args);
	if (written < 0)
		return (-2);
	return (written);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_struct_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:11:42 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/12 20:15:28 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_percent_flag(t_percent *percent, char **format)
{
	while (ft_isflag(**format) && **format)
	{
		if (**format == '-')
			percent->minus = true ;
		if (**format == '0')
			percent->zero = true ;
		if (**format == '+')
			percent->plus = true ;
		if (**format == ' ')
			percent->blank = true ;
		if (**format == '#')
			percent->hashtag = true ;
		(*format)++ ;
	}
}

static void	ft_percent_field(t_percent *percent, char **format, va_list args)
{
	if (**format == '*')
	{
		percent->field.min = va_arg(args, int);
		(*format)++ ;
	}
	while ((ft_isdigit(**format)) && **format)
	{
		percent->field.min = (percent->field.min * 10) + ((**format) - '0');
		(*format)++ ;
	}
	if (**format == '.' && **format)
	{
		percent->field.period = true ;
		(*format)++ ;
		if (**format == '*')
		{
			percent->field.max = va_arg(args, int);
			(*format)++ ;
		}
		while ((ft_isdigit(**format)) && **format)
		{
			percent->field.max = (percent->field.max * 10) + ((**format) - '0');
			(*format)++ ;
		}
	}
}

static void	ft_percent_identifier(t_percent *percent, char **format)
{
	if (ft_isformat(**format))
		percent->format = **format ;
	(*format)++ ;
}

static t_field	ft_field_init(void)
{
	t_field	field ;

	field.min = 0 ;
	field.period = false ;
	field.max = 0 ;
	return (field);
}

t_percent	ft_percent_init(char **format, va_list args)
{
	t_percent	percent ;

	percent.minus = false ;
	percent.zero = false ;
	percent.plus = false ;
	percent.blank = false ;
	percent.hashtag = false ;
	percent.field = ft_field_init();
	percent.format = 0 ;
	ft_percent_flag(&percent, format);
	ft_percent_field(&percent, format, args);
	ft_percent_identifier(&percent, format);
	return (percent);
}

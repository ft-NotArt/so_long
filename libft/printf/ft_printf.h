/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:21:16 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/12 20:28:23 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Includes

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

// <|===|> Maxi printf <|===|>

/**
 * @name printf
 * @param format The string to write in the standard output,
 * in which to format variables
 * @param ... As much arguments as wanted,
 * those variables are inserted in the written string (with %)
 * or used as field width / precision values (with *)
 * @return Returns how many characters were written.
 * If NULL was given as format, returns -1.
 * If write fails (ex : writting in a file where it can't), returns -2
 * @author NotArt
 */
int			ft_printf(const char *format, ...);

// Structure

typedef struct s_field
{
	int		min;
	bool	period;
	int		max;
}					t_field;

typedef struct s_percent
{
	bool			minus;
	bool			zero;
	bool			plus;
	bool			blank;
	bool			hashtag;
	t_field			field;
	unsigned char	format;
}					t_percent;

t_percent	ft_percent_init(char **format, va_list args);

// Utils

bool		ft_isflag(int c);
bool		ft_isformat(int c);

// Format handling

int			ft_printf_format(va_list args, t_percent *percent);
int			ft_id_c(va_list args);
int			ft_id_s(va_list args);
int			ft_id_d(va_list args);
int			ft_id_u(va_list args);
int			ft_id_x(va_list args);
int			ft_id_xx(va_list args);
int			ft_id_p(va_list args);
int			ft_id_percent(va_list args);

int			ft_field_char(va_list args, t_percent *percent);
int			ft_field_str(va_list args, t_percent *percent);
int			ft_field_int(va_list args, t_percent *percent);
int			ft_field_uint(va_list args, t_percent *percent);
int			ft_field_hex(va_list args, t_percent *percent);
int			ft_field_address(va_list args, t_percent *percent);

int			ft_write_field(t_percent *percent);
int			ft_write_sign(int nb, t_percent *percent);
int			ft_write_0x(t_percent *percent);

#endif
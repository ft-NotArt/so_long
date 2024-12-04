/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlongnbr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 23:20:13 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/12 19:56:38 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putlongnbr_fd(long long n, int fd)
{
	int	written ;

	written = 0 ;
	if (n == LLONG_MIN)
		return (ft_putstr_fd("-9223372036854775808", fd));
	else
	{
		if (n < 0)
		{
			written += ft_putchar_fd('-', fd);
			n = -n;
		}
		if (n > 9)
			written += ft_putlongnbr_fd((n / 10), fd);
		return (written + ft_putchar_fd(((n % 10) + '0'), fd));
	}
}

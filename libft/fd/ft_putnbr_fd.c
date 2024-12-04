/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:08:09 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/12 19:57:08 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	written ;

	written = 0 ;
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	else
	{
		if (n < 0)
		{
			written += ft_putchar_fd('-', fd);
			n = -n;
		}
		if (n > 9)
			written += ft_putnbr_fd((n / 10), fd);
		return (written + ft_putchar_fd(((n % 10) + '0'), fd));
	}
}

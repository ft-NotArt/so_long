/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnbr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:15:05 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/12 19:56:05 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthexnbr_fd(unsigned long n, int fd, char hex_case)
{
	char	*base ;
	int		written ;

	written = 0 ;
	base = "0123456789abcdef" ;
	if (hex_case == MAJ)
		base = "0123456789ABCDEF" ;
	if (n > 15)
		written += ft_puthexnbr_fd((n / 16), fd, hex_case);
	return (written + ft_putchar_fd((base[n % 16]), fd));
}

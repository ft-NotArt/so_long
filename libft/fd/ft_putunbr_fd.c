/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:56:43 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/12 19:57:30 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	written ;

	written = 0 ;
	if (n > 9)
		written += ft_putunbr_fd((n / 10), fd);
	return (written + ft_putchar_fd(((n % 10) + '0'), fd));
}

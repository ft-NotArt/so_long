/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 05:12:48 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/12 07:48:17 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	rand_uchar(void)
{
	int				fd ;
	unsigned char	c[1];

	fd = open("/dev/random", O_RDONLY);
	if (fd == -1)
		return (1);
	if (read(fd, c, 1) != 1)
		c[0] = 1 ;
	close(fd);
	return (c[0]);
}

int	rand_int(void)
{
	int				res ;
	int				fd ;

	fd = open("/dev/random", O_RDONLY);
	if (fd == -1)
		return (1);
	if (read(fd, &res, sizeof(int)) != sizeof(int))
		res = 1 ;
	close(fd);
	return (res);
}

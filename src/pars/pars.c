/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_pars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:08:29 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/05 01:25:34 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_ber(int argc, char *argv[])
{
	while (--argc > 0)
	{
		if (ft_strcmp(".ber", argv[argc] + (ft_strlen(argv[argc]) - 4)))
			return (false);
	}
	return (true);
}

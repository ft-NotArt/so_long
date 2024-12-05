/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:25:03 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/05 02:19:59 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_arguments()
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(strerror(EINVAL), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	error_map()
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("Invalid Map\n", STDERR_FILENO);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:25:03 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/16 00:04:35 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_arguments(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(strerror(EINVAL), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	error_map(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("Invalid Map\n", STDERR_FILENO);
}

void	error_mlx(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd((char *) mlx_strerror(mlx_errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

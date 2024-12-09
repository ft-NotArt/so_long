/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:25:03 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/09 23:49:49 by anoteris         ###   ########.fr       */
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

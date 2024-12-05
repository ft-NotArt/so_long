/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_str_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 01:05:49 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/05 01:06:22 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_str_array(char **to_free)
{
	int	i ;

	i = -1 ;
	while (to_free && to_free[++i])
		free(to_free[i]);
	free(to_free);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_attack_get.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 04:33:06 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/17 02:06:49 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_image_t	*get_mlx_knife(t_game *game, t_attack *attack)
{
	mlx_image_t	*img ;
	char		sprite_file[100];

	ft_strlcpy(sprite_file, ATTACKS, ft_strlen(ATTACKS) + 1);
	ft_strlcat(sprite_file, KNIFE,
		ft_strlen(sprite_file) + ft_strlen(KNIFE) + 1);
	ft_strlcat(sprite_file, "_", ft_strlen(sprite_file) + 2);
	add_orient(attack->orient, sprite_file);
	ft_strlcat(sprite_file, PNG, ft_strlen(sprite_file) + ft_strlen(PNG) + 1);
	img = get_mlx_img(game, sprite_file);
	return (img);
}

static mlx_image_t	*get_mlx_magic_beam(t_game *game, t_attack *attack)
{
	mlx_image_t	*img ;
	char		sprite_file[100];
	char		*frame_number ;

	ft_strlcpy(sprite_file, ATTACKS, ft_strlen(ATTACKS) + 1);
	ft_strlcat(sprite_file, MAGIC_BEAM,
		ft_strlen(sprite_file) + ft_strlen(MAGIC_BEAM) + 1);
	ft_strlcat(sprite_file, "_", ft_strlen(sprite_file) + 2);
	add_orient(attack->orient, sprite_file);
	ft_strlcat(sprite_file, "_", ft_strlen(sprite_file) + 2);
	frame_number = ft_itoa(attack->frame);
	ft_strlcat(sprite_file, frame_number, ft_strlen(sprite_file) + 2);
	free(frame_number);
	ft_strlcat(sprite_file, PNG, ft_strlen(sprite_file) + ft_strlen(PNG) + 1);
	img = get_mlx_img(game, sprite_file);
	return (img);
}

mlx_image_t	*get_mlx_attack(t_game *game, t_attack *attack)
{
	if (attack->type == DEE)
		return (get_mlx_knife(game, attack));
	else
		return (get_mlx_magic_beam(game, attack));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 06:30:45 by arigonza          #+#    #+#             */
/*   Updated: 2023/10/10 16:51:26 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_map(t_game *game)
{
    int			x;
	int			y;
	mlx_image_t	*img;

	while (game->map[y])
	{
		while (game->map[x][y])
		{
			mlx_image_to_window(game->mlx, mlx_texture_to_image(game->mlx, game->textures->floor), x * 32, y * 32);
			if (game->map[x][y] == WALL)
				mlx_image_to_window(game->mlx, game->textures->wall, x * 32, y * 32);
			if (game->map[x][y] == COLLECT_ITEM)
				mlx_image_to_window(game->mlx, game->textures->collect_item, x * 32, y * 32);
			if (game->map[x][y] == PLAYER)
				mlx_image_to_window(game->mlx, game->textures->player, x * 32, y * 32);
			if (game->map[x][y] == EXIT)
				mlx_image_to_window(game->mlx, game->textures->exit, x * 32, y * 32);
			x++;
		}
		x = 0;
		y++;
	}
}
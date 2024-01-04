/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:32:59 by arigonza          #+#    #+#             */
/*   Updated: 2024/01/04 18:47:12 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_render_map_bonus(t_game *game)
{
    int         x;
	int			y;

	game->player->c_counter = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_image_to_window(game->mlx, game->textures->floor, x * 32, y * 32);
			if (game->map[y][x] == WALL)
				mlx_image_to_window(game->mlx, game->textures->wall, x * 32, y * 32);
			if (game->map[y][x] == COLLECT_ITEM)
			{
				mlx_image_to_window(game->mlx, game->textures->collect_item, x * 32, y * 32);
				game->player->c_counter++;
			}
			if (game->map[y][x] == EXIT)
			{
				mlx_image_to_window(game->mlx, game->textures->exit_open, x * 32, y * 32);
				mlx_image_to_window(game->mlx, game->textures->exit, x * 32, y * 32);
			}
			if (game->map[y][x] == ENEMY)
				mlx_image_to_window(game->mlx, game->textures->enemy, x * 32, y * 32);
			x++;
		}
		y++;
	}
	game->total_c = game->player->c_counter;
}

void	ft_dead(t_game *game, int current_y, int current_x)
{
	char	**map;

	map = game->map;
	if (map[current_y][current_x] == ENEMY)
	{
		ft_free_all_b(game);
		mlx_close_window(game->mlx);
	}
}

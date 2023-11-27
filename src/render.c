/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 06:30:45 by arigonza          #+#    #+#             */
/*   Updated: 2023/11/18 23:11:08 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_render_map(t_game *game)
{
    int			x;
	int			y;

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
				mlx_image_to_window(game->mlx, game->textures->exit, x * 32, y * 32);
			x++;
		}
		y++;
	}
	game->total_c = game->player->c_counter;
}

void	ft_render_player(t_game *game)
{
	int	curr_y;
	int	curr_x;

	curr_y = game->player->y;
	curr_x = game->player->x;
	while (game->map[curr_y])
	{
		curr_x = 0;
		while (game->map[curr_y][curr_x])
		{
			if (game->map[curr_y][curr_x] == PLAYER)
				mlx_image_to_window(game->mlx, game->textures->player, curr_x * 32, curr_y * 32);
			curr_x++;
		}
		curr_y++;
	}
}

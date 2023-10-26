/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 06:30:45 by arigonza          #+#    #+#             */
/*   Updated: 2023/10/26 00:25:48 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_render_map(t_game *game)
{
    int			x;
	int			y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			mlx_image_to_window(game->mlx, game->textures->floor, x * 32, y * 32);
			if (game->map[y][x] == WALL)
				mlx_image_to_window(game->mlx, game->textures->wall, x * 32, y * 32);
			if (game->map[y][x] == COLLECT_ITEM)
				mlx_image_to_window(game->mlx, game->textures->collect_item, x * 32, y * 32);
			if (game->map[y][x] == PLAYER)
				mlx_image_to_window(game->mlx, game->textures->player, x * 32, y * 32);
			if (game->map[y][x] == EXIT)
				mlx_image_to_window(game->mlx, game->textures->exit, x * 32, y * 32);
			x++;
		}
		x = 0;
		y++;
	}
}


void	ft_render_animation(void *param)
{
	t_game	*game;
	t_node	*current;
	
	game = param;
	current = game->player->animation->head;
	while (current)
	{
		mlx_image_to_window(game->mlx, current->img, 32, 32);
		current = current->next;
	}
}
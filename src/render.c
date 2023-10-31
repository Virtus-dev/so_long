/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 06:30:45 by arigonza          #+#    #+#             */
/*   Updated: 2023/10/30 15:45:11 by arigonza         ###   ########.fr       */
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

void	ft_open_window(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "so_long", false);

	mlx_loop(game->mlx);
	
}
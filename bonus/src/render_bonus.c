/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:32:59 by arigonza          #+#    #+#             */
/*   Updated: 2024/01/14 16:39:03 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_render_map_bonus(t_game *game)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	game->player->c_counter = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_image_to_window(game->mlx,
				game->textures->floor, x * 32, y * 32);
			if (game->map[y][x] == WALL)
				mlx_image_to_window(game->mlx,
					game->textures->wall, x * 32, y * 32);
			ft_check_exit_enemy(game, y, x);
			x++;
		}
		y++;
	}
	game->total_c = game->player->c_counter;
	while (i < game->textures->enemy_c)
		game->textures->enemy_an->instances[i++].enabled = 0;
}

void	ft_check_exit_enemy(t_game *game, int y, int x)
{
	if (game->map[y][x] == COLLECT_ITEM)
	{
		mlx_image_to_window(game->mlx,
			game->textures->collect_item, x * 32, y * 32);
		game->player->c_counter++;
	}
	if (game->map[y][x] == EXIT)
	{
		mlx_image_to_window(game->mlx,
			game->textures->exit_open, x * 32, y * 32);
		mlx_image_to_window(game->mlx, game->textures->exit, x * 32, y * 32);
	}
	if (game->map[y][x] == ENEMY)
	{
		mlx_image_to_window(game->mlx, game->textures->enemy, x * 32, y * 32);
		mlx_image_to_window(game->mlx,
			game->textures->enemy_an, x * 32, y * 32);
		game->textures->enemy_c++;
	}
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

void	ft_render_player_b(t_game *game)
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
			{
				mlx_image_to_window(game->mlx, game->textures->player,
					curr_x * 32, curr_y * 32);
				game->player->x = curr_x;
				game->player->y = curr_y;
			}
			curr_x++;
		}
		curr_y++;
	}
}

void	ft_get_citem_b(t_game *game)
{
	int	i;

	i = 0;
	while (i <= game->total_c)
	{
		if (game->textures->collect_item->instances[i].y
			== game->textures->player->instances[0].y
			&& game->textures->collect_item->instances[i].x
			== game->textures->player->instances[0].x)
		{
			ft_printf("GOLD!\n");
			game->textures->collect_item->instances[i].enabled = 0;
		}
		i++;
	}
}

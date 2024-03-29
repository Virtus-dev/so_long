/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ply_moves_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:32:55 by arigonza          #+#    #+#             */
/*   Updated: 2024/01/14 16:04:38 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_controls_bonus(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		ft_up_b(game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		ft_down_b(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		ft_left_b(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		ft_right_b(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
	{
		ft_free_all_b(game);
		mlx_close_window(game->mlx);
	}
	if (game->player->c_counter == 0)
		ft_door_open(game);
}

void	ft_up_b(t_game *game)
{
	int		currnt_y;
	int		currnt_x;
	char	**map;

	currnt_y = game->textures->player->instances[0].y / 32;
	currnt_x = game->textures->player->instances[0].x / 32;
	map = game->map;
	if (map[currnt_y -1][currnt_x] == WALL
	|| (map[currnt_y -1][currnt_x] == EXIT
	&& !ft_win_bonus(game, currnt_y - 1, currnt_x)))
		return ;
	game->textures->player->instances[0].y -= 32;
	if (map[currnt_y - 1][currnt_x] == COLLECT_ITEM)
	{
		game->player->c_counter--;
		ft_get_citem_b(game);
	}
	ft_dead(game, currnt_y - 1, currnt_x);
	game->map[currnt_y][currnt_x] = '0';
	game->map[currnt_y - 1][currnt_x] = PLAYER;
	game->player->y--;
	game->moves++;
	ft_score(game);
	ft_enemy_animation(game);
}

void	ft_down_b(t_game *game)
{
	int		currnt_y;
	int		currnt_x;
	char	**map;

	currnt_y = game->textures->player->instances[0].y / 32;
	currnt_x = game->textures->player->instances[0].x / 32;
	map = game->map;
	if (map[currnt_y + 1][currnt_x] == WALL
	|| (map[currnt_y + 1][currnt_x] == EXIT
	&& !ft_win_bonus(game, currnt_y + 1, currnt_x)))
		return ;
	game->textures->player->instances[0].y += 32;
	if (map[currnt_y + 1][currnt_x] == COLLECT_ITEM)
	{
		game->player->c_counter--;
		ft_get_citem_b(game);
	}
	ft_dead(game, currnt_y + 1, currnt_x);
	game->map[currnt_y][currnt_x] = '0';
	game->map[currnt_y + 1][currnt_x] = PLAYER;
	game->player->y++;
	game->moves++;
	ft_score(game);
	ft_enemy_animation(game);
}

void	ft_left_b(t_game *game)
{
	int		currnt_y;
	int		currnt_x;
	char	**map;

	currnt_y = game->textures->player->instances[0].y / 32;
	currnt_x = game->textures->player->instances[0].x / 32;
	map = game->map;
	if (map[currnt_y][currnt_x - 1] == WALL
	|| (map[currnt_y][currnt_x - 1] == EXIT
	&& !ft_win_bonus(game, currnt_y, currnt_x -1)))
		return ;
	game->textures->player->instances[0].x -= 32;
	if (map[currnt_y][currnt_x - 1] == COLLECT_ITEM)
	{
		game->player->c_counter--;
		ft_get_citem_b(game);
	}
	ft_dead(game, currnt_y, currnt_x - 1);
	game->map[currnt_y][currnt_x] = '0';
	game->map[currnt_y][currnt_x - 1] = PLAYER;
	game->player->x--;
	game->moves++;
	ft_score(game);
	ft_enemy_animation(game);
}

void	ft_right_b(t_game *game)
{
	int		currnt_y;
	int		currnt_x;
	char	**map;

	currnt_y = game->textures->player->instances[0].y / 32;
	currnt_x = game->textures->player->instances[0].x / 32;
	map = game->map;
	if (map[currnt_y][currnt_x + 1] == WALL
		|| (map[currnt_y][currnt_x + 1]
		== EXIT && !ft_win_bonus(game, currnt_y, currnt_x + 1)))
		return ;
	game->textures->player->instances[0].x += 32;
	if (map[currnt_y][currnt_x + 1] == COLLECT_ITEM)
	{
		game->player->c_counter--;
		ft_get_citem_b(game);
	}
	ft_dead(game, currnt_y, currnt_x + 1);
	game->map[currnt_y][currnt_x] = '0';
	game->map[currnt_y][currnt_x + 1] = PLAYER;
	game->player->x++;
	game->moves++;
	ft_score(game);
	ft_enemy_animation(game);
}

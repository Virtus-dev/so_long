/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ply_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 23:22:10 by arigonza          #+#    #+#             */
/*   Updated: 2023/11/18 22:00:50 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_controls(mlx_key_data_t keydata, void *param)
{
    t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		ft_up(game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		ft_down(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		ft_left(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		ft_right(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
	{
		ft_free_all(game);
		mlx_close_window(game->mlx);
	}
}

void	ft_up(t_game *game)
{
	int		currnt_y;
	int		currnt_x;
	char	**map;

	currnt_y = game->player->y;
	currnt_x = game->player->x;
	map = game->map;
	if (map[currnt_y -1][currnt_x] == WALL || (map[currnt_y -1][currnt_x] == EXIT && !ft_win(game, currnt_y - 1, currnt_x)))
	 	return ;
	// TODO Introduce the player image instance and move it -32px on the Y axis.
	game->textures->player->instances[0].y -= 32;
	if (map[currnt_y - 1][currnt_x] == COLLECT_ITEM)
	{
		game->player->c_counter--;
		ft_get_citem(game);
	}
	game->map[currnt_y][currnt_x] = '0';
	game->map[currnt_y - 1][currnt_x] = PLAYER;
	game->player->y--;
	game->moves++;
	ft_score(game);
	ft_printf("moves: %d\n", game->moves);
}

void	ft_down(t_game *game)
{
	int		currnt_y;
	int		currnt_x;
	char	**map;

	currnt_y = game->player->y;
	currnt_x = game->player->x;
	map = game->map;
	if (map[currnt_y + 1][currnt_x] == WALL || (map[currnt_y + 1][currnt_x] == EXIT && !ft_win(game, currnt_y + 1, currnt_x)))
	 	return ;
	// TODO Introduce the player image instance and move it +32px on the Y axis.
	game->textures->player->instances[0].y += 32;
	if (map[currnt_y + 1][currnt_x] == COLLECT_ITEM)
	{
		game->player->c_counter--;
		ft_get_citem(game);
	}
	game->map[currnt_y][currnt_x] = '0';
	game->map[currnt_y + 1][currnt_x] = PLAYER;
	game->player->y++;
	game->moves++;
	ft_score(game);
	ft_printf("moves: %d\n", game->moves);
}

void	ft_left(t_game *game)
{
	int		currnt_y;
	int		currnt_x;
	char	**map;

	currnt_y = game->player->y;
	currnt_x = game->player->x;
	map = game->map;
	if (map[currnt_y][currnt_x - 1] == WALL || (map[currnt_y][currnt_x - 1] == EXIT && !ft_win(game, currnt_y, currnt_x -1)))
	 	return ;
	// TODO Introduce the player image instance and move it -32px on the X axis.
	game->textures->player->instances[0].x -= 32;
	if (map[currnt_y][currnt_x - 1] == COLLECT_ITEM)
	{
		game->player->c_counter--;
		ft_get_citem(game);
	}
	game->map[currnt_y][currnt_x] = '0';
	game->map[currnt_y][currnt_x - 1] = PLAYER;
	game->player->x--;
	game->moves++;
	ft_score(game);
	ft_printf("moves: %d\n", game->moves);
}

void	ft_right(t_game *game)
{
	int		currnt_y;
	int		currnt_x;
	char	**map;

	currnt_y = game->player->y;
	currnt_x = game->player->x;
	map = game->map;
	if (map[currnt_y][currnt_x + 1] == WALL || (map[currnt_y][currnt_x + 1] == EXIT && !ft_win(game, currnt_y, currnt_x +1)))
	 	return ;
	// TODO Introduce the player image instance and move it +32px on the X axis.
	game->textures->player->instances[0].x += 32;
	if (map[currnt_y][currnt_x + 1] == COLLECT_ITEM)
	{
		game->player->c_counter--;
		ft_get_citem(game);
	}
	game->map[currnt_y][currnt_x] = '0';
	game->map[currnt_y][currnt_x + 1] = PLAYER;
	game->player->x++;
	game->moves++;
	ft_score(game);
	ft_printf("moves: %d\n", game->moves);
}
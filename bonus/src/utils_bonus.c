/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:52:31 by arigonza          #+#    #+#             */
/*   Updated: 2024/01/09 16:16:46 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_load_textures_bonus(t_game *game)
{
	mlx_texture_t	*exit_open;
	mlx_texture_t	*enemy;

	ft_load_basic_textures(game);
	exit_open = mlx_load_png("textures/door_open.png");
	enemy = mlx_load_png("textures/Pumpkin2.png");
	game->textures->exit_open = mlx_texture_to_image(game->mlx, exit_open);
	game->textures->enemy = mlx_texture_to_image(game->mlx, enemy);
	mlx_delete_texture(exit_open);
	mlx_delete_texture(enemy);
}

void	ft_load_basic_textures(t_game *game)
{
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*exit;
	mlx_texture_t	*coll;
	mlx_texture_t	*ply;

	wall = mlx_load_png("textures/wall.png");
	floor = mlx_load_png("textures/floor.png");
	coll = mlx_load_png("textures/collect_item.png");
	ply = mlx_load_png("textures/ply_right.png");
	exit = mlx_load_png("textures/door.png");
	game->textures->wall = mlx_texture_to_image(game->mlx, wall);
	game->textures->floor = mlx_texture_to_image(game->mlx, floor);
	game->textures->collect_item = mlx_texture_to_image(game->mlx, coll);
	game->textures->player = mlx_texture_to_image(game->mlx, ply);
	game->textures->exit = mlx_texture_to_image(game->mlx, exit);
	mlx_delete_texture(wall);
	mlx_delete_texture(floor);
	mlx_delete_texture(ply);
	mlx_delete_texture(coll);
	mlx_delete_texture(exit);
}

void	ft_free_all_b(t_game *game)
{
	mlx_delete_image(game->mlx, game->textures->wall);
	mlx_delete_image(game->mlx, game->textures->collect_item);
	mlx_delete_image(game->mlx, game->textures->exit);
	mlx_delete_image(game->mlx, game->textures->player);
	mlx_delete_image(game->mlx, game->textures->floor);
	mlx_delete_image(game->mlx, game->textures->exit_open);
	mlx_delete_image(game->mlx, game->textures->enemy);
	ft_free_map(game->map);
}

t_game	*ft_game_init_bonus(char *argv)
{
	t_game		*game;
	t_player	*player;
	int			fd;

	fd = open(argv, O_RDONLY);
	game = (t_game *)malloc(sizeof(t_game));
	ft_read_map(game, fd);
	close(fd);
	player = (t_player *)malloc(sizeof(t_player));
	player->x = 0;
	player->y = 0;
	player->c_counter = 0;
	game->moves = 0;
	game->mlx = NULL;
	game->player = player;
	game->textures = (t_texture *)malloc(sizeof(t_texture));
	return (game);
}

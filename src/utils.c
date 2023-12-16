/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 07:18:05 by arigonza          #+#    #+#             */
/*   Updated: 2023/12/16 15:11:12 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error(char *error)
{
	ft_printf(error);
	exit(EXIT_FAILURE);
}

void	ft_load_textures(t_game *game)
{
	t_texture		*textures;
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*exit;
	mlx_texture_t	*exit_open;
	mlx_texture_t	*coll;
	mlx_texture_t	*ply;
	
	wall = mlx_load_png("textures/wall.png");
	floor = mlx_load_png("textures/floor.png");
	coll = mlx_load_png("textures/collect_item.png");
	ply = mlx_load_png("textures/ply_right.png");
	exit = mlx_load_png("textures/door.png");
	exit_open = mlx_load_png("textures/door_open.png");
	
	textures = (t_texture*)malloc(sizeof(t_texture));
	textures->wall = mlx_texture_to_image(game->mlx, wall);
	textures->floor = mlx_texture_to_image(game->mlx, floor);
	textures->collect_item = mlx_texture_to_image(game->mlx, coll);
	textures->player = mlx_texture_to_image(game->mlx, ply);
	textures->exit = mlx_texture_to_image(game->mlx, exit);
	textures->exit_open = mlx_texture_to_image(game->mlx, exit_open);
	game->textures = textures;
	
	mlx_delete_texture(wall);
	mlx_delete_texture(floor);
	mlx_delete_texture(ply);
	mlx_delete_texture(coll);
	mlx_delete_texture(exit);
	mlx_delete_texture(exit_open);
}

t_game	*ft_game_init(char *argv)
{
	t_game		*game;
	t_player	*player;
	int			fd;

	fd = open(argv, O_RDONLY);
	game = (t_game *)malloc(sizeof(t_game));
	ft_read_map(game, fd);
	close(fd);
	player = (t_player*)malloc(sizeof(t_player));
	player->x = 0;
	player->y = 0;
	player->c_counter = 0;
	game->moves = 0;
	game->mlx = NULL;
	game->player = player;
	game->textures = NULL;
	return (game);
}

void	ft_get_citem(t_game *game)
{
	int	i;

	i = 0;
	while (i <= game->total_c)
	{
		if (game->textures->collect_item->instances[i].y == game->textures->player->instances[0].y &&
			game->textures->collect_item->instances[i].x == game->textures->player->instances[0].x)
		{
			ft_printf("GOLD!\n");
			game->textures->collect_item->instances[i].enabled = 0;
		}
		i++;
	}
}

void	ft_free_all(t_game *game)
{
	mlx_delete_image(game->mlx, game->textures->wall);
	mlx_delete_image(game->mlx, game->textures->collect_item);
	mlx_delete_image(game->mlx, game->textures->exit);
	mlx_delete_image(game->mlx, game->textures->player);
	mlx_delete_image(game->mlx, game->textures->floor);
	ft_free_map(game->map);
}

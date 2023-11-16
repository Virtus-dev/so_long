/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 07:18:05 by arigonza          #+#    #+#             */
/*   Updated: 2023/11/16 20:14:57 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void error(char *error)
{
	//puts(mlx_strerror(mlx_errno));
	ft_printf(error);
	exit(EXIT_FAILURE);
}

void	ft_load_textures(t_game *game)
{
	t_texture	*textures;
	
	textures = (t_texture*)malloc(sizeof(t_texture));
	textures->wall = mlx_texture_to_image(game->mlx, mlx_load_png("textures/wall.png"));
	textures->floor = mlx_texture_to_image(game->mlx, mlx_load_png("textures/floor.png"));
	textures->collect_item = mlx_texture_to_image(game->mlx, mlx_load_png("textures/collect_item.png"));
	textures->player = mlx_texture_to_image(game->mlx, mlx_load_png("textures/ply_right.png"));
	textures->exit = mlx_texture_to_image(game->mlx, mlx_load_png("textures/door.png"));
	game->textures = textures;
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
	player->animation = NULL;
	player->x = 0;
	player->y = 0;
	game->mlx = NULL;
	game->player = player;
	game->textures = NULL;

	return (game);
}

void	ft_get_citem(t_game *game)
{
    int		i;

	i = 0;
	while (i <= game->total_c)
	{
		if (game->textures->collect_item->instances[i].y == game->textures->player->instances[0].y &&
			game->textures->collect_item->instances[i].x == game->textures->player->instances[0].x)
		{
			ft_printf("");
			game->textures->collect_item->instances[i].enabled = 0;
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 07:18:05 by arigonza          #+#    #+#             */
/*   Updated: 2023/10/27 20:16:03 by arigonza         ###   ########.fr       */
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
	textures->wall = mlx_texture_to_image(game->mlx, mlx_load_png("textures/tree.png"));
	textures->floor = mlx_texture_to_image(game->mlx, mlx_load_png("textures/grass.png"));
	textures->collect_item = mlx_texture_to_image(game->mlx, mlx_load_png("textures/rock2.png"));
	textures->player = mlx_texture_to_image(game->mlx, mlx_load_png("textures/player.png"));
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

char	**ft_cpymap(char **map)
{
	char	**map_cpy;
	int		x_size;
	int		y;
	int		x;

	x_size = (int)ft_strlen(map[0]);
	map_cpy = (char**)malloc(((int)ft_map_height(map) + 1) * sizeof(char*));
	if (!map_cpy)
	{
		free(map_cpy);
		error(MAPCPY_ERROR);
	}
	y = 0;
	while (map[y])
	{
		x = 0;
		map_cpy[y] = (char*)malloc(x_size * sizeof(char));
		if (!map_cpy)
			error(MAPCPY_ERROR);
		while (map[y][x])
		{
			map_cpy[y][x] = map[y][x];
			x++;
		}
		y++;
	}
	return (map_cpy);
}

size_t	ft_map_height(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
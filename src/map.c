/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 02:29:12 by arigonza          #+#    #+#             */
/*   Updated: 2024/01/14 13:29:26 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * @brief Reads the map from a file descriptor and
 * saves it on the game->map property.
 * @param game Struct that holds all the game related information.
 * @param fd file descriptor from wich to read.
 * @return int number of rows from the map readed.
 */
int	ft_read_map(t_game *game, int fd)
{
	char	*line;
	char	*tmp;
	int		num_rows;

	num_rows = 0;
	line = get_next_line(fd);
	tmp = NULL;
	if (!line)
		return (error(READING_ERROR), free(line), 0);
	while (line)
	{
		tmp = ft_strjoin_gnl(tmp, line);
		free(line);
		line = get_next_line(fd);
		num_rows++;
	}
	if (tmp[0] == '\n')
		error(MAP_ERROR);
	game->map = ft_split(tmp, '\n');
	return (free(line), free(tmp), num_rows);
}

/**
 * @brief Checks if the map is surrounded by walls 
 * and also if there's any gap into.
 * 
 * @param map The map to check.
 */
void	ft_check_walls(t_game *game, size_t y_size, size_t x_size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != x_size)
			error(MAP_ERROR);
		while (game->map[i][j])
		{
			if (game->map[0][j] != WALL)
				error(MAP_ERROR);
			if (game->map[y_size - 1][j] != WALL)
				error(MAP_ERROR);
			if (game->map[i][0] != WALL)
				error(MAP_ERROR);
			if (game->map[i][x_size - 1] != WALL)
				error(MAP_ERROR);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_check_elements(char **map)
{
	int	y;
	int	x;
	int	ply;
	int	c;
	int	exits;

	ply = 0;
	c = 0;
	exits = 0;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == PLAYER)
				ply++;
			if (map[y][x] == COLLECT_ITEM)
				c++;
			if (map[y][x] == EXIT)
				exits++;
		}
	}
	if (ply != 1 || c < 1 || exits != 1)
		error(MAP_ERROR);
}

/**
 * @brief Checks for a valid path looking for the 'F' in the map,
 *  if there's any 'C' or 'E' in there, it means they'r surrounded by walls,
 *  so the player can't reach them.
 * 
 * @param map 
 */
void	ft_check_valid_path(char **map)
{
	int	y;
	int	x;

	y = 0;
	if (!map)
		error("No map to check a valid path");
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == EXIT || map[y][x] == COLLECT_ITEM)
				error(NON_VALID_PATH);
			x++;
		}
		y++;
	}
}

// Checks if the map is or is not valid.
void	ft_check_map(t_game *game)
{
	char	**mapcpy;
	size_t	x_size;
	size_t	y_size;

	y_size = ft_map_height(game->map);
	x_size = (int)ft_strlen(game->map[0]);
	if (y_size >= x_size)
		error(MAP_ERROR);
	game->num_col = y_size;
	game->num_rows = x_size;
	mapcpy = ft_cpymap(game->map, (int)x_size);
	ft_check_walls(game, y_size, x_size);
	ft_check_elements(mapcpy);
	ft_set_ply_pos(game, mapcpy);
	ft_flood_fill(mapcpy, game->player->y, game->player->x);
	ft_check_valid_path(mapcpy);
	ft_check_micromap(game);
	ft_free_map(mapcpy);
}

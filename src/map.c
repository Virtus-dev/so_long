/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 02:29:12 by arigonza          #+#    #+#             */
/*   Updated: 2023/10/27 20:13:34 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../includes/so_long.h"

/**
 * @brief Reads the map from a file descriptor and saves it on the game->map property.
 * 
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
void	ft_check_walls(t_game *game)
{
	int	i;
	int	j;
	size_t	x_size;
	size_t	y_size;
	
	i = 0;
	j = 0;
	x_size = ft_strlen(game->map[0]);
	y_size = ft_map_height(game->map);
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
			if (game->map[i][j] == PLAYER)
			{
				game->player->x = j;
				game->player->y = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

/**
 * @brief Looks for the positions nearby and convert 'C' and 'E' into '0', and later on, into 'F'.
 * We'll use it later to find a valid path looking for the 'F' in the map.
 * 
 * @param map
 * @param y_position Y position of the player.
 * @param x_position X position of the player.
 */
void	ft_flood_fill(char **map, int y_position, int x_position)
{
	if (x_position < 0 || y_position < 0 ||
		map[y_position][x_position] == WALL || map[y_position][x_position] == 'F')
		return ;
	if (map[y_position][x_position] == EXIT || map[y_position][x_position] == COLLECT_ITEM)
		map[y_position][x_position] = '0';
		
	map[y_position][x_position] = 'F';
	ft_flood_fill(map, y_position + 1, x_position);
	ft_flood_fill(map, y_position - 1, x_position);
	ft_flood_fill(map, y_position, x_position + 1);
	ft_flood_fill(map, y_position, x_position - 1);
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
	ft_printf("In check_valid_path.\n");
	y = 0;
	x = 0;
	if (!map)
		error("Invalid map");
	while (map[y])
	{
		x = 0;
		//ft_printf("In check_valid_path map[%d][%d]-> %c.\n", y, x, map[y][x]);
		while (map[y][x])
		{
			ft_printf("%c", map[y][x]);
			if (map[y][x] == 'E' || map[y][x] == 'C')
				error(NON_VALID_PATH);
			x++;
		}
		ft_printf("\n");
		y++;
	}
	ft_printf("outside loop.\n");
}

// Checks if the map is or is not valid.
void	ft_check_map(t_game *game)
{
	char	**mapcpy;

	mapcpy = ft_cpymap(game->map);
	ft_printf("Before check_walls function.\n");
	ft_check_walls(game);
	ft_printf("After check_walls function.\n");
	ft_flood_fill(mapcpy, game->player->y, game->player->x);
	ft_printf("After floodfill.\n");
	ft_check_valid_path(mapcpy);
}

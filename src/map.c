/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 02:29:12 by arigonza          #+#    #+#             */
/*   Updated: 2023/10/26 07:50:41 by arigonza         ###   ########.fr       */
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
		return (error(), free(line), 0);	
	while (line)
	{
		tmp = ft_strjoin_gnl(tmp, line);
		free(line);
		line = get_next_line(fd);
		num_rows++;
	}
	if (tmp[0] == '\n')
		error();
	game->map = ft_split(tmp, '\n');
	return (free(line), free(tmp), num_rows);
}

/**
 * @brief Checks that the number of rows are the same size to avoid non valid maps.
 * 
 * @param map Map to check the rows from.
 * @return int returns the size of the row.
 */
int	ft_row_check(char **map)
{
	size_t	size;
	int		y;
	
	size = ft_strlen(map[0]);
	y = 0;
	while (map[y])
	{
		if (ft_strlen(map[y]) != size)
			error();
		y++;
	}
	return ((int)size);
}

// TODO find another way to check if all the surrounders are walls
void	ft_check_walls(char **map)
{
	int	i;
	int	j;
	size_t	x_size;
	size_t	y_size;
	
	i = 0;
	j = 0;
	x_size = ft_strlen(map[0]);
	y_size = ft_map_height(map);
	while (map[i])
	{
		while (map[i][j])
		{		
			if (map[0][j] != WALL)
				error();
			if (map[y_size - 1][j] != WALL)
				error();
			if (map[i][0] != WALL)
				error();
			if (map[i][x_size - 1] != WALL)
				error();
			j++;
		}
		j = 0;
		i++;
	}
}

/**
 * @brief Looks for a valid path within the map.
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
 * @brief Checks if the map is or is not valid.
 * 
 * @param map The map to check.
 * @param x_size The size of the map in the x axis.
 * @param y_size The size of the map in the y axis.
 */
void	ft_check_map(char **map)
{
	ft_row_check(map);
	ft_check_walls(map);
	//ft_check_valid_path(map, y_size, x_size);
}

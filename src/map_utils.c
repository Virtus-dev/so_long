/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 12:24:01 by arigonza          #+#    #+#             */
/*   Updated: 2023/12/16 15:16:07 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**ft_cpymap(char **map, int x_size)
{
	char	**map_cpy;
	int		y;
	int		x;

	map_cpy = (char**)malloc(((int)ft_map_height(map) + 1) * sizeof(char*));
	if (!map_cpy)
		return (free(map_cpy), error(MAPCPY_ERROR), NULL);
	y = 0;
	while (map[y])
	{
		x = 0;
		map_cpy[y] = (char*)malloc(x_size * sizeof(char));
		if (!map_cpy[y])
			return (ft_free_map(map), NULL);
		while (map[y][x])
		{
			map_cpy[y][x] = map[y][x];
			x++;
		}
		map_cpy[y][x] = '\0';
		y++;
	}
	map_cpy[y] = NULL;
	return (map_cpy);
}

size_t	ft_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
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

void	ft_print_map(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			ft_printf("%c", map[y][x++]);
		ft_printf("\n");
		y++;
	}
}

void	ft_set_ply_pos(t_game *game, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == PLAYER)
			{
				game->player->x = x;
				game->player->y = y;
			}
			x++;
		}
		y++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:30:12 by arigonza          #+#    #+#             */
/*   Updated: 2024/01/14 16:38:22 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_win(t_game *game, int current_y, int current_x)
{
	char	**map;
	int		c_counter;

	map = game->map;
	c_counter = game->player->c_counter;
	if (map[current_y][current_x] == EXIT && c_counter == 0)
		return (ft_free_all(game), mlx_close_window(game->mlx), 1);
	return (0);
}

void	ft_check_micromap(t_game *game)
{
	int		y_pos;
	int		x_pos;

	y_pos = game->player->y;
	x_pos = game->player->x;
	if (game->map[y_pos][x_pos - 1] == WALL && game->map[y_pos][x_pos + 1]
		== WALL && game->map[y_pos - 1][x_pos] == WALL)
		if (game->map[y_pos + 1][x_pos] == EXIT
			&& game->map[y_pos + 2][x_pos] == COLLECT_ITEM)
			error(MAP_ERROR);
	if (game->map[y_pos][x_pos - 1] == WALL && game->map[y_pos][x_pos + 1]
		== WALL && game->map[y_pos + 1][x_pos] == WALL)
		if (game->map[y_pos - 1][x_pos] == EXIT
			&& game->map[y_pos - 2][x_pos] == COLLECT_ITEM)
			error(MAP_ERROR);
	if (game->map[y_pos - 1][x_pos] == WALL && game->map[y_pos + 1][x_pos]
		== WALL && game->map[y_pos][x_pos + 1] == WALL)
		if (game->map[y_pos][x_pos -1] == EXIT
			&& game->map[y_pos][x_pos -2] == COLLECT_ITEM)
			error(MAP_ERROR);
	if (game->map[y_pos - 1][x_pos] == WALL && game->map[y_pos + 1][x_pos]
		== WALL && game->map[y_pos][x_pos - 1] == WALL)
		if (game->map[y_pos][x_pos + 1] == EXIT
			&& game->map[y_pos][x_pos + 2] == COLLECT_ITEM)
			error(MAP_ERROR);
}

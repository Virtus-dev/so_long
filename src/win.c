/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:30:12 by arigonza          #+#    #+#             */
/*   Updated: 2023/10/30 16:14:48 by arigonza         ###   ########.fr       */
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
		return (mlx_close_window(game->mlx), 1);
	return (0);
}
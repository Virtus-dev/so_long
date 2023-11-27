/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:30:12 by arigonza          #+#    #+#             */
/*   Updated: 2023/11/27 20:56:34 by arigonza         ###   ########.fr       */
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

void	ft_score(t_game *game)
{
	char	*str;
	char	*str2;

	str2 = ft_itoa(game->moves);
	str = ft_strjoin("Moves: ", str2);
	mlx_delete_image(game->mlx, game->score);
	game->score = mlx_put_string(game->mlx, str, 10, 10);
	free(str);
	free(str2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:56:48 by arigonza          #+#    #+#             */
/*   Updated: 2023/12/16 14:25:51 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_win_bonus(t_game *game, int current_y, int current_x)
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

void	ft_door_open(t_game *game)
{
	int		y;
	int		x;
	char	**map;

	map = game->map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == EXIT)
			{
				game->textures->exit->instances[0].enabled = 0;
				game->textures->exit_open->instances[0].x = x;
				game->textures->exit_open->instances[0].y = y;
				game->textures->exit_open->instances[0].enabled = 1;
			}
			x++;
		}
		y++;
	}
}
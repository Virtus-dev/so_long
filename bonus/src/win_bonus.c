/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:56:48 by arigonza          #+#    #+#             */
/*   Updated: 2024/01/14 16:25:21 by arigonza         ###   ########.fr       */
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
		return (ft_free_all_b(game), mlx_close_window(game->mlx), 1);
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
	game->textures->exit->instances[0].enabled = 0;
	game->textures->exit_open->instances[0].enabled = 1;
}

void	ft_enemy_animation(t_game *game)
{
	int			e_counter;
	int			i;

	e_counter = game->textures->enemy_c;
	i = 0;
	if (game->textures->enemy->instances[0].enabled == 1)
	{
		while (i < e_counter)
		{
			game->textures->enemy->instances[i].enabled = 0;
			game->textures->enemy_an->instances[i].enabled = 1;
			i++;
		}
		i = 0;
	}
	else
	{
		while (i < e_counter)
		{
			game->textures->enemy->instances[i].enabled = 1;
			game->textures->enemy_an->instances[i].enabled = 0;
			i++;
		}
		i = 0;
	}
}

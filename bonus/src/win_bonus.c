/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:56:48 by arigonza          #+#    #+#             */
/*   Updated: 2023/11/27 20:56:52 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
				game->textures->exit->instances[0].x = x;
				game->textures->exit->instances[0].y = y;
				game->textures->exit_open->instances[0].enabled = 1;
			}
			x++;
		}
		y++;
	}
}
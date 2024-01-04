/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:52:31 by arigonza          #+#    #+#             */
/*   Updated: 2024/01/04 18:47:42 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_load_textures_bonus(t_game *game)
{
	mlx_texture_t	*exit_open;
	mlx_texture_t	*enemy;

	exit_open = mlx_load_png("textures/door_open.png");
	enemy = mlx_load_png("textures/crab_idle.png");
	game->textures->exit_open = mlx_texture_to_image(game->mlx, exit_open);
	game->textures->enemy = mlx_texture_to_image(game->mlx, enemy);
}

void	ft_free_all_b(t_game *game)
{
	mlx_delete_image(game->mlx, game->textures->wall);
	mlx_delete_image(game->mlx, game->textures->collect_item);
	mlx_delete_image(game->mlx, game->textures->exit);
	mlx_delete_image(game->mlx, game->textures->player);
	mlx_delete_image(game->mlx, game->textures->floor);
	mlx_delete_image(game->mlx, game->textures->exit_open);
	mlx_delete_image(game->mlx, game->textures->enemy);
	ft_free_map(game->map);
	free(game->textures);
}

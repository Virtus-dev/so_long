/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:52:31 by arigonza          #+#    #+#             */
/*   Updated: 2023/12/07 22:10:53 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/includes/so_long_bonus.h"

void	ft_load_textures(t_game *game)
{
	t_texture		*textures;
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*exit;
	mlx_texture_t	*exit_open;
	mlx_texture_t	*coll;
	mlx_texture_t	*ply;
	
	wall = mlx_load_png("textures/wall.png");
	floor = mlx_load_png("textures/floor.png");
	coll = mlx_load_png("textures/collect_item.png");
	ply = mlx_load_png("textures/ply_right.png");
	exit = mlx_load_png("textures/door.png");
	exit_open = mlx_load_png("textures/door_open.png");
	
	textures = (t_texture*)malloc(sizeof(t_texture));
	textures->wall = mlx_texture_to_image(game->mlx, wall);
	textures->floor = mlx_texture_to_image(game->mlx, floor);
	textures->collect_item = mlx_texture_to_image(game->mlx, coll);
	textures->player = mlx_texture_to_image(game->mlx, ply);
	textures->exit = mlx_texture_to_image(game->mlx, exit);
	textures->exit_open = mlx_texture_to_image(game->mlx, exit_open);
	game->textures = textures;
	
	mlx_delete_texture(wall);
	mlx_delete_texture(floor);
	mlx_delete_texture(ply);
	mlx_delete_texture(coll);
	mlx_delete_texture(exit);
	mlx_delete_texture(exit_open);
}

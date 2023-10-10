/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 07:18:05 by arigonza          #+#    #+#             */
/*   Updated: 2023/10/10 17:28:53 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	ft_load_textures(t_game *game)
{
	t_texture	*textures;
	
	textures = (t_texture*)malloc(sizeof(t_texture));
	textures->wall = mlx_texture_to_image(game->mlx, mlx_load_png("textures/tree.png"));
	textures->floor = mlx_texture_to_image(game->mlx, mlx_load_png("textures/grass.png"));
	//textures->collect_item = mlx_texture_to_image(game->mlx, mlx_load_png("textures/.png"));
	textures->player = mlx_texture_to_image(game->mlx, mlx_load_png("textures/iddle_0.png"));
	textures->exit = mlx_texture_to_image(game->mlx, mlx_load_png("textures/door.png"));
	game->textures = textures;
}

t_game	*ft_game_init(void)
{
	t_game	*game;
	
	game = (t_game *)malloc(sizeof(t_game));
	game->map = NULL;
	game->mlx = NULL;
	game->player = NULL;
	game->textures = NULL;

	return (game);
}
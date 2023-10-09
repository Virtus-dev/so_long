/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 07:18:05 by arigonza          #+#    #+#             */
/*   Updated: 2023/10/06 12:20:36 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	ft_load_textures(t_game *game)
{
	game->textures->wall = mlx_load_png("../textures/tree.png");
	game->textures->floor = mlx_load_png("../textures/grass.png");
	game->textures->collect_item = mlx_load_png("../textures/.png");
	game->textures->player = mlx_load_png("../textures/iddle_0.png");
	game->textures->exit = mlx_load_png("../textures/door.png");
}


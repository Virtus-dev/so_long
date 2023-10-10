/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:05:26 by arigonza          #+#    #+#             */
/*   Updated: 2023/10/10 17:47:05 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdbool.h>

int32_t	main(void)
{
	t_game		*game;
	
	game = ft_game_init();
	game->mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!game->mlx)
        error();
	
	ft_load_textures(game);
	// Display the image
	if (mlx_image_to_window(game->mlx, game->textures->wall, 0, 0) < 0)
        error();

	mlx_loop(game->mlx);

	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
	mlx_delete_image(game->mlx, game->textures->wall);
	//mlx_delete_texture(texture);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}

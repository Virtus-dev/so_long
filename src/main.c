/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:05:26 by arigonza          #+#    #+#             */
/*   Updated: 2023/11/08 14:51:27 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdbool.h>

int32_t	main(int argc, char **argv)
{
	t_game		*game;

	if (argc != 2)
		error(INVALID_NUM_ARGS);
	game = ft_game_init(argv[1]);
	game->mlx = mlx_init(WIDTH, HEIGHT, "Test", true);

	// Load the basic textures
	ft_load_textures(game);
	ft_printf("TEXTURES LOADED\n");
	if (!game->mlx)
        error(MLX_ERROR);
	
	// Map read and check
	ft_check_map(game);

	// Render the map and player
	ft_render_map(game);
	ft_render_player(game);

	// Movement
	mlx_key_hook(game->mlx, &ft_controls, game);

	mlx_loop(game->mlx);

	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
	mlx_delete_image(game->mlx, game->textures->wall);
	//mlx_delete_texture(texture);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}

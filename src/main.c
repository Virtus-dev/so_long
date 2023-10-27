/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:05:26 by arigonza          #+#    #+#             */
/*   Updated: 2023/10/27 22:37:50 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdbool.h>

int32_t	main(int argc, char **argv)
{
	t_game		*game;
	t_animation	*player_animation;
	
	if (argc != 2)
		error(INVALID_NUM_ARGS);
	game = ft_game_init(argv[1]);
	game->mlx = mlx_init(WIDTH, HEIGHT, "Test", false);
	player_animation = ft_animation_init();
	ft_iddle_player(player_animation, game);
	game->player->animation = player_animation;
	if (!game->mlx)
        error(MLX_ERROR);
	
	// Load the basic textures
	ft_load_textures(game);

	// Map read and check
	ft_check_map(game);

	// Render the map
	ft_render_map(game);

	// suposed to be the loop for the animations
	//mlx_loop_hook(game->mlx, &ft_render_animation, game);

	mlx_loop(game->mlx);

	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
	mlx_delete_image(game->mlx, game->textures->wall);
	//mlx_delete_texture(texture);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}

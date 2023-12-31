/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:05:26 by arigonza          #+#    #+#             */
/*   Updated: 2023/11/30 16:56:39 by arigonza         ###   ########.fr       */
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
	// Map read and check
	ft_check_map(game);
	game->mlx = mlx_init(game->num_rows * 32, game->num_col * 32, "so_long", true);
	// Load the basic textures
	ft_load_textures(game);
	if (!game->mlx)
        error(MLX_ERROR);
	// Render the map and player
	ft_render_map(game);
	ft_render_player(game);
	// Movement
	mlx_key_hook(game->mlx, &ft_controls, game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}

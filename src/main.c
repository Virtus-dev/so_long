/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:05:26 by arigonza          #+#    #+#             */
/*   Updated: 2024/01/13 12:37:24 by arigonza         ###   ########.fr       */
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
	ft_check_map(game);
	game->mlx = mlx_init(game->num_rows * 32,
			game->num_col * 32, "so_long", true);
	ft_load_textures(game);
	if (!game->mlx)
		error(MLX_ERROR);
	ft_render_map(game);
	ft_render_player(game);
	mlx_key_hook(game->mlx, &ft_controls, game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}

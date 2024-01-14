/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:26:31 by arigonza          #+#    #+#             */
/*   Updated: 2024/01/14 16:23:49 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_leaks(void)
{
	system("leaks -q so_long_bonus");
	exit(0);
}

int32_t	main(int argc, char **argv)
{
	t_game		*game;

	atexit(ft_leaks);
	if (argc != 2)
		error(INVALID_NUM_ARGS);
	game = ft_game_init_bonus(argv[1]);
	ft_check_map(game);
	game->mlx = mlx_init(game->num_rows * 32,
			game->num_col * 32, "so_long_bonus", true);
	ft_load_textures_bonus(game);
	if (!game->mlx)
		error(MLX_ERROR);
	ft_render_map_bonus(game);
	ft_render_player_b(game);
	mlx_key_hook(game->mlx, &ft_controls_bonus, game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}

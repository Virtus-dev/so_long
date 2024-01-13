/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:37:43 by arigonza          #+#    #+#             */
/*   Updated: 2024/01/13 13:11:54 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/includes/ft_printf.h"
# include "../lib/libft/includes/get_next_line.h"
# include "../lib/libft/includes/libft.h"
# include "constants.h"
# include <stdio.h>

//------------------------------------

/**
 * @brief Struct that holds all the player information.
 * @param animation Takes the first node of a list
 * of sprites to make the animation.
 * @param x Position of the player on the X axis.
 * @param y Position of the player on the X axis.
 * @param iddle Flag to know if the animation must be on iddle or not.
 */
typedef struct s_player
{
	int			x;
	int			y;
	int			c_counter;
}				t_player;

typedef struct s_texture
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*exit;
	mlx_image_t	*player;
	mlx_image_t	*collect_item;
}				t_texture;

/**
 * @brief Holds all the important information concerning to the game,
 * such as window and all that refers to the maps.
 * @param mlx The mlx it self.
 * @param map The map passed by arguments that helps you to construct the field.
 * @param player The player.
 * @param textures The textures loaded and converted as mlx_image_t.
 */
typedef struct s_game
{
	mlx_t		*mlx;
	char		**map;
	t_player	*player;
	t_texture	*textures;
	int			num_rows;
	int			num_col;
	int			moves;
	mlx_image_t	*score;
	int			total_c;
}				t_game;

//----------------------------------

int				ft_win(t_game *game, int current_y, int current_x);
void			ft_score(t_game *game);
// Utils
void			error(char *error);
t_game			*ft_game_init(char *argv);
void			ft_load_textures(t_game *game);
void			ft_get_citem(t_game *game);
// Map utils
void			ft_flood_fill(char **map, int y_position, int x_position);
void			ft_free_map(char **map);
void			ft_free_all(t_game *game);
size_t			ft_map_height(char **map);
void			ft_set_ply_pos(t_game *game, char **map);
// Map
int				ft_read_map(t_game *game, int fd);
void			ft_check_map(t_game *game);
void			ft_check_walls(t_game *game, size_t y_size, size_t x_size);
void			ft_check_elements(char **map);
void			ft_check_valid_path(char **map);
char			**ft_cpymap(char **map, int x_size);
// Render
void			ft_render_map(t_game *game);
void			ft_render_player(t_game *game);
void			ft_render(t_game *game, int y, int x);
// Player moves
void			ft_controls(mlx_key_data_t keydata, void *param);
void			ft_up(t_game *game);
void			ft_down(t_game *game);
void			ft_left(t_game *game);
void			ft_right(t_game *game);

#endif

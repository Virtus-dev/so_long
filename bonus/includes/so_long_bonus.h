/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:46:25 by arigonza          #+#    #+#             */
/*   Updated: 2024/01/04 18:46:43 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <stdio.h>
# include "../../lib/libft/includes/libft.h"
# include "../../lib/libft/includes/ft_printf.h"
# include "../../lib/libft/includes/get_next_line.h"
# include "../../lib/MLX42/include/MLX42/MLX42.h"
# include "../../includes/constants.h"

//------------------------------------

typedef struct s_node
{
	mlx_image_t		*img;
	int				x;
	int				y;
	struct s_node	*next;
}	t_node;

/**
 * @brief Struct that holds a list of sprites in order to make an animation.
 * @param img texture passed as an img.( mlx_texture_to_image() )
 * @param next a pointer for the next node of the list of img.
 */
typedef struct s_animation
{
	t_node	*head;
	int		size;
}	t_animation;

/**
 * @brief Struct that holds all the player information.
 * @param animation Takes the first node of a list
 *  of sprites to make the animation.
 * @param x Position of the player on the X axis.
 * @param y Position of the player on the X axis.
 * @param iddle Flag to know if the animation must be on iddle or not.
 */
typedef struct s_player
{
	t_animation	*animation;
	int			x;
	int			y;
	int			c_counter;
}	t_player;

typedef struct s_texture
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*exit;
	mlx_image_t	*exit_open;
	mlx_image_t	*player;
	mlx_image_t	*collect_item;
	mlx_image_t	*enemy;
}	t_texture;

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
}	t_game;

//----------------------------------

// Bonus
int			ft_win_bonus(t_game *game, int current_y, int current_x);
void		ft_score(t_game *game);
void		ft_door_open(t_game *game);
// Utils
void		error(char *error);
t_game		*ft_game_init(char *argv);
void		ft_load_textures_bonus(t_game *game);
void		ft_load_textures(t_game *game);
void		ft_get_citem(t_game *game);
void		ft_free_all_b(t_game *game);
// Map utils
void		ft_print_map(char **map);
void		ft_flood_fill(char **map, int y_position, int x_position);
void		ft_free_map(char **map);
size_t		ft_map_height(char **map);
void		ft_set_ply_pos(t_game *game, char **map);
// Map
int			ft_read_map(t_game *game, int fd);
void		ft_check_map(t_game *game);
void		ft_check_walls(t_game *game, size_t y_size, size_t x_size);
void		ft_check_elements(char **map);
void		ft_check_valid_path(char **map);
char		**ft_cpymap(char **map, int x_size);
// Render
void		ft_dead(t_game *game, int current_y, int current_x);
void		ft_render_map_bonus(t_game *game);
void		ft_render_player(t_game *game);
void		ft_render_animation(t_game *param);
// Player moves
void		ft_controls_bonus(mlx_key_data_t keydata, void *param);
void		ft_up_b(t_game *game);
void		ft_down_b(t_game *game);
void		ft_left_b(t_game *game);
void		ft_right_b(t_game *game);
// Animations
t_node		*ft_new_img_node(mlx_image_t *image);
t_animation	*ft_animation_init(void);
void		ft_add_img(t_animation *animation, t_node *img);
void		ft_iddle_player(t_animation *animation, t_game *game);

#endif
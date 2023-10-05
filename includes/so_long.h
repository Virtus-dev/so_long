/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:37:43 by arigonza          #+#    #+#             */
/*   Updated: 2023/10/03 11:38:27 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include "../lib/libft/includes/libft.h"
# include "../lib/libft/includes/ft_printf.h"
# include "../lib/libft/includes/get_next_line.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

# define HEIGHT 800
# define WIDTH 800
# define IDDLE 0
# define TREE 2
# define WALL 1
# define FLOOR 0
# define PLAYER "p"

//---------------------

/**
 * @brief Struct that holds a list of sprites in order to make an animation.
 * @param img texture passed as an img.( mlx_texture_to_image() )
 * @param next a pointer for the next node of the list of img.
 */
typedef struct s_animation
{
    mlx_image_t			*img;
    struct s_animation	*next;
}	t_animation;

/**
 * @brief Struct that holds all the player information.
 * @param animation Takes the first node of a list of sprites to make the animation.
 * @param x Position of the player on the X axis.
 * @param y Position of the player on the X axis.
 * @param iddle Flag to know if the animation must be on iddle or not.
 */
typedef struct s_player
{
    t_animation	*animation;
    int			x;
    int			y;
    int			iddle;
}	t_player;

typedef struct s_entity
{
	mlx_image_t	*entity;
	char		indentifier;
	int			x;
	int			y;
} t_entity;

/**
 * @brief Holds all the important information concerning to the game,
 * such as window and all that refers to the maps.
 * @param mlx The mlx it self.
 * @param map The map passed by arguments that helps you to construct the field.
 * @param player The player.
 * @param wall The wall image to draw.
 * @param tree The tree image to draw.
 * @param floor The floor image to draw.
 */
typedef struct s_game
{
    mlx_t		*mlx;
    char		**map;
	t_player	*player;
	t_entity	**entity;
}	t_game;


//---------------------

void	error(void);

#endif
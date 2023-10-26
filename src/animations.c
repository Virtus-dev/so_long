/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:20:09 by arigonza          #+#    #+#             */
/*   Updated: 2023/10/25 20:06:48 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_node	*ft_new_img_node(mlx_image_t *image)
{
	t_node	*node;
	
	node = (t_node *)malloc(sizeof(t_node));
	node->img = image;
	node->next = NULL;
	return (node);
}

t_animation	*ft_animation_init()
{
	t_animation *animation;
	
	animation = (t_animation*)malloc(sizeof(t_animation));
	animation->head = NULL;
	animation->size = 0;
	
	return (animation);
}

void	ft_img_into_animation(t_animation *animation, t_node *img)
{
	t_node	*current;
	
	if (!animation || !img)
		return ;
	if (!animation->head)
		animation->head = img;
	else
	{
		current = animation->head;
		while (current->next)
			current = current->next;
		current->next = img;
		//ft_printf("working");
	}
	animation->size++;
}

void	ft_iddle_player(t_animation *animation, t_game *game)
{
	int		i;
	t_node	**nodes;
	
	nodes = (t_node**)malloc(4 * sizeof(t_node*));
	nodes[0] = ft_new_img_node(mlx_texture_to_image(game->mlx, mlx_load_png("textures/iddle_player_0.png")));
	nodes[1] = ft_new_img_node(mlx_texture_to_image(game->mlx, mlx_load_png("textures/iddle_player_1.png")));
	nodes[2] = ft_new_img_node(mlx_texture_to_image(game->mlx, mlx_load_png("textures/iddle_player_2.png")));
	nodes[3] = ft_new_img_node(mlx_texture_to_image(game->mlx, mlx_load_png("textures/iddle_player_3.png")));
	i = 0;
	while (i < 4)
		ft_img_into_animation(animation, nodes[i++]);
}
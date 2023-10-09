/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:20:09 by arigonza          #+#    #+#             */
/*   Updated: 2023/10/09 17:48:57 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_node	*ft_new_img_node(mlx_image_t *image)
{
	t_node	*node;
	
	node = malloc(sizeof(t_node*));
	node->img = image;
	node->next = NULL;
	return (node);
}

void	ft_fill_animation(t_animation *animation,int size, t_node **img_node)
{
	t_node	*tmp;
	t_node	*current;
	int		i;
	
	i = 0;
	if (!animation | !img_node[0])
		return ;
	if (!animation->head)
	{
		tmp = img_node[0];
		animation->head = tmp;
	}
	current = animation->head;
	while (current->next)
		current = current->next;
	while (size > i)
	{
		current->next = img_node[i++];
		current = current->next;
		animation->size++;
	}
}

t_animation	*ft_animation_struct_init(void)
{
	t_animation	*animation;

	animation = malloc(sizeof(t_animation*));
	animation->head = NULL;
	animation->size = 0;
	
	return (animation);
}

void	ft_img_into_animation(t_animation *animation, t_node *img)
{
	t_node	*current;
	
	current = animation->head;
	while (current->next)
		current = current->next;
	current->next = img;
}

t_animation	*ft_player_iddle(t_game *game)
{
	t_animation	*iddle;
	mlx_image_t	*img_1;
	mlx_image_t	*img_2;

	img_1 =  mlx_texture_to_image(game->mlx, mlx_load_png("../textures/iddle_0.png"));
	img_2 =  mlx_texture_to_image(game->mlx, mlx_load_png("../textures/iddle_1.png"));
	//iddle->img = img_1;
}
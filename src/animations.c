/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:20:09 by arigonza          #+#    #+#             */
/*   Updated: 2023/10/10 16:50:51 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_node	*ft_new_img_node(mlx_image_t *image)
{
	t_node	*node;
	
	node = (t_node *)malloc(sizeof(t_node));
	node->img = image;
	node->next = NULL;
	return (node);
}

void	ft_animation_struct_init(t_animation *animation)
{
	animation->head = NULL;
	animation->size = 0;
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
	}
	animation->size++;
}

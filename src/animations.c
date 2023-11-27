/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:20:09 by arigonza          #+#    #+#             */
/*   Updated: 2023/11/22 22:29:52 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_node	*ft_new_img_node(mlx_image_t *image)
{
	t_node	*node;
	
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (free(node), NULL);
	node->img = image;
	node->next = NULL;
	return (node);
}

t_animation	*ft_animation_init()
{
	t_animation *animation;
	
	animation = (t_animation*)malloc(sizeof(t_animation));
	if (!animation)
		return (free(animation), NULL);
	animation->head = NULL;
	animation->size = 0;

	return (animation);
}

void	ft_add_img(t_animation *animation, t_node *img)
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
	ft_printf("Adding img into the animation\n");
	animation->size++;
}

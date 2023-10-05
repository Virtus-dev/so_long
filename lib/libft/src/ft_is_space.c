/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:57:08 by arigonza          #+#    #+#             */
/*   Updated: 2023/06/13 15:07:39 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// checks if there's o there's not a space or tabs
int	ft_is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	else
		return (0);		
}
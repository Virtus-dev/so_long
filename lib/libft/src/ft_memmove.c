/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:05:28 by arigonza          #+#    #+#             */
/*   Updated: 2022/10/04 13:30:57 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function copies "n" bytes from the memory of "src" to "dest".
** Memories may overlap.
** First, the bytes in "src" are copied into a temporary array and then to
** "dest".
** For further information, please check the Standard C Library function
** 'memmove(void *dst, const void *src, size_t n)'
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*src2;
	char	*dst2;

	src2 = (char *)src;
	dst2 = (char *)dst;
	i = 0;
	if (!dst && !src)
		return (0);
	if (dst > src)
	{
		while (len--)
			dst2[len] = src2[len];
	}
	else if (dst <= src)
	{
		while (i < len)
		{
			dst2[i] = src2[i];
			i++;
		}
	}
	return (dst);
}

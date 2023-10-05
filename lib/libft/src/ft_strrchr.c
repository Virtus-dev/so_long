/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:16:58 by arigonza          #+#    #+#             */
/*   Updated: 2022/10/04 13:36:37 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	index;

index = ft_strlen((char *)str) + 1;
	while (index--)
	{
		if (*(str + index) == (char)c)
			return ((char *)(str + index));
	}
	return (0);
}

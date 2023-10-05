/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:54:56 by arigonza          #+#    #+#             */
/*   Updated: 2022/10/18 18:04:25 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*aux;
	size_t	i;

	i = 0;
	if (ft_strlen(s) <= start)
	{
			aux = malloc(sizeof(char) * 1);
		if (!aux)
			return (0);
		*aux = '\0';
		return (aux);
	}
	if (len > (ft_strlen(s + start)))
			len = ft_strlen(s + start);
	aux = malloc(sizeof(char) * len + 1);
	if (!aux)
		return (0);
	while (start < ft_strlen(s) && i < len)
	{
		aux[i++] = s[start++];
	}
	aux[i] = '\0';
	return (aux);
}

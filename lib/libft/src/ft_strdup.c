/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:18:06 by arigonza          #+#    #+#             */
/*   Updated: 2022/10/18 16:40:34 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//returns a pointer to a new string which is a duplicate of the string s1.
char	*ft_strdup(const char *s1)
{
	char	*cpy;

	cpy = (char *)malloc(ft_strlen(s1) + 1);
	if (!cpy)
		return (0);
	ft_memcpy(cpy, s1, ft_strlen(s1) + 1);
	return (cpy);
}

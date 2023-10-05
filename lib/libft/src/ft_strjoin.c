/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:16:34 by arigonza          #+#    #+#             */
/*   Updated: 2022/10/03 12:35:13 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*combinedstring;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s1 && !s2)
		return (0);
	combinedstring = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!combinedstring)
		return (0);
	while (s1[i] != '\0')
	{
		combinedstring[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		combinedstring[i] = s2[j];
		i++;
		j++;
	}
	combinedstring[i] = '\0';
	return (combinedstring);
}

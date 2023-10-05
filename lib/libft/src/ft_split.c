/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:05:28 by arigonza          #+#    #+#             */
/*   Updated: 2023/07/03 14:30:29 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counterwords(const char *s, char c)
{
	int	i;
	int	words;
	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			words++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (words);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	j;
	int		found;
	char	**splitedstr;

	i = 0;
	j = 0;
	found = 0;
	splitedstr = (char**)malloc (sizeof(char *) * (ft_counterwords(s, c) + 1));
	if (!splitedstr)
		return (free(splitedstr), NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i > 0 && s[i - 1] != c)
			splitedstr[found++] = ft_substr(s, j, (i - j));
	}
	splitedstr[found] = NULL;
	return (splitedstr);
}

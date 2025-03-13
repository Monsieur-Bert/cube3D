/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 20:27:06 by antauber          #+#    #+#             */
/*   Updated: 2025/01/23 08:54:38 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*ft_dup(char const *s, char c)
{
	int		i;
	int		len;
	char	*dup;

	i = 0;
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	while (s[i] && i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static char	**set_split(char **split, const char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] && s[j] == c)
			j++;
		if (s[j] && s[j] != c)
		{
			split[i] = ft_dup((&s[j]), c);
			if (!split[i])
				return (ft_free_tabstr(split));
			i++;
			while (s[j] && s[j] != c)
				j++;
		}
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	int		size;
	char	**split;

	if (!s)
		return (NULL);
	size = ft_count_words(s, c);
	split = malloc(sizeof(char *) * (size + 1));
	if (split == NULL)
		return (NULL);
	split = set_split(split, s, c);
	return (split);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 20:27:06 by antauber          #+#    #+#             */
/*   Updated: 2025/01/23 08:53:33 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*ft_dup(char const *s, char *set)
{
	int		i;
	int		len;
	char	*dup;

	i = 0;
	len = 0;
	while (s[len] && !ft_charinset(s[len], set))
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

static char	**set_split(char **split, const char *s, char *set)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] && ft_charinset(s[j], set))
			j++;
		if (s[j] && !ft_charinset(s[j], set))
		{
			split[i] = ft_dup((&s[j]), set);
			if (!split[i])
				return (ft_free_tabstr(split));
			i++;
			while (s[j] && !ft_charinset(s[j], set))
				j++;
		}
	}
	split[i] = NULL;
	return (split);
}

char	**ft_setsplit(char const *s, char *set)
{
	int		size;
	char	**split;

	if (!s)
		return (NULL);
	size = ft_count_wordset(s, set);
	split = malloc(sizeof(char *) * (size + 1));
	if (split == NULL)
		return (NULL);
	split = set_split(split, s, set);
	return (split);
}

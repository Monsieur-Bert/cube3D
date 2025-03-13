/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:04:59 by antauber          #+#    #+#             */
/*   Updated: 2024/12/18 12:20:38 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	gnl_strlen(const char *s)
{
	const char	*tmp;

	if (!s)
		return (0);
	tmp = s;
	while (*tmp)
		tmp++;
	return (tmp - s);
}

char	*gnl_ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*dup;

	i = 0;
	len = gnl_strlen(s);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	*gnl_to_free(char *store, char *buffer)
{
	free(store);
	free(buffer);
	return (NULL);
}

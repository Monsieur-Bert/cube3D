/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:59:03 by antauber          #+#    #+#             */
/*   Updated: 2024/12/18 12:22:55 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = ft_strlen(str);
	if (c == '\0')
		return (str + i);
	while (i > 0)
	{
		if (str[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	if (str[0] == (char)c)
		return (str);
	return (0);
}

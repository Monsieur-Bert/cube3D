/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:50:10 by antauber          #+#    #+#             */
/*   Updated: 2024/12/18 12:22:58 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_charinset(s1[start], set))
		start++;
	end = ft_strlen(s1);
	end--;
	while (end > 0 && ft_charinset(s1[end], set))
		end--;
	trim = ft_substr(s1, start, ((end - start) + 1));
	return (trim);
}

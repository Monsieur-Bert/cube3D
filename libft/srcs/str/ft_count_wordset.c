/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_wordset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 20:27:06 by antauber          #+#    #+#             */
/*   Updated: 2024/12/18 12:22:16 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_count_wordset(char const *s, char *set)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && ft_charinset(s[i], set))
			i++;
		if (s[i] && !ft_charinset(s[i], set))
		{
			count ++;
			while (s[i] && !ft_charinset(s[i], set))
				i++;
		}
	}
	return (count);
}

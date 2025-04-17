/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:40:42 by ygorget           #+#    #+#             */
/*   Updated: 2025/04/17 14:12:06 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

int	ft_maplen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	one_charactere(int p)
{
	if (p != 1)
	{
		print_error(ERR_CHARACTERS);
		return (1);
	}
	return (0);
}

bool	wall_or_floor(char c)
{
	if (c == '0' || c == '1' || c == 'F' || c == 'D')
		return (true);
	return (false);
}

bool	is_sprite(char c)
{
	if (c == 'F' || c == 'D')
		return (true);
	return (false);
}

int	door_in_wall(char **tab, int i, int j)
{
	if (tab[i][j] == 'D')
	{
		if (tab[i - 1][j] && tab[i - 1][j] == '1'
			&& tab[i + 1][j] && tab[i + 1][j] == '1')
			return (0);
		else if (tab[i][j - 1] && tab[i][j - 1] == '1'
			&& tab[i][j + 1] && tab[i][j + 1] == '1')
			return (0);
		else
		{
			print_error(ERR_DOOR);
			return (1);
		}
	}
	return (0);
}

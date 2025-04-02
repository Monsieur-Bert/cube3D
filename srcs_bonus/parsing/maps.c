/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:41:35 by ygorget           #+#    #+#             */
/*   Updated: 2025/04/02 12:06:28 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

bool	is_character(char c)
{
	if (c == 'N')
		return (true);
	if (c == 'S')
		return (true);
	if (c == 'W')
		return (true);
	if (c == 'E')
		return (true);
	return (false);
}

static bool	wall_or_floor(char c)
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

static int	check_around(char **tab, int i, int j)
{
	if (j == 0 || i + 1 == ft_maplen(tab))
		return (1);
	if (!wall_or_floor(tab[i + 1][j]) && !is_character(tab[i + 1][j]))
		return (1);
	if (!wall_or_floor(tab[i - 1][j]) && !is_character(tab[i - 1][j]))
		return (1);
	if (!wall_or_floor(tab[i][j + 1]) && !is_character(tab[i][j + 1]))
		return (1);
	if (!wall_or_floor(tab[i][j - 1]) && !is_character(tab[i][j - 1]))
		return (1);
	return (0);
}


static int	good_items(char **tab, int i, int j, int *p)
{
	if (is_character(tab[i][j]))
		(*p)++;
	if (!wall_or_floor(tab[i][j]) && !is_character(tab[i][j])
	&& tab[i][j] != ' ')
	{
		print_error(ERR_ITEMS);
		return (1);
	}
	return (0);
}

int	door_in_wall(char **tab, int i, int j)
{
	if (tab[i - 1][j] && tab[i - 1][j] == '1' && tab[i + 1][j] && tab[i + 1][j] == '1')
		return (0);
	if (tab[i][j - 1] && tab[i][j - 1] == '1' && tab[i][j + 1] && tab[i][j + 1] == '1')
		return (0);
	return (1);
}

int	maps(char **tab, int p)
{
	int	i;
	int	j;

	i = 5;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] == '0' || is_character(tab[i][j]) || is_sprite(tab[i][j]))
			{
				if (check_around(tab, i, j) == 1)
				{
					print_error(ERR_WALL);
					return (1);
				}
				if (tab[i][j] == 'D')
				{
					if (door_in_wall(tab, i, j) == 1)
					{
						print_error(ERR_DOOR);
						return (1);
					}
				}
			}
			if (good_items(tab, i, j, &p) == 1)
				return (1);
		}
	}
	if (one_charactere(p) == 1)
		return (1);
	return (0);
}

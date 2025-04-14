/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:41:35 by ygorget           #+#    #+#             */
/*   Updated: 2025/04/14 14:35:26 by ygorget          ###   ########.fr       */
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
	if (c == '0' || c == '1')
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

int	maps(char **tab, int p, int i)
{
	int	j;

	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] == '0' || is_character(tab[i][j]))
			{
				if (check_around(tab, i, j) == 1)
				{
					print_error(ERR_WALL);
					return (1);
				}
			}
			if (good_items(tab, i, j, &p) == 1)
				return (1);
		}
	}
	if (no_map(i) == 1)
		return (1);
	if (one_charactere(p) == 1)
		return (1);
	return (0);
}

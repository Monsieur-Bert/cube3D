/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:45:14 by ygorget           #+#    #+#             */
/*   Updated: 2025/03/24 16:36:37 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

void	init_texture(t_texture *img)
{
	img->no = NULL;
	img->so = NULL;
	img->we = NULL;
	img->ea = NULL;
	img->f = NULL;
	img->c = NULL;
}

int	no_space(char *rgb)
{
	int	i;

	i = 0;
	while (ft_isspaces(rgb[i]))
		i++;
	while (ft_isdigit(rgb[i]))
		i++;
	while (ft_isspaces(rgb[i]))
		i++;
	if (ft_isdigit(rgb[i]))
	{
		print_error(ERR_RGB);
		return (1);
	}
	return (0);
}

int	rgb(int *parsed_color, char *str)
{
	char	**rgb;
	t_color	color;

	rgb = ft_split(str, ',');
	if (!rgb)
	{
		print_error(ERR_MALLOC);
		return (1);
	}
	if (no_space(rgb[0]) == 1 || no_space(rgb[1]) == 1 || no_space(rgb[2]) == 1)
	{
		ft_free_tabstr(rgb);
		return (1);
	}
	color.r = ft_atoi(rgb[0]);
	color.g = ft_atoi(rgb[1]);
	color.b = ft_atoi(rgb[2]);
	ft_free_tabstr(rgb);
	*parsed_color = (color.r << 16) | (color.g << 8) | color.b;
	return (0);
}

void	pos_character(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j] && !is_character(map->map[i][j]))
			j++;
		if (is_character(map->map[i][j]))
			break ;
		i++;
	}
	map->pos.pos = map->map[i][j];
	map->pos.x = j;
	map->pos.y = i;
}

int	init_struct(char **tab, t_texture *img, t_map *map)
{
	map->map = &tab[6];
	pos_character(map);
	map->img.no = img->no;
	map->img.so = img->so;
	map->img.we = img->we;
	map->img.ea = img->ea;
	if (rgb(&map->floor, img->f) == 1)
		return (1);
	if (rgb(&map->ceiling, img->c) == 1)
		return (1);
	return (0);
}

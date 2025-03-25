/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:08:11 by ygorget           #+#    #+#             */
/*   Updated: 2025/03/24 16:51:45 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

static void	draw_mini(t_img *render, int *x, int y, int img)
{
	int count_x;
	int count_y;

	count_x = 0;
	count_y = 0;
	while (count_x <= 8)
	{
		while (count_y < 8)
		{
			ft_put_pixel(render, *x, y++, img);
			count_y++;
		}
		y -= 8;
		count_y = 0;
		count_x++;
		(*x)++;
	}
}

static int	limit(int pos)
{
	if (pos - 4 >= 0)
		return (pos + 4);
	return (8);
}

static void	mini(t_cube *cube, int i, int j)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (1)
	{
		if (j > limit(cube->ray.pos_x) || j == ft_maplen(cube->map.map))
		{
			j -= 9;
			i++;
			if (i > limit(cube->ray.pos_y) || i == (int)ft_strlen(cube->map.map[0]))
				break; 
			x = 0;
			y += 8;
		}
		if (i == (int)cube->ray.pos_y && j == (int)cube->ray.pos_x)
			draw_mini(&cube->mlx.render, &x, y, PLAYER);
		else if (cube->map.map[i][j] == '1')
			draw_mini(&cube->mlx.render, &x, y, WALL);
		else if (cube->map.map[i][j] == '0' || is_character(cube->map.map[i][j]))
			draw_mini(&cube->mlx.render, &x, y, FLOOR);
		j++;
	}
}

void	minimap(t_cube *cube)
{
	int j;
	int i;
	
	if (cube->ray.pos_x - 4 >= 0)
		j = cube->ray.pos_x - 4;	
	else
		j = 0;
	if (cube->ray.pos_y - 4 >= 0)
		i = cube->ray.pos_y - 4;
	else
		i = 0;
	if (j + 8 >= (int)ft_strlen(cube->map.map[i]))
		j = (int)ft_strlen(cube->map.map[i]) - 9;
	if (i + 8 >= (int)ft_maplen(cube->map.map))
		i = (int)ft_maplen(cube->map.map) - 9;
	mini(cube, i , j);
}
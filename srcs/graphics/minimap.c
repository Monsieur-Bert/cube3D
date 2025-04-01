/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:08:11 by ygorget           #+#    #+#             */
/*   Updated: 2025/04/01 16:50:38 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

static void	draw_tile(t_img *render, int img, t_minimap *plan)
{
	int	count_x;
	int	count_y;
	int	tmp;

	tmp = plan->y;
	count_x = 0;
	count_y = 0;
	if (plan->x == 80 || plan->y == 80)
		return ;
	while (count_x < plan->limit_x)
	{
		while (count_y < plan->limit_y)
		{
			ft_put_pixel(render, plan->x, plan->y++, img);
			if (plan->y == 80)
				break ;
			count_y++;
		}
		plan->y = tmp;
		count_y = 0;
		count_x++;
		plan->x++;
		if (plan->x == 80)
			break ;
	}
}

static double	limit(double pos)
{
	if (pos - 4 > 0)
		return (pos + 4);
	return (pos - (int)pos + 7.5);
}

void	draw_map_element(t_cube *cube, t_minimap *plan)
{
	if ((int)plan->i == (int)cube->ray.pos_y
		&& (int)plan->j == (int)cube->ray.pos_x)
		draw_tile(&cube->mlx.render, PLAYER, plan);
	else if ((int)plan->i >= ft_maplen(cube->map.map)
		|| (int)plan->j >= (int)ft_strlen(cube->map.map[(int)plan->i])
		|| cube->map.map[(int)plan->i][(int)plan->j] == ' ')
		draw_tile(&cube->mlx.render, VOID, plan);
	else if (cube->map.map[(int)plan->i][(int)plan->j] == '1')
		draw_tile(&cube->mlx.render, WALL, plan);
	else if (cube->map.map[(int)plan->i][(int)plan->j] == '0'
		|| is_character(cube->map.map[(int)plan->i][(int)plan->j]))
		draw_tile(&cube->mlx.render, FLOOR, plan);
}

void	draw_part_element(t_cube *cube, t_minimap *plan)
{
	int	i;
	int	j;

	if (plan->count_i == 1)
		i = ceil(plan->i);
	else
		i = floor(plan->i);
	if (plan->count_j == 1)
		j = ceil(plan->j);
	else
		j = floor(plan->j);
	if (i >= ft_maplen(cube->map.map) || j >= (int)ft_strlen(cube->map.map[i])
		|| cube->map.map[i][j] == ' ')
		draw_tile(&cube->mlx.render, VOID, plan);
	else if (cube->map.map[i][j] == '1')
		draw_tile(&cube->mlx.render, WALL, plan);
	else if (cube->map.map[i][j] == '0' || is_character(cube->map.map[i][j]))
		draw_tile(&cube->mlx.render, FLOOR, plan);
}

static void	limit_xy(t_minimap *plan)
{
	plan->limit_x = 10 - ((plan->j - (int)plan->j) * 10);
	plan->limit_y = 10 - ((plan->i - (int)plan->i) * 10);
}

int	newline_minimap(t_cube *cube, t_minimap *plan, double fmo_i, double tmp)
{
	plan->j -= (plan->j - tmp);
	if (plan->i + fmo_i == cube->ray.pos_y + 4)
	{
		plan->count_i++;
		plan->i += fmo_i;
	}
	else
		plan->i += plan->limit_y * 0.1;
	if (plan->i >= limit(cube->ray.pos_y))
	{
		plan->count_i--;
		return (1);
	}
	plan->x = 0;
	plan->y += plan->limit_y;
	limit_xy(plan);
	plan->count_j = 0;
	return (0);
}

static void	mini(t_cube *cube, t_minimap *plan)
{
	double	tmp;
	double	fmo_j;
	double	fmo_i;

	fmo_j = fmod(plan->j, 1.0);
	fmo_i = fmod(plan->i, 1.0);
	tmp = plan->j;
	while (1)
	{
		limit_xy(plan);
		if (plan->j >= limit(cube->ray.pos_x))
		{
			if (newline_minimap(cube, plan, fmo_i, tmp) == 1)
				break ;
		}
		if (plan->count_j == 1 || plan->count_i == 1)
			draw_part_element(cube, plan);
		else
			draw_map_element(cube, plan);
		if (plan->j + fmo_j == cube->ray.pos_x + 4)
		{
			plan->count_j++;
			plan->j += fmo_j;
		}
		else
			plan->j += plan->limit_x * 0.1;
	}
}

void	init_plan(t_cube *cube, t_minimap *plan)
{
	if (cube->ray.pos_x - 4 > 0)
		plan->j = cube->ray.pos_x - 4;
	else
		plan->j = 0;
	if (cube->ray.pos_y - 4 >= 0)
		plan->i = cube->ray.pos_y - 4;
	else
		plan->i = 0;
	plan->x = 0;
	plan->y = 0;
	plan->count_j = 0;
	plan->count_i = 0;
}

void	minimap(t_cube *cube)
{
	t_minimap	plan;

	init_plan(cube, &plan);
	mini(cube, &plan);
}

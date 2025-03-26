/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:08:11 by ygorget           #+#    #+#             */
/*   Updated: 2025/03/26 11:41:37 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

static void	draw_tile(t_img *render, int *x, int y, int img, t_minimap *plan)
{
	int count_x;
	int count_y;
	
	count_x = 0;
	count_y = 0;
	while (count_x <= plan->limit_x)
	{
		while (count_y < plan->limit_y)
		{
			ft_put_pixel(render, *x, y++, img);
			count_y++;
		}
		y -= plan->limit_y;
		count_y = 0;
		count_x++;
		(*x)++;
	}
}

static double	limit(double pos)
{
	if (pos - 4 > 0)
		return (pos + 4);
	return (pos - (int)pos + 8.0);
}

void	draw_map_element(t_cube *cube, t_minimap *plan)
{
	if ((int)plan->i == (int)cube->ray.pos_y && (int)plan->j == (int)cube->ray.pos_x)
		draw_tile(&cube->mlx.render, &plan->x, plan->y, PLAYER, plan);
	else if ((int)plan->i >= ft_maplen(cube->map.map) || (int)plan->j >= (int)ft_strlen(cube->map.map[(int)plan->i]) || cube->map.map[(int)plan->i][(int)plan->j] == ' ')
		draw_tile(&cube->mlx.render, &plan->x, plan->y, VOID, plan);
	else if (cube->map.map[(int)plan->i][(int)plan->j] == '1')
		draw_tile(&cube->mlx.render, &plan->x, plan->y, WALL, plan);
	else if (cube->map.map[(int)plan->i][(int)plan->j] == '0' || is_character(cube->map.map[(int)plan->i][(int)plan->j]))
		draw_tile(&cube->mlx.render, &plan->x, plan->y, FLOOR, plan);
}

static void	limit_xy(t_minimap *plan)
{
	plan->limit_x = 10 - ((plan->j - (int)plan->j) * 10);
	plan->limit_y = 10 - ((plan->i - (int)plan->i) * 10);
}

static void	mini(t_cube *cube, t_minimap *plan)
{
	double tmp;
	
	tmp = plan->j;
	while (1)
	{
		limit_xy(plan);
		if (plan->j > limit(cube->ray.pos_x))
		{
			plan->j -= (plan->j - tmp);
			if ((int)(cube->ray.pos_y + 4 - plan->i) < 1 && (int)(cube->ray.pos_y + 4 - plan->i) > 0)
				plan->i += cube->ray.pos_y + 4 - plan->i;
			else
				plan->i += plan->limit_y * 0.1;
			if (plan->i >= limit(cube->ray.pos_y))
				break; 
			plan->x = 0;
			plan->y += plan->limit_y;
			limit_xy(plan);
		}
		draw_map_element(cube, plan);
		if ((int)(cube->ray.pos_x + 4 - plan->j) < 1 && (int)(cube->ray.pos_x + 4 - plan->j) > 0)
			plan->j += cube->ray.pos_x + 4 - plan->j;
		else
			plan->j += plan->limit_x * 0.1;
	}
}

void	minimap(t_cube *cube)
{
	t_minimap plan;
	
	if (cube->ray.pos_x - 4 > 0)
		plan.j = cube->ray.pos_x - 4;	
	else
		plan.j = 0;
	if (cube->ray.pos_y - 4 > 0)
		plan.i = cube->ray.pos_y - 4;
	else
		plan.i = 0;
	plan.x = 0;
	plan.y = 0;
	mini(cube, &plan);
}

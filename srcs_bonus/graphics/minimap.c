/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:08:11 by ygorget           #+#    #+#             */
/*   Updated: 2025/04/07 15:24:46 by antauber         ###   ########.fr       */
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
	else if (cube->map.map[(int)plan->i][(int)plan->j] == 'F')
		draw_tile(&cube->mlx.render, FIRE, plan);
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
		else if (cube->map.map[i][j] == 'F')
		draw_tile(&cube->mlx.render, FIRE, plan);
	else if (cube->map.map[i][j] == '0' || is_character(cube->map.map[i][j]))
		draw_tile(&cube->mlx.render, FLOOR, plan);
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
		new_element(cube, plan, fmo_j);
	}
}

void	minimap(t_cube *cube)
{
	t_minimap	plan;

	init_plan(cube, &plan);
	mini(cube, &plan);
}

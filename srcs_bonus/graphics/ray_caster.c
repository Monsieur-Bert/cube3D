/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:51:18 by antauber          #+#    #+#             */
/*   Updated: 2025/04/07 16:08:05 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

static void	init_ray(t_ray *ray)
{
	ray->cam_x = 2 * ray->x / (double)WIN_W - 1;
	ray->ray_dir_x = ray->dir_x + ray->plane_x * ray->cam_x;
	ray->ray_dir_y = ray->dir_y + ray->plane_y * ray->cam_x;
	ray->map_x = (int)ray->pos_x;
	ray->map_y = (int)ray->pos_y;
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

static void	set_player_dir(t_ray *ray, char dir)
{
	if (dir == 'N')
	{
		ray->dir_y = -1;
		ray->plane_x = 0.66;
	}
	else if (dir == 'S')
	{
		ray->dir_y = 1;
		ray->plane_x = -0.66;
	}
	else if (dir == 'W')
	{
		ray->dir_x = -1;
		ray->plane_y = -0.66;
	}
	else if (dir == 'E')
	{
		ray->dir_x = 1;
		ray->plane_y = 0.66;
	}
}

void	set_player(t_ray *ray, t_map *map)
{
	int	i;

	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->plane_x = 0;
	ray->plane_y = 0;
	ray->offset = 0;
	ray->pos_x = map->pos.x + 0.5;
	ray->pos_y = map->pos.y + 0.5;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->x = 0;
	i = 0;
	while (i < WIN_W)
	{
		ray->z_buffer[i] = 0;
		i++;
	}
	set_player_dir(ray, map->pos.pos);
}

void	raycaster(t_cube *cube)
{
	cube->ray.x = 0;
	while (cube->ray.x < WIN_W)
	{
		init_ray(&cube->ray);
		find_step_dda(&cube->ray);
		perform_dda(&cube->ray, cube->map.map, cube->door);
		draw_walls(cube, &cube->ray, &cube->mlx);
		cube->ray.x++;
	}
}

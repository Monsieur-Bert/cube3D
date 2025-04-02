/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:55:08 by antauber          #+#    #+#             */
/*   Updated: 2025/04/02 16:07:34 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

bool	door_close(t_door **door, int y, int x)
{
	t_door *tmp;

	if (!door)
		return (false);
	tmp = *door;
	while (tmp)
	{
		if (tmp->x == x && tmp->y == y && tmp->open == false)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

void	perform_dda(t_ray *ray, char **map, t_door *door)
{
	(void)door;
	while (ray->hit == false)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = false;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = true;
		}
		if (map[ray->map_y][ray->map_x] == '1' || (map[ray->map_y][ray->map_x] == 'D' && door_close(&door, ray->map_y, ray->map_x)))
			ray->hit = true;
	}
	if (!ray->side)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
}

void	find_step_dda(t_ray *ray)
{
	ray->hit = false;
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (ray->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - ray->pos_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (ray->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - ray->pos_y) * ray->delta_dist_y;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:55:45 by antauber          #+#    #+#             */
/*   Updated: 2025/04/04 15:54:19 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

void	draw_background(t_cube *cube)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < (cube->mlx.half_height) + cube->ray.offset && y <= WIN_HEIGHT)
			ft_put_pixel(&cube->mlx.render, x, y++, cube->map.ceiling);
		while (y <= WIN_HEIGHT)
			ft_put_pixel(&cube->mlx.render, x, y++, cube->map.floor);
		x++;
	}
}

static void	find_texture_pixel(t_text *text, t_ray *ray)
{
	text->x = (int)(ray->wall_x * 64);
	if (!ray->side && ray->ray_dir_x > 0)
		text->x = 64 - text->x - 1;
	if (ray->side && ray->ray_dir_y < 0)
		text->x = 64 - text->x - 1;
	text->step = 1.0 * (double)64 / ray->line_height;
	text->pos = (ray->draw_start - ((WIN_HEIGHT >> 1) + ray->offset)
			+ (ray->line_height >> 1)) * text->step;
}

static void	add_wall_texture(t_img *img, t_img *wall, t_ray *ray)
{
	t_text	text;

	if (!ray->side)
		ray->wall_x = ray->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = ray->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
	find_texture_pixel(&text, ray);
	while (ray->draw_start < ray->draw_end && ray->draw_start < WIN_HEIGHT)
	{
		if (ray->draw_start >= 0)
		{
			text.y = (int)text.pos & 63;
			text.pos += text.step;
			text.pixl = text.y * wall->line_len
				+ ((int)(text.x * wall->bpp) >> 3);
			text.color = *(int *)(wall->addr + text.pixl);
			ft_put_pixel(img, ray->x, ray->draw_start, text.color);
		}
		ray->draw_start++;
	}
}

void	door_or_wall(t_cube *cube, t_ray *ray, t_mlx *mlx, t_img *wall)
{
	if (cube->map.map[ray->map_y][ray->map_x] == 'D')
		add_wall_texture(&mlx->render, &mlx->door, ray);
	else
		add_wall_texture(&mlx->render, wall, ray);
}

void	draw_walls(t_cube *cube, t_ray *ray, t_mlx *mlx)
{
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = - (ray->line_height >> 1) + (mlx->half_height + ray->offset);
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (ray->line_height >> 1) + (mlx->half_height + ray->offset);
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT;
	if (!ray->side)
	{
		if (ray->ray_dir_x > 0)
			door_or_wall(cube, ray, mlx, &mlx->wall_we);
		else
			door_or_wall(cube, ray, mlx, &mlx->wall_ea);
	}
	else
	{
		if (ray->ray_dir_y > 0)
			door_or_wall(cube, ray, mlx, &mlx->wall_no);
		else
			door_or_wall(cube, ray, mlx, &mlx->wall_so);
	}
}

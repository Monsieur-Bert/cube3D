/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:55:45 by antauber          #+#    #+#             */
/*   Updated: 2025/04/07 16:30:18 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

void	draw_background(t_cube *cube)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIN_W)
	{
		y = cube->ray.prev_start[x];
		while (y < (cube->mlx.half_height) + cube->ray.offset && y <= WIN_H)
			ft_put_pixel(&cube->mlx.render, x, y++, cube->map.ceiling);
		while (y < cube->ray.prev_end[x] && y <= WIN_H)
			ft_put_pixel(&cube->mlx.render, x, y++, cube->map.floor);
		x++;
	}
}

void	ft_put_pixel(t_img *img, int x, int y, int color)
{
	int	pixel;

	pixel = y * img->line_len + ((x * img->bpp) >> 3);
	img->addr[pixel] = color & 255;
	img->addr[pixel + 1] = (color >> 8) & 255;
	img->addr[pixel + 2] = (color >> 16) & 255;
}

static void	find_texture_pixel(t_text *text, t_ray *ray)
{
	text->x = (int)(ray->wall_x * 64);
	if (!ray->side && ray->ray_dir_x > 0)
		text->x = 64 - text->x - 1;
	if (ray->side && ray->ray_dir_y < 0)
		text->x = 64 - text->x - 1;
	text->step = 1.0 * (double)64 / ray->line_height;
	text->pos = (ray->draw_start - ((WIN_H >> 1) + ray->offset)
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
	while (ray->draw_start < ray->draw_end && ray->draw_start < WIN_H)
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

void	draw_walls(t_ray *ray, t_mlx *mlx)
{
	ray->line_height = (int)(WIN_H / ray->perp_wall_dist);
	ray->draw_start = - (ray->line_height >> 1)
		+ (mlx->half_height + ray->offset);
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (ray->line_height >> 1) + (mlx->half_height + ray->offset);
	if (ray->draw_end >= WIN_H)
		ray->draw_end = WIN_H;
	ray->prev_start[ray->x] = ray->draw_start;
	ray->prev_end[ray->x] = ray->draw_end;
	if (!ray->side)
	{
		if (ray->ray_dir_x > 0)
			add_wall_texture(&mlx->render, &mlx->wall_we, ray);
		else
			add_wall_texture(&mlx->render, &mlx->wall_ea, ray);
	}
	else
	{
		if (ray->ray_dir_y > 0)
			add_wall_texture(&mlx->render, &mlx->wall_no, ray);
		else
			add_wall_texture(&mlx->render, &mlx->wall_so, ray);
	}
}

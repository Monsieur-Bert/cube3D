/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:39:33 by antauber          #+#    #+#             */
/*   Updated: 2025/04/07 16:15:40 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

static t_img	update_sprite_animation(t_mlx *mlx, double delta_time)
{
	static int	frame = 0;

	mlx->sprite_timer += delta_time;
	if (mlx->sprite_timer > SPRITE_SPEED)
	{
		mlx->sprite_timer = 0;
		frame++;
		if (frame > 3)
			frame = 0;
	}
	return (mlx->spt_fire[frame]);
}

static void	init_sprites(t_cube *cube, t_spt **sprites)
{
	t_spt	*curr;

	curr = *sprites;
	while (curr)
	{
		curr->dist = (cube->ray.pos_x - curr->x) * (cube->ray.pos_x - curr->x)
			- (cube->ray.pos_y - curr->y) * (cube->ray.pos_y - curr->y);
		curr = curr->next;
	}
	sort_sprites(sprites, true);
}

static void	init_ray_sprite(t_cube *cube, t_ray_spt *r_spt, t_spt *tmp)
{
	r_spt->sprite_x = tmp->x - cube->ray.pos_x;
	r_spt->sprite_y = tmp->y - cube->ray.pos_y;
	r_spt->inv_det = 1.0 / (cube->ray.plane_x * cube->ray.dir_y
			- cube->ray.dir_x * cube->ray.plane_y);
	r_spt->trans_x = r_spt->inv_det * (cube->ray.dir_y * r_spt->sprite_x
			- cube->ray.dir_x * r_spt->sprite_y);
	r_spt->trans_y = r_spt->inv_det * (-cube->ray.plane_y * r_spt->sprite_x
			+ cube->ray.plane_x * r_spt->sprite_y);
	r_spt->screen_x = (int)cube->mlx.half_width
		* (1 + r_spt->trans_x / r_spt->trans_y);
	r_spt->height = fabs((int)WIN_H / r_spt->trans_y);
	r_spt->start_y = floor(-r_spt->height * 0.5
			+ cube->mlx.half_height + cube->ray.offset);
	if (r_spt->start_y < 0)
		r_spt->start_y = 0;
	r_spt->end_y = r_spt->height * 0.5 + cube->mlx.half_height
		+ cube->ray.offset;
	r_spt->width = fabs((int)WIN_H / r_spt->trans_y);
	r_spt->start_x = floor(-r_spt->width * 0.5 + r_spt->screen_x);
	if (r_spt->start_x < 0)
		r_spt->start_x = 0;
	r_spt->end_x = r_spt->width * 0.5 + r_spt->screen_x;
	if (r_spt->end_x >= WIN_W)
		r_spt->end_x = WIN_W;
}

static void	draw_stripes(t_cube *cube, t_img *curr_spt, t_ray_spt *r_spt)
{
	if (r_spt->trans_y > 0 && r_spt->stripe > 0 && r_spt->stripe < WIN_W
		&& r_spt->trans_y < cube->ray.z_buffer[r_spt->stripe])
	{
		r_spt->y = r_spt->start_y;
		while (r_spt->y < r_spt->end_y)
		{
			r_spt->d = (r_spt->y - cube->ray.offset) * 256 - WIN_H
				* 128 + r_spt->height * 128;
			r_spt->text_y = ((r_spt->d * curr_spt->height / r_spt->height)
					/ 256);
			r_spt->text_y = fmax(0, fmin(r_spt->text_y, curr_spt->height - 1));
			r_spt->text_pxl = r_spt->text_y * curr_spt->line_len
				+ r_spt->text_x * (curr_spt->bpp / 8);
			r_spt->text_color = *(int *)(curr_spt->addr + r_spt->text_pxl);
			if (r_spt->text_color != 0x000000 && r_spt->y >= 0
				&& r_spt->y < WIN_H && r_spt->stripe >= 0
				&& r_spt->stripe < WIN_W)
				ft_put_pixel(&cube->mlx.render, r_spt->stripe, r_spt->y,
					r_spt->text_color);
			r_spt->y++;
		}
	}
}

void	draw_sprites(t_cube *cube, double delta_time)
{
	t_spt		*tmp;
	t_img		curr_spt;
	t_ray_spt	r_spt;

	init_sprites(cube, &cube->mlx.sprites);
	curr_spt = update_sprite_animation(&cube->mlx, delta_time);
	tmp = cube->mlx.sprites;
	while (tmp)
	{
		init_ray_sprite(cube, &r_spt, tmp);
		r_spt.stripe = r_spt.start_x;
		while (r_spt.stripe < r_spt.end_x && r_spt.stripe < WIN_W)
		{
			r_spt.relative_x = (double)(r_spt.stripe
					- (r_spt.screen_x - r_spt.width * 0.5)) / r_spt.width;
			r_spt.text_x = (int)(r_spt.relative_x * curr_spt.width);
			r_spt.y = 0;
			r_spt.text_x = fmax(0, fmin(r_spt.text_x, curr_spt.width - 1));
			draw_stripes(cube, &curr_spt, &r_spt);
			r_spt.stripe++;
		}
		tmp = tmp->next;
	}
}

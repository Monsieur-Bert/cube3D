/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:25:41 by antauber          #+#    #+#             */
/*   Updated: 2025/04/07 14:06:09 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>



//********************************************UTILS SPIRTES


// static bool	is_moving(t_mlx *mlx)
// {
// 	int	i;

// 	if (mlx->keys[0])
// 	{
// 		mlx->keys[0] = false;
// 		return (true);
// 	}
// 	i = 0;
// 	while (i < Q_QUIT)
// 	{
// 		if (mlx->keys[i])
// 			return (true);
// 		i++;
// 	}
// 	return (false);
// }

static double	get_time_in_seconds(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((double)tv.tv_sec + (double)tv.tv_usec / 1000000.0);
}


void	init_sprites(t_cube *cube, t_spt **sprites)
{
	t_spt	*curr;

	curr = *sprites;
	while (curr)
	{
		curr->dist = (cube->ray.pos_x - curr->x) * (cube->ray.pos_x - curr->x)
			- (cube->ray.pos_y - curr->y) * (cube->ray.pos_y - curr->y);
		curr = curr->next;
	}
	sort_sprites(sprites);
}


t_img update_sprite_animation(t_mlx *mlx, double delta_time)
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
	return (mlx->sprite_fire[frame]);
}

void	draw_sprites(t_cube *cube, double delta_time)
{
	t_spt *tmp;
	t_img	curr_sprite;
	
	curr_sprite = update_sprite_animation(&cube->mlx, delta_time);
	tmp = cube->mlx.sprites;
	while (tmp)
	{
		//translate sprite position
		double sprite_x = tmp->x - cube->ray.pos_x;
		double sprite_y = tmp->y - cube->ray.pos_y;
		
		//transform
		double inv_det = 1.0 / (cube->ray.plane_x * cube->ray.dir_y - cube->ray.dir_x * cube->ray.plane_y);
		double transform_x = inv_det * (cube->ray.dir_y * sprite_x - cube->ray.dir_x * sprite_y);
		double transform_y = inv_det * (- cube->ray.plane_y * sprite_x + cube->ray.plane_x * sprite_y);
		int	sprite_screen_x = (int)cube->mlx.half_width * (1 + transform_x / transform_y);
		
		//calculate height of the sprite screen
		int	sprite_height = fabs((int)WIN_HEIGHT / transform_y);

		//calculate lowest and highest pixest to fill i  current stripe
		int	draw_start_y = floor(- sprite_height * 0.5 + cube->mlx.half_height + cube->ray.offset);
		if (draw_start_y < 0)
			draw_start_y = 0;
		int draw_end_y = sprite_height * 0.5 + cube->mlx.half_height + cube->ray.offset;

		//calculate width of the sprite
		int sprite_width = fabs((int)WIN_HEIGHT / transform_y);
		int draw_start_x = floor(- sprite_width * 0.5 + sprite_screen_x);
		if(draw_start_x < 0)
			draw_start_x = 0;
		int draw_end_x = sprite_width * 0.5 + sprite_screen_x;
		if(draw_end_x >= WIN_WIDTH)
			draw_end_x = WIN_WIDTH;

		//loop throught every vertuical sptripe
		int stripe = draw_start_x;
		int y;
		while (stripe < draw_end_x && stripe < WIN_WIDTH)
		{
			
			// int tex_x = (int)((stripe - draw_start_x) * curr_sprite.width / sprite_width);
			// int tex_x = (int)((stripe - (-sprite_width * 0.5 + sprite_screen_x)) * curr_sprite.width / sprite_width);
			// Calculer la position relative du stripe dans la largeur du sprite (de 0 à 1)
			double relative_x = (double)(stripe - (sprite_screen_x - sprite_width * 0.5)) / sprite_width;
			int tex_x = (int)(relative_x * curr_sprite.width);
			tex_x = fmax(0, fmin(tex_x, curr_sprite.width - 1));

			if (transform_y > 0 && stripe > 0 && stripe < WIN_WIDTH && transform_y < cube->ray.z_buffer[stripe])
			{
				y = draw_start_y;
				while (y < draw_end_y)
				{
					int d = (y - cube->ray.offset) * 256 - WIN_HEIGHT * 128 + sprite_height * 128;
					int text_y = ((d * curr_sprite.height / sprite_height) / 256);
					text_y = fmax(0, fmin(text_y, curr_sprite.height - 1));
					int	tex_pxl = text_y * curr_sprite.line_len + tex_x * (curr_sprite.bpp / 8);
					int text_color = *(int *)(curr_sprite.addr + tex_pxl);
					if (text_color != 0x000000 && y >= 0 && y < WIN_HEIGHT && stripe >= 0 && stripe < WIN_WIDTH)
						ft_put_pixel(&cube->mlx.render, stripe, y, text_color);

					y++;
				}

			}
			stripe++;
		}
			
		tmp = tmp->next;
	}
	
}

int	render(t_cube *cube)
{
	static double	last_time = 0;
	double			curr_time;
	double			delta_time;

	curr_time = get_time_in_seconds();
	if (last_time == 0)
		last_time = curr_time;
	delta_time = curr_time - last_time;
	last_time = curr_time;
	if (cube->mlx.win != NULL)
	{
		draw_background(cube);
		move_player(cube, delta_time);
		raycaster(cube);
		draw_sprites(cube, delta_time);
		if (cube->mlx.keys[MAP])
			minimap(cube);
		mlx_put_image_to_window(cube->mlx.init, cube->mlx.win,
			cube->mlx.render.img, 0, 0);
	}
	return (0);
}

void	graphics(t_cube *cube)
{
	init_mlx(&cube->mlx);
	cube->mlx.init = mlx_init();
	if (!cube->mlx.init)
		free_error(cube, ERR_MLX_INIT);
	cube->mlx.win = mlx_new_window(cube->mlx.init, WIN_WIDTH,
			WIN_HEIGHT, "cube_3D");
	if (!cube->mlx.win)
		free_error(cube, ERR_MLX_WIN);
	cube->mlx.render.img = mlx_new_image(cube->mlx.init, WIN_WIDTH, WIN_HEIGHT);
	if (!cube->mlx.render.img)
		free_error(cube, ERR_MLX_RENDER);
	cube->mlx.render.addr = mlx_get_data_addr(cube->mlx.render.img,
			&cube->mlx.render.bpp, &cube->mlx.render.line_len,
			&cube->mlx.render.endian);
	if (!cube->mlx.render.addr)
		free_error(cube, ERR_MLX_RENDER);
	set_keystab(cube);
	set_player(&cube->ray, &cube->map);
	if (!get_walls_textures(&cube->mlx, &cube->map))
		free_error(cube, ERR_MLX_TEXT);

	/*------SPRITES---------------*/
	if (!get_sprites_textures(&cube->mlx))
		free_error(cube, ERR_MLX_SPRITE);

	
	/*--------------------------*/
	
	mlx_loop_hook(cube->mlx.init, &render, cube);
	mlx_hook(cube->mlx.win, DestroyNotify, StructureNotifyMask,
		close_window, cube);
	mlx_hook(cube->mlx.win, MotionNotify, PointerMotionMask, mouse_hook, cube);
	mlx_hook(cube->mlx.win, KeyPress, KeyPressMask, key_press, cube);
	mlx_hook(cube->mlx.win, KeyRelease, KeyReleaseMask, key_release, cube);
	mlx_loop(cube->mlx.init);
}

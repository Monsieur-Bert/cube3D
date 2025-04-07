/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:20:55 by antauber          #+#    #+#             */
/*   Updated: 2025/04/07 16:08:42 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

static void	move_forward_backward(t_cube *cube, int dir, double speed)
{
	if (cube->map.map[(int)(cube->ray.pos_y)]
		[(int)(cube->ray.pos_x + cube->ray.dir_x * speed * dir)] != '1')
		cube->ray.pos_x += cube->ray.dir_x * speed * dir;
	if (cube->map.map[(int)(cube->ray.pos_y + cube->ray.dir_y * speed * dir)]
		[(int)(cube->ray.pos_x)] != '1')
		cube->ray.pos_y += cube->ray.dir_y * speed * dir;
}

static void	move_right_left(t_cube *cube, int dir, double speed)
{
	if (cube->map.map[(int)(cube->ray.pos_y)]
		[(int)(cube->ray.pos_x - cube->ray.dir_y * speed * dir)] != '1')
		cube->ray.pos_x -= cube->ray.dir_y * speed * dir;
	if (cube->map.map[(int)(cube->ray.pos_y + cube->ray.dir_x * speed * dir)]
		[(int)(cube->ray.pos_x)] != '1')
		cube->ray.pos_y += cube->ray.dir_x * speed * dir;
}

void	rotate_player(t_ray *ray, int dir, double speed)
{
	double	old_dir_x;
	double	old_plane_x;
	double	cos_angle;
	double	sin_angle;

	cos_angle = cos(speed * dir);
	sin_angle = sin(speed * dir);
	old_dir_x = ray->dir_x;
	ray->dir_x = ray->dir_x * cos_angle - ray->dir_y * sin_angle;
	ray->dir_y = old_dir_x * sin_angle + ray->dir_y * cos_angle ;
	old_plane_x = ray->plane_x;
	ray->plane_x = ray->plane_x * cos_angle - ray->plane_y * sin_angle;
	ray->plane_y = old_plane_x * sin_angle + ray->plane_y * cos_angle ;
}

void	move_player(t_cube *cube, double delta_time)
{
	double	move_speed;
	double	rot_speed;

	move_speed = MOVE_SPEED * delta_time;
	rot_speed = ROT_SPEED * delta_time;
	if (cube->mlx.keys[LR_MV_BOOST] == true)
		move_speed *= 1.5;
	if (cube->mlx.keys[W_MV_FOR] == true)
		move_forward_backward(cube, 1, move_speed);
	if (cube->mlx.keys[S_MV_BACK] == true)
		move_forward_backward(cube, -1, move_speed);
	if (cube->mlx.keys[D_MV_RIGHT] == true)
		move_right_left(cube, 1, move_speed);
	if (cube->mlx.keys[A_MV_LEFT] == true)
		move_right_left(cube, -1, move_speed);
	if (cube->mlx.keys[R_RT_RIGHT] == true)
		rotate_player(&cube->ray, 1, rot_speed);
	if (cube->mlx.keys[L_RT_LEFT] == true)
		rotate_player(&cube->ray, -1, rot_speed);
	if (cube->mlx.keys[U_RT_UP] == true
		&& (cube->mlx.half_height + cube->ray.offset < WIN_H))
		cube->ray.offset += 600 * delta_time;
	if (cube->mlx.keys[D_RT_DOWN] == true
		&& (cube->mlx.half_height + cube->ray.offset > 0))
		cube->ray.offset -= 600 * delta_time;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:43:37 by ygorget           #+#    #+#             */
/*   Updated: 2025/03/25 10:53:55 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

static void	move_forward_backward(t_cube *cube, int dir, double speed)
{
	if(cube->map.map[(int)(cube->ray.pos_y)][(int)(cube->ray.pos_x + cube->ray.dir_x * speed * dir)] != '1')
		cube->ray.pos_x += cube->ray.dir_x * speed * dir;
	if(cube->map.map[(int)(cube->ray.pos_y + cube->ray.dir_y * speed * dir)][(int)(cube->ray.pos_x)] != '1')
		cube->ray.pos_y += cube->ray.dir_y * speed * dir;
}

static void	move_right_left(t_cube *cube, int dir, double speed)
{
	if(cube->map.map[(int)(cube->ray.pos_y)][(int)(cube->ray.pos_x - cube->ray.dir_y * speed * dir)] != '1')
		cube->ray.pos_x -= cube->ray.dir_y * speed * dir;
	if(cube->map.map[(int)(cube->ray.pos_y + cube->ray.dir_x * speed * dir)][(int)(cube->ray.pos_x)] != '1')
		cube->ray.pos_y += cube->ray.dir_x * speed * dir;
}

static void	rotate_player(t_ray *ray, int dir, double speed)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = ray->dir_x;
	ray->dir_x = ray->dir_x * cos(speed * dir) - ray->dir_y * sin(speed * dir);
	ray->dir_y = old_dir_x * sin(speed * dir) + ray->dir_y * cos(speed * dir);
	old_plane_x = ray->plane_x;
	ray->plane_x =  ray->plane_x * cos(speed * dir) -  ray->plane_y * sin(speed * dir);
	ray->plane_y = old_plane_x * sin(speed * dir) + ray->plane_y * cos(speed * dir);
}

void	move_player(t_cube *cube, double delta_time)
{
	if (cube->mlx.keys[W_MV_FOR] == true)
		move_forward_backward(cube, 1, MOVE_SPEED * delta_time);
	if (cube->mlx.keys[S_MV_BACK] == true)
		move_forward_backward(cube, -1, MOVE_SPEED * delta_time);
	if (cube->mlx.keys[D_MV_RIGHT] == true)
		move_right_left(cube, 1, MOVE_SPEED * delta_time);
	if (cube->mlx.keys[A_MV_LEFT] == true)
		move_right_left(cube, -1, MOVE_SPEED * delta_time);
	if (cube->mlx.keys[R_RT_RIGHT] == true)
		rotate_player(&cube->ray, 1, ROT_SPEED * delta_time);
	if (cube->mlx.keys[L_RT_LEFT] == true)
		rotate_player(&cube->ray, -1, ROT_SPEED * delta_time);
}

int	key_press(int keysym, t_cube *cube)
{
	if (keysym == XK_w)
		cube->mlx.keys[W_MV_FOR] = true;
	if (keysym == XK_s)
		cube->mlx.keys[S_MV_BACK] = true;
	if (keysym == XK_d)
		cube->mlx.keys[D_MV_RIGHT] = true;
	if (keysym == XK_a)
		cube->mlx.keys[A_MV_LEFT] = true;
	if (keysym == XK_Right)
		cube->mlx.keys[R_RT_RIGHT] = true;
	if (keysym == XK_Left)
		cube->mlx.keys[L_RT_LEFT] = true;
	if (keysym == XK_Escape || keysym == XK_q)
		close_window(cube);
	return (0);
}

int	key_release(int keysym, t_cube *cube)
{
	if (keysym == XK_w)
		cube->mlx.keys[W_MV_FOR] = false;
	if (keysym == XK_s)
		cube->mlx.keys[S_MV_BACK] = false;
	if (keysym == XK_d)
		cube->mlx.keys[D_MV_RIGHT] = false;
	if (keysym == XK_a)
		cube->mlx.keys[A_MV_LEFT] = false;
	if (keysym == XK_Right)
		cube->mlx.keys[R_RT_RIGHT] = false;
	if (keysym == XK_Left)
		cube->mlx.keys[L_RT_LEFT] = false;
	return (0);
}

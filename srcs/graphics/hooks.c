/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:43:37 by ygorget           #+#    #+#             */
/*   Updated: 2025/03/18 10:29:24 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

void	move_forward_backward(t_cube *cube, int dir)
{
	if(cube->map.map[(int)((cube->ray.pos_x) - cube->ray.dir_x * MOVE_SPEED * dir)][(int)(cube->ray.pos_y)] != '1')
		cube->ray.pos_x += cube->ray.dir_x * MOVE_SPEED * dir;
	if(cube->map.map[(int)(cube->ray.pos_x)][(int)((cube->ray.pos_y) - cube->ray.dir_y * MOVE_SPEED * dir)] != '1')
		cube->ray.pos_y += cube->ray.dir_y * MOVE_SPEED * dir;
}

void	move_right_left(t_cube *cube, int dir)
{
	if(cube->map.map[(int)(cube->ray.pos_y)][(int)(cube->ray.pos_x - cube->ray.dir_y * MOVE_SPEED * dir)] != '1')
		cube->ray.pos_x -= cube->ray.dir_y * MOVE_SPEED * dir;
	if(cube->map.map[(int)(cube->ray.pos_y + cube->ray.dir_x * MOVE_SPEED * dir)][(int)(cube->ray.pos_x)] != '1')
		cube->ray.pos_y += cube->ray.dir_x * MOVE_SPEED * dir;
}

void	rotate_player(t_ray *ray, int dir)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = ray->dir_x;
	ray->dir_x = ray->dir_x * cos(ROT_SPEED * dir) - ray->dir_y * sin(ROT_SPEED * dir);
	ray->dir_y = old_dir_x * sin(ROT_SPEED * dir) + ray->dir_y * cos(ROT_SPEED * dir);
	old_plane_x = ray->plane_x;
	ray->plane_x =  ray->plane_x * cos(ROT_SPEED * dir) -  ray->plane_y * sin(ROT_SPEED * dir);
	ray->plane_y = old_plane_x * sin(ROT_SPEED * dir) + ray->plane_y * cos(ROT_SPEED * dir);
}

void	move_player(int keysym, t_cube *cube)
{
	if (keysym == XK_w)
		move_forward_backward(cube, 1);
	if (keysym == XK_s)
		move_forward_backward(cube, -1);
	if (keysym == XK_d)
		move_right_left(cube, 1);
	if (keysym == XK_a)
		move_right_left(cube, -1);
	if (keysym == XK_Right)
		rotate_player(&cube->ray, 1);
	if (keysym == XK_Left)
		rotate_player(&cube->ray, -1);
}

int handle_keyhooks(int keysym, t_cube *cube)
{
	if (keysym == XK_Escape || keysym == XK_q)
		close_window(cube);

	move_player(keysym, cube);
	return (0);
}

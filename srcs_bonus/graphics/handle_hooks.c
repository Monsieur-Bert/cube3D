/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:43:37 by ygorget           #+#    #+#             */
/*   Updated: 2025/04/08 10:15:49 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

int	mouse_hook(int x, int y, t_cube *cube)
{
	double	delta_x;
	double	delta_y;
	double	rot_speedy;
	double	rot_speedx;

	if (cube->mlx.keys[MOUSE] == false)
		return (1);
	delta_x = x - cube->mlx.half_width;
	delta_y = y - cube->mlx.half_height;
	rot_speedx = (delta_x / (cube->mlx.half_width) * MOUSE_SENSI);
	rot_speedy = (-delta_y / (cube->mlx.half_height)) * MOUSE_SENSI * 60;
	if (delta_x > 0)
		rotate_player(&cube->ray, 1, fabs(rot_speedx));
	if (delta_x < 0)
		rotate_player(&cube->ray, -1, fabs(rot_speedx));
	if (cube->ray.offset + rot_speedy > -cube->mlx.half_height
		&& cube->ray.offset + rot_speedy < cube->mlx.half_height)
		cube->ray.offset += rot_speedy;
	if (delta_x != 0 || delta_y != 0)
		mlx_mouse_move(cube->mlx.init, cube->mlx.win, cube->mlx.half_width,
			cube->mlx.half_height);
	return (0);
}

int	key_release(int keysym, t_cube *cube)
{
	if (keysym == XK_Shift_R)
		cube->mlx.keys[LR_MV_BOOST] = false;
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
	if (keysym == XK_Up)
		cube->mlx.keys[U_RT_UP] = false;
	if (keysym == XK_Down)
		cube->mlx.keys[D_RT_DOWN] = false;
	return (0);
}

static void	activ_map_n_mouse(int keysym, t_cube *cube)
{
	if (keysym == XK_space)
		cube->mlx.keys[SPACE] = true;
	if (keysym == XK_m)
	{
		cube->mlx.keys[MOUSE] = !cube->mlx.keys[MOUSE];
		if (cube->mlx.keys[MOUSE])
			mlx_mouse_hide(cube->mlx.init, cube->mlx.win);
		else
			mlx_mouse_show(cube->mlx.init, cube->mlx.win);
	}
	if (keysym == XK_p)
		cube->mlx.keys[MAP] = !cube->mlx.keys[MAP];
}

int	key_press(int keysym, t_cube *cube)
{
	if (keysym == XK_Shift_R)
		cube->mlx.keys[LR_MV_BOOST] = true;
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
	if (keysym == XK_Up)
		cube->mlx.keys[U_RT_UP] = true;
	if (keysym == XK_Down)
		cube->mlx.keys[D_RT_DOWN] = true;
	activ_map_n_mouse(keysym, cube);
	if (keysym == XK_Escape || keysym == XK_q)
		close_window(cube);
	return (0);
}

void	set_keystab(t_cube *cube)
{
	int	i;

	i = 0;
	cube->mlx.keys = malloc((sizeof(int) * (Q_QUIT + 1)));
	if (cube->mlx.keys == NULL)
		free_error(cube, ERR_MALLOC);
	cube->mlx.keys[i++] = true;
	while (i <= Q_QUIT)
		cube->mlx.keys[i++] = false;
}

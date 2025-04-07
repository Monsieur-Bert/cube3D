/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:25:41 by antauber          #+#    #+#             */
/*   Updated: 2025/04/07 16:08:42 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

static bool	is_moving(t_mlx *mlx)
{
	int	i;

	if (mlx->keys[0])
	{
		mlx->keys[0] = false;
		return (true);
	}
	i = 0;
	while (i < Q_QUIT)
	{
		if (mlx->keys[i])
			return (true);
		i++;
	}
	return (false);
}

static double	get_time_in_seconds(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((double)tv.tv_sec + (double)tv.tv_usec / 1000000.0);
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
	if (cube->mlx.win != NULL && is_moving(&cube->mlx))
	{
		draw_background(cube);
		move_player(cube, delta_time);
		raycaster(cube);
		if (cube->mlx.keys[MAP])
			minimap(cube);
		mlx_put_image_to_window(cube->mlx.init, cube->mlx.win,
			cube->mlx.render.img, 0, 0);
	}
	return (0);
}

void	build_mlx(t_cube *cube)
{
	if (!cube->mlx.init)
		free_error(cube, ERR_MLX_INIT);
	cube->mlx.win = mlx_new_window(cube->mlx.init, WIN_W,
			WIN_H, "cube_3D");
	if (!cube->mlx.win)
		free_error(cube, ERR_MLX_WIN);
	cube->mlx.render.img = mlx_new_image(cube->mlx.init, WIN_W, WIN_H);
	if (!cube->mlx.render.img)
		free_error(cube, ERR_MLX_RENDER);
	cube->mlx.render.addr = mlx_get_data_addr(cube->mlx.render.img,
			&cube->mlx.render.bpp, &cube->mlx.render.line_len,
			&cube->mlx.render.endian);
	if (!cube->mlx.render.addr)
		free_error(cube, ERR_MLX_RENDER);
}

void	graphics(t_cube *cube)
{
	init_mlx(&cube->mlx);
	cube->mlx.init = mlx_init();
	build_mlx(cube);
	set_keystab(cube);
	set_player(&cube->ray, &cube->map);
	if (!get_walls_textures(&cube->mlx, &cube->map))
		free_error(cube, ERR_MLX_TEXT);
	mlx_loop_hook(cube->mlx.init, &render, cube);
	mlx_hook(cube->mlx.win, DestroyNotify, StructureNotifyMask,
		close_window, cube);
	mlx_hook(cube->mlx.win, MotionNotify, PointerMotionMask, mouse_hook, cube);
	mlx_hook(cube->mlx.win, KeyPress, KeyPressMask, key_press, cube);
	mlx_hook(cube->mlx.win, KeyRelease, KeyReleaseMask, key_release, cube);
	mlx_loop(cube->mlx.init);
}

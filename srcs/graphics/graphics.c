/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:25:41 by antauber          #+#    #+#             */
/*   Updated: 2025/03/26 16:31:44 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

void	free_walls_textures(t_mlx *mlx)
{
	if (mlx->wall_no.img != NULL)
	{
		mlx_destroy_image(mlx->init, mlx->wall_no.img);
		mlx->wall_no.img = NULL;
		mlx->wall_no.addr = NULL;
	}
	if (mlx->wall_so.img != NULL)
	{
		mlx_destroy_image(mlx->init, mlx->wall_so.img);
		mlx->wall_so.img = NULL;
		mlx->wall_so.addr = NULL;
	}
	if (mlx->wall_we.img != NULL)
	{
		mlx_destroy_image(mlx->init, mlx->wall_we.img);
		mlx->wall_we.img = NULL;
		mlx->wall_we.addr = NULL;
	}
	if (mlx->wall_ea.img != NULL)
	{
		mlx_destroy_image(mlx->init, mlx->wall_ea.img);
		mlx->wall_ea.img = NULL;
		mlx->wall_ea.addr = NULL;
	}
}

void	free_mlx(t_mlx *mlx)
{
	free_walls_textures(mlx);
	free(mlx->keys);
	if (mlx->render.img != NULL)
	{
		mlx_destroy_image(mlx->init, mlx->render.img);
		mlx->render.img = NULL;
		mlx->render.addr = NULL;
	}
	if (mlx->win != NULL)
	{
		mlx_destroy_window(mlx->init, mlx->win);
		mlx->win = NULL;
	}
	if (mlx->init != NULL)
	{
		mlx_destroy_display(mlx->init);
		free(mlx->init);
		mlx->init = NULL;
	}
}

int	close_window(t_cube *cube)
{
	if (cube->mlx.win != NULL)
		free_mlx(&cube->mlx);
	ft_free_tabstr(cube->tab);
	exit (0);
}

void	free_error(t_cube *cube, char *error_message)
{
	free_mlx(&cube->mlx);
	ft_free_tabstr(cube->tab);
	print_error(error_message);
	exit (1);
}

static void	init_img(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = 0;
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

void	init_mlx(t_mlx *mlx)
{
	init_img(&mlx->render);
	init_img(&mlx->wall_no);
	init_img(&mlx->wall_so);
	init_img(&mlx->wall_we);
	init_img(&mlx->wall_ea);
	mlx->keys = NULL;
	mlx->init = NULL;
	mlx->win = NULL;
}

static bool	get_walls_addr(t_mlx *mlx)
{
	mlx->wall_no.addr = mlx_get_data_addr(mlx->wall_no.img, &mlx->wall_no.bpp, 
		&mlx->wall_no.line_len, &mlx->wall_no.endian);
	if (!mlx->wall_no.addr)
		return (false);
	mlx->wall_so.addr = mlx_get_data_addr(mlx->wall_so.img, &mlx->wall_so.bpp, 
		&mlx->wall_so.line_len, &mlx->wall_so.endian);
	if (!mlx->wall_no.addr)
		return (false);
	mlx->wall_we.addr = mlx_get_data_addr(mlx->wall_we.img, &mlx->wall_we.bpp, 
		&mlx->wall_we.line_len, &mlx->wall_we.endian);
	if (!mlx->wall_no.addr)
		return (false);
	mlx->wall_ea.addr = mlx_get_data_addr(mlx->wall_ea.img, &mlx->wall_ea.bpp, 
		&mlx->wall_ea.line_len, &mlx->wall_ea.endian);
	if (!mlx->wall_no.addr)
		return (false);
	return (true);
}

static bool	get_walls_textures(t_mlx *mlx, t_map *map)
{
	mlx->wall_no.img = mlx_xpm_file_to_image(mlx->init, map->img.no,
			&mlx->wall_no.width, &mlx->wall_no.height);
	if (!mlx->wall_no.img)
		return (false);
	mlx->wall_so.img = mlx_xpm_file_to_image(mlx->init, map->img.so,
			&mlx->wall_so.width, &mlx->wall_so.height);
	if (!mlx->wall_so.img)
		return (false);
	mlx->wall_we.img = mlx_xpm_file_to_image(mlx->init, map->img.we,
			&mlx->wall_we.width, &mlx->wall_we.height);
	if (!mlx->wall_we.img)
		return (false);
	mlx->wall_ea.img = mlx_xpm_file_to_image(mlx->init, map->img.ea,
			&mlx->wall_ea.width, &mlx->wall_ea.height);
	if (!mlx->wall_ea.img)
		return (false);
	if (!get_walls_addr(mlx))
		return (false);
	return (true);
}

bool	is_moving(t_mlx *mlx)
{
	int	i;

	if (mlx->keys[0] == true)
	{
		mlx->keys[0] = false;
		return (true);
	}
	i = 0;
	while (i < Q_QUIT)
	{
		if (mlx->keys[i] == true)
			return (true);
		i++;
	}
	return (false);
}

double	get_time_in_seconds(void)
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
		minimap(cube);
		mlx_put_image_to_window(cube->mlx.init, cube->mlx.win, cube->mlx.render.img, 0, 0);
	}
	return (0);
}

void	graphics(t_cube *cube)
{
	init_mlx(&cube->mlx);
	cube->mlx.init = mlx_init();
	if (!cube->mlx.init)
		free_error(cube, ERR_MLX_INIT);
	cube->mlx.win = mlx_new_window(cube->mlx.init, WIN_WIDTH, WIN_HEIGHT, "cube_3D");
	if (!cube->mlx.win)
		free_error(cube, ERR_MLX_WIN);
	cube->mlx.render.img = mlx_new_image(cube->mlx.init, WIN_WIDTH, WIN_HEIGHT);
	if (!cube->mlx.render.img)
		free_error(cube, ERR_MLX_RENDER);
	cube->mlx.render.addr = mlx_get_data_addr(cube->mlx.render.img, &cube->mlx.render.bpp, &cube->mlx.render.line_len, &cube->mlx.render.endian);
	if (!cube->mlx.render.addr)
		free_error(cube, ERR_MLX_RENDER);

	// INIT VALUES############################
	cube->ray.offset = 0;
	cube->ray.pos_x = cube->map.pos.x + 0.5;
	cube->ray.pos_y = cube->map.pos.y + 0.5;
	set_keystab(cube);
	set_player_dir(&cube->ray, cube->map.pos.pos);
	cube->ray.x = 0;
	for (int i = 0; i < WIN_WIDTH; i++)
	{
		cube->ray.prev_start[i] = 0;
		cube->ray.prev_end[i] = WIN_HEIGHT;
	}
	//########################################
	
	if (!get_walls_textures(&cube->mlx, &cube->map))
		free_error(cube, ERR_MLX_TEXT);
	mlx_loop_hook(cube->mlx.init, &render, cube);
	mlx_hook(cube->mlx.win, DestroyNotify, StructureNotifyMask, close_window, cube);
	mlx_hook(cube->mlx.win, KeyPress, KeyPressMask, key_press, cube);
	mlx_hook(cube->mlx.win, KeyRelease, KeyReleaseMask, key_release, cube);
	mlx_loop(cube->mlx.init);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:30:58 by antauber          #+#    #+#             */
/*   Updated: 2025/04/17 15:10:24 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

static bool	get_sprites_addr(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx->spt_fire[i].addr = mlx_get_data_addr(mlx->spt_fire[i].img,
				&mlx->spt_fire[i].bpp, &mlx->spt_fire[i].line_len,
				&mlx->spt_fire[i].endian);
		if (!mlx->spt_fire[i].addr)
			return (false);
		i++;
	}
	return (true);
}

bool	get_sprites_textures(t_mlx *mlx)
{
	mlx->spt_fire[0].img = mlx_xpm_file_to_image(mlx->init,
			"Xpm/sprites/fire_01.xpm", &mlx->spt_fire[0].width,
			&mlx->spt_fire[0].height);
	if (!mlx->spt_fire[0].img)
		return (false);
	mlx->spt_fire[1].img = mlx_xpm_file_to_image(mlx->init,
			"Xpm/sprites/fire_02.xpm", &mlx->spt_fire[1].width,
			&mlx->spt_fire[1].height);
	if (!mlx->spt_fire[1].img)
		return (false);
	mlx->spt_fire[2].img = mlx_xpm_file_to_image(mlx->init,
			"Xpm/sprites/fire_03.xpm",
			&mlx->spt_fire[2].width, &mlx->spt_fire[2].height);
	if (!mlx->spt_fire[2].img)
		return (false);
	mlx->spt_fire[3].img = mlx_xpm_file_to_image(mlx->init,
			"Xpm/sprites/fire_04.xpm",
			&mlx->spt_fire[3].width, &mlx->spt_fire[3].height);
	if (!mlx->spt_fire[3].img)
		return (false);
	if (!get_sprites_addr(mlx))
		return (false);
	return (true);
}

bool	get_walls_addr(t_mlx *mlx)
{
	mlx->wall_no.addr = mlx_get_data_addr(mlx->wall_no.img, &mlx->wall_no.bpp,
			&mlx->wall_no.line_len, &mlx->wall_no.endian);
	if (!mlx->wall_no.addr)
		return (false);
	mlx->wall_so.addr = mlx_get_data_addr(mlx->wall_so.img, &mlx->wall_so.bpp,
			&mlx->wall_so.line_len, &mlx->wall_so.endian);
	if (!mlx->wall_so.addr)
		return (false);
	mlx->wall_we.addr = mlx_get_data_addr(mlx->wall_we.img, &mlx->wall_we.bpp,
			&mlx->wall_we.line_len, &mlx->wall_we.endian);
	if (!mlx->wall_we.addr)
		return (false);
	mlx->wall_ea.addr = mlx_get_data_addr(mlx->wall_ea.img, &mlx->wall_ea.bpp,
			&mlx->wall_ea.line_len, &mlx->wall_ea.endian);
	if (!mlx->wall_ea.addr)
		return (false);
	mlx->door.addr = mlx_get_data_addr(mlx->door.img, &mlx->door.bpp,
			&mlx->door.line_len, &mlx->door.endian);
	if (!mlx->door.addr)
		return (false);
	return (true);
}

bool	get_walls_textures(t_mlx *mlx, t_map *map)
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
	mlx->door.img = mlx_xpm_file_to_image(mlx->init, "Xpm/door.xpm",
			&mlx->door.width, &mlx->door.height);
	if (!mlx->door.img)
		return (false);
	if (!get_walls_addr(mlx))
		return (false);
	return (true);
}

void	init_mlx(t_mlx *mlx)
{
	init_img(&mlx->render);
	init_img(&mlx->wall_no);
	init_img(&mlx->wall_so);
	init_img(&mlx->wall_we);
	init_img(&mlx->wall_ea);
	init_img(&mlx->spt_fire[0]);
	init_img(&mlx->spt_fire[1]);
	init_img(&mlx->spt_fire[2]);
	init_img(&mlx->spt_fire[3]);
	init_img(&mlx->door);
	mlx->init = NULL;
	mlx->win = NULL;
	mlx->keys = NULL;
	mlx->half_width = WIN_W >> 1;
	mlx->half_height = WIN_H >> 1;
	mlx->sprite_timer = 0;
}

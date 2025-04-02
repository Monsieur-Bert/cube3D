/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:30:58 by antauber          #+#    #+#             */
/*   Updated: 2025/04/02 14:34:02 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

bool	get_sprites_textures(t_mlx *mlx)
{
	mlx->spt_fire.img = mlx_xpm_file_to_image(mlx->init,"Xpm/barrel.xpm",
		&mlx->spt_fire.width, &mlx->spt_fire.height);
	if (!mlx->spt_fire.img)
		return (false);
	mlx->spt_fire.addr = mlx_get_data_addr(mlx->spt_fire.img, &mlx->spt_fire.bpp,
		&mlx->spt_fire.line_len, &mlx->spt_fire.endian);
	if (!mlx->spt_fire.addr)
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
	if (!get_walls_addr(mlx))
		return (false);
	return (true);
}

static void	init_img(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = 0;
}

void	init_mlx(t_mlx *mlx)
{
	init_img(&mlx->render);
	init_img(&mlx->wall_no);
	init_img(&mlx->wall_so);
	init_img(&mlx->wall_we);
	init_img(&mlx->wall_ea);
	init_img(&mlx->spt_fire);
	mlx->init = NULL;
	mlx->win = NULL;
	mlx->keys = NULL;
	mlx->half_width = WIN_WIDTH >> 1;
	mlx->half_height = WIN_HEIGHT >> 1;
}

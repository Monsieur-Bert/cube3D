/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:33:10 by antauber          #+#    #+#             */
/*   Updated: 2025/04/07 13:30:28 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

static void	free_sprites_textures(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (mlx->sprite_fire[i].img != NULL)
			{
				mlx_destroy_image(mlx->init, mlx->sprite_fire[i].img);
				mlx->sprite_fire[i].img = NULL;
				mlx->sprite_fire[i].addr = NULL;
			}
		i++;
	}
}

static void	free_walls_textures(t_mlx *mlx)
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

static void	free_mlx(t_mlx *mlx)
{
	free_sprites_textures(mlx);
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
	sprites_clear(&cube->mlx.sprites);
	ft_free_tabstr(cube->tab);
	exit (0);
}

void	free_error(t_cube *cube, char *error_message)
{
	free_mlx(&cube->mlx);
	sprites_clear(&cube->mlx.sprites);
	ft_free_tabstr(cube->tab);
	print_error(error_message);
	exit (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:26:34 by antauber          #+#    #+#             */
/*   Updated: 2025/04/07 16:27:35 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

void	free_error(t_cube *cube, char *error_message)
{
	free_mlx(&cube->mlx);
	sprites_clear(&cube->mlx.sprites);
	ft_free_tabstr(cube->tab);
	lst_clear(&cube->door);
	print_error(error_message);
	exit (1);
}

void	init_img(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = 0;
}

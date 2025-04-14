/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:55:56 by ygorget           #+#    #+#             */
/*   Updated: 2025/04/14 14:34:54 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

void	print_error(char *str)
{
	ft_printf(2, "Error\n%s", str);
}

static int	parsing(char **tab, t_texture *img, t_map *map)
{
	if (texture(tab, img) == 1)
		return (1);
	if (maps(tab, 0, 5) == 1)
		return (1);
	if (init_struct(tab, img, map) == 1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_texture	img;
	t_cube		cube;

	if (argc != 2)
	{
		print_error(ERR_PARAM);
		return (1);
	}
	init_texture(&img);
	cube.tab = create_tab(argv[1], NULL);
	if (!cube.tab)
		return (1);
	if (parsing(cube.tab, &img, &cube.map) == 1)
	{
		ft_free_tabstr(cube.tab);
		return (1);
	}
	graphics(&cube);
	return (0);
}

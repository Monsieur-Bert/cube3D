/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:55:56 by ygorget           #+#    #+#             */
/*   Updated: 2025/03/24 14:59:03 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

//libft
// void	*ft_free_tabstr(char **tab)
// {
// 	int	i;

// 	i = 0;
// 	if (!tab)
// 		return (NULL);
// 	while (tab[i])
// 	{
// 		free(tab[i]);
// 		tab[i] = NULL;
// 		i++;
// 	}
// 	free(tab);
// 	tab = NULL;
// 	return (NULL);
// }

void	print_error(char *str)
{
	ft_printf(2, "Error\n%s", str);
}

// //libft
// bool	ft_isspaces(char c)
// {
// 	if ((c >= '\t' && c <= '\r') || c == ' ')
// 		return (true);
// 	return (false);
// }

int	parsing(char **tab, t_texture *img, t_map *map)
{
	if (texture(tab, img) == 1)
		return (1);
	if (maps(tab, 0) == 1)
		return (1);
	init_struct(tab, img, map);
	return (0);
}

// void	ft_free(t_texture *img, t_map *map)
// {
// 	free(img->no);
// 	free(img->so);
// 	free(img->ea);
// 	free(img->we);
// 	free(img->f);
// 	free(img->c);
// 	ft_free_tabstr(map->map);
// }

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
	cube.tab = create_tab(argv[1]);
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

// for(int i = 0; map.map[i]; ++i)
// 	printf("%s\n", map.map[i]);
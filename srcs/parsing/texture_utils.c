/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:54:09 by ygorget           #+#    #+#             */
/*   Updated: 2025/04/01 15:59:51 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

static int	start_color(char *color, char *str)
{
	if (!color)
	{
		print_error(str);
		return (1);
	}
	if (color[0] == ',')
	{
		print_error(ERR_COLOR);
		return (1);
	}
	return (0);
}

int	check_color(char *color, char *str, int count)
{
	int	i;

	i = -1;
	if (start_color(color, str) == 1)
		return (1);
	while (color[++i])
	{
		while (ft_isspaces(color[i]))
			i++;
		if ((!ft_isdigit(color[i]) && color[i] != ',')
			|| (color[i] == ',' && color[i + 1] && color[i + 1] == ','))
		{
			print_error(ERR_SPACES);
			return (1);
		}
		if (color[i] == ',')
			count++;
	}
	if (!ft_isdigit(color[i - 1]) || count != 2)
	{
		print_error(ERR_COLOR);
		return (1);
	}
	return (0);
}

int	check_space(char *img)
{
	int	i;

	i = 0;
	if (!img)
	{
		print_error(ERR_NO_IMG);
		return (1);
	}
	while (img[i])
	{
		if (ft_isspaces(img[i]))
		{
			print_error(ERR_SPACES);
			return (1);
		}
		i++;
	}
	return (0);
}

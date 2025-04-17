/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:54:09 by ygorget           #+#    #+#             */
/*   Updated: 2025/04/17 13:43:34 by ygorget          ###   ########.fr       */
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

static int	end_color(char *color, int i, int count)
{
	while (ft_isspaces(color[i - 1]))
		i--;
	if (!ft_isdigit(color[i - 1]) || count != 2)
	{
		print_error(ERR_COLOR);
		return (1);
	}
	return (0);
}

static int	error_color(char *color, int digit, int i)
{
	if ((!ft_isdigit(color[i]) && color[i] != ',')
		|| (color[i] == ',' && color[i + 1] && color[i + 1] == ',')
		|| (color[i] == ',' && digit == 1))
	{
		print_error(ERR_COLOR);
		return (1);
	}
	return (0);
}

int	check_color(char *color, char *str, int count, int digit)
{
	int	i;

	i = -1;
	if (start_color(color, str) == 1)
		return (1);
	while (color[++i])
	{
		while (ft_isspaces(color[i]))
			i++;
		if (!color[i])
			break ;
		if (ft_isdigit(color[i]))
			digit = 0;
		if (error_color(color, digit, i) == 1)
			return (1);
		if (color[i] == ',')
		{
			digit++;
			count++;
		}
	}
	if (end_color(color, i, count) == 1)
		return (1);
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
			while (img[++i])
			{
				if (!ft_isspaces(img[i]))
				{
					print_error(ERR_SPACES);
					return (1);
				}
			}
			return (0);
		}
		i++;
	}
	return (0);
}

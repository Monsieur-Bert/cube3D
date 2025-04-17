/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:40:24 by ygorget           #+#    #+#             */
/*   Updated: 2025/04/17 15:00:14 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

static int	good_texture(t_texture *img)
{
	if (check_space(img->no) == 1)
		return (1);
	if (check_space(img->so) == 1)
		return (1);
	if (check_space(img->we) == 1)
		return (1);
	if (check_space(img->ea) == 1)
		return (1);
	if (check_color(img->f, ERR_FLOOR, 0, 0) == 1)
		return (1);
	if (check_color(img->c, ERR_CEILING, 0, 0) == 1)
		return (1);
	return (0);
}

static char	*identifier(char *str, char *to_find)
{
	int	i;
	int	com;
	int	len;

	i = 0;
	com = 1;
	len = ft_strlen(to_find);
	if (to_find[i] == '\0')
		return (str);
	while (str && str[i] != '\0')
	{
		if (!ft_isspaces(str[i]) && str[i] != to_find[0])
			return (0);
		if (str[i] == to_find[0])
		{
			com = ft_strncmp(str, to_find, len);
			if (com == 0)
				return (str);
			else
				return (0);
		}
		str++;
	}
	return (0);
}

static char	*add_texture(char *str, char *text)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i] != text[0])
		i++;
	i += ft_strlen(text);
	while (ft_isspaces(str[i]))
		i++;
	while (str[i + j] && !ft_isspaces(str[i + j]))
		j++;
	str[i + j] = '\0';
	return (&str[i]);
}

static char	*add_color(char *str, char *text)
{
	int	i;

	i = 0;
	while (str[i] != text[0])
		i++;
	i += ft_strlen(text);
	while (ft_isspaces(str[i]))
		i++;
	return (&str[i]);
}

int	texture(char **tab, t_texture *img)
{
	int	i;

	i = 0;
	while (tab[i] && i < 6)
	{
		if (identifier(tab[i], "NO"))
			img->no = add_texture(tab[i], "NO");
		else if (identifier(tab[i], "SO"))
			img->so = add_texture(tab[i], "SO");
		else if (identifier(tab[i], "WE"))
			img->we = add_texture(tab[i], "WE");
		else if (identifier(tab[i], "EA"))
			img->ea = add_texture(tab[i], "EA");
		else if (identifier(tab[i], "F"))
			img->f = add_color(tab[i], "F");
		else if (identifier(tab[i], "C"))
			img->c = add_color(tab[i], "C");
		i++;
	}
	if (good_texture(img) == 1)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:43:30 by ygorget           #+#    #+#             */
/*   Updated: 2025/04/17 13:30:31 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

char	*ft_strstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!big && len == 0)
		return (NULL);
	if (little[i] == '\0')
		return ((char *)big);
	while (*big)
	{
		while ((big[j] == little[i]) && i <= len)
		{
			i++;
			j++;
			if (little[i] == '\0' && big[j] == '\0')
				return ((char *)big);
		}
		i = 0;
		j = 0;
		big++;
	}
	return (0);
}

static void	skip_element(char *str, int *i)
{
	int	info;

	info = 0;
	while (str[++(*i)])
	{
		if (str[*i] == 'N' || str[*i] == 'S' || str[*i] == 'A'
			|| str[*i] == 'W' || str[*i] == 'F' || str[*i] == 'C')
			info++;
		if (info == 6)
		{
			while (str[*i] && str[*i] != '\n')
				(*i)++;
			break ;
		}
	}
}

static int	backslash(char *str)
{
	int	i;

	i = -1;
	skip_element(str, &i);
	while (ft_isspaces(str[i]))
		i++;
	while (str[i] && str[++i])
	{
		if (str[i] == '\n' && str[i - 1] == '\n')
		{
			while (str[i])
			{
				if (str[i] && str[i] != '\n' && !ft_isspaces(str[i]))
				{
					free(str);
					print_error(ERR_CONTENT);
					return (1);
				}
				i++;
			}
		}
	}
	return (0);
}

char	**create_tab(char *file, char *str)
{
	int		fd;
	char	**tab;

	if (!(ft_strstr(file, ".cub", 4)))
	{
		print_error(ERR_FILE);
		return (NULL);
	}
	fd = open(file, O_RDONLY);
	str = read_fd(fd, 0);
	if (!str)
	{
		print_error(ERR_EMPTY);
		return (NULL);
	}
	if (backslash(str) == 1)
		return (NULL);
	tab = ft_split(str, '\n');
	if (!tab)
	{
		print_error(ERR_MALLOC);
		return (NULL);
	}
	free(str);
	return (tab);
}

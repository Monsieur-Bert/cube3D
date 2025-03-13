/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:43:30 by ygorget           #+#    #+#             */
/*   Updated: 2025/03/13 14:40:01 by ygorget          ###   ########.fr       */
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

void	skip_element(char *str, int *i)
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
			while (str[*i] != '\n')
				(*i)++;
			break ;
		}
	}
}

int	backslash(char *str)
{
	int	i;

	i = -1;
	skip_element(str, &i);
	while (str[i] == '\n')
		i++;
	while (str[++i])
	{
		if (str[i] == '\n' && str[i - 1] == '\n')
		{
			free(str);
			return (1);
		}
	}
	return (0);
}

char	**create_tab(char *file)
{
	int		fd;
	char	*str;
	char	**tab;

	if (!(ft_strstr(file, ".cub", 4)))
	{
		print_error(ERR_FILE);
		return (NULL);
	}
	fd = open(file, O_RDONLY);
	str = read_fd(fd, 0);
	if (!str)
		return (NULL);
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

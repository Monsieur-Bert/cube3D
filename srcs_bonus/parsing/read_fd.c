/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:42:47 by ygorget           #+#    #+#             */
/*   Updated: 2025/04/01 16:01:04 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

static void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static char	*new_string(t_buff *node, int count)
{
	char	*str;
	int		len;

	len = ft_strlen(ft_lst_last(node)->buffer);
	str = malloc(sizeof(char) * ((count - 1) * BUFFER_SIZE + len + 1));
	if (!str)
	{
		print_error(ERR_MALLOC);
		return (NULL);
	}
	len = 0;
	while (node->next)
	{
		ft_strcpy(str + len, node->buffer);
		node = node->next;
		len += BUFFER_SIZE;
	}
	ft_strcpy(str + len, node->buffer);
	return (str);
}

char	*read_fd(int fd, int count)
{
	t_buff	*node;
	t_buff	*new_node;
	char	*str;
	int		size;

	new_node = ft_lst_new();
	node = NULL;
	while (1)
	{
		size = read(fd, new_node->buffer, BUFFER_SIZE);
		if (size <= 0)
		{
			free (new_node);
			break ;
		}
		count++;
		ft_lstaddback(&node, new_node);
		new_node = ft_lst_new();
	}
	if (node == NULL)
		return (NULL);
	new_node = node;
	str = new_string(node, count);
	ft_lst_clear(&new_node);
	return (str);
}

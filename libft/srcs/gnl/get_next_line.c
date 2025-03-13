/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 07:49:17 by antauber          #+#    #+#             */
/*   Updated: 2024/12/18 12:20:40 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*reset_store(char *store)
{
	char	*tmp;
	char	*reset;

	tmp = ft_strchr(store, '\n');
	if (tmp == NULL)
	{
		free(store);
		return (NULL);
	}
	reset = gnl_ft_strdup(tmp + 1);
	free(store);
	return (reset);
}

static char	*new_line(char *store, char *line)
{
	int	len_line;
	int	i;

	len_line = 0;
	while (store[len_line] && store[len_line] != '\n')
		len_line++;
	line = malloc(sizeof(char) * (len_line + (store[len_line] == '\n') + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (store[i] && i < len_line)
	{
		line[i] = store[i];
		i++;
	}
	if (store[len_line] && store[len_line] == '\n')
	{
		line[i] = '\n';
		line[i + 1] = '\0';
	}
	else
		line[i] = '\0';
	return (line);
}

static char	*add_to_store(char *store, char *buffer)
{
	int		i;
	int		j;
	char	*str;

	if (!buffer)
		return (NULL);
	if (!store)
		store = gnl_ft_strdup("");
	str = malloc(sizeof(char) * ((gnl_strlen(store) + gnl_strlen(buffer)) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (store[i])
	{
		str[i] = store[i];
		i++;
	}
	j = 0;
	while (buffer[j])
		str[i++] = buffer[j++];
	str[i] = '\0';
	free(store);
	return (str);
}

static char	*read_and_store(int fd, char *store)
{
	int		been_read;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	while (1)
	{
		been_read = read(fd, buffer, BUFFER_SIZE);
		if (been_read == -1 || (been_read == 0 && gnl_strlen(store) == 0))
			return (gnl_to_free(store, buffer));
		buffer[been_read] = '\0';
		store = add_to_store(store, buffer);
		if (store == NULL)
		{
			free(buffer);
			return (NULL);
		}
		if (ft_strchr(store, '\n') || been_read == 0)
			break ;
	}
	free(buffer);
	return (store);
}

char	*get_next_line(int fd)
{
	static char	*store[1024];
	char		*line;	

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	store[fd] = read_and_store(fd, store[fd]);
	if (store[fd] == NULL || (store[fd][0] == '\0' && line == NULL))
		return (NULL);
	line = new_line(store[fd], line);
	if (line == NULL)
		return (NULL);
	store[fd] = reset_store(store[fd]);
	if (store[fd] && store[fd][0] == '\0')
	{
		free (store[fd]);
		store[fd] = NULL;
	}
	return (line);
}

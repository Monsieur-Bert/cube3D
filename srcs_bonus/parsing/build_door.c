/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_door.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:01:45 by ygorget           #+#    #+#             */
/*   Updated: 2025/04/07 15:50:34 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

void	lst_clear(t_door **lst)
{
	t_door	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

t_door	*lstnew(void)
{
	t_door	*node;

	node = malloc(sizeof(*node));
	if (node)
	{
		node->x = 0;
		node->y = 0;
		node->open = false;
		node->next = NULL;
	}
	return (node);
}

void	addback(t_door **node, t_door *new)
{
	t_door	*tmp;

	if (!node || !new)
		return ;
	tmp = *node;
	if (!tmp)
	{
		*node = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

t_door	*door(char **map)
{
	t_door	*node;
	t_door	*new_node;
	int		i;
	int		j;

	i = -1;
	node = NULL;
	new_node = lstnew();
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'D')
			{
				new_node->x = j;
				new_node->y = i;
				addback(&node, new_node);
				new_node = lstnew();
			}
		}
	}
	free(new_node);
	return (node);
}

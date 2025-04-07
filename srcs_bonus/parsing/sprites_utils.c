/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:56:40 by antauber          #+#    #+#             */
/*   Updated: 2025/04/07 11:02:02 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

void	sprites_clear(t_spt **lst)
{
	t_spt	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

static t_spt	*sprites_lstnew(void)
{
	t_spt	*node;

	node = malloc(sizeof(*node));
	if (node)
	{
		node->x = 0;
		node->y = 0;
		node->dist = 0;
		node->next = NULL;
	}
	return (node);
}

static void	sprites_addback(t_spt **node, t_spt *new)
{
	t_spt	*tmp;

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

t_spt	*sprites_lst(char **map)
{
	t_spt	*node;
	t_spt	*new_node;
	int		i;
	int		j;

	i = -1;
	node = NULL;
	new_node = sprites_lstnew();
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'F')
			{
				new_node->x = j + 0.5;
				new_node->y = i + 0.5;
				new_node->dist = 0;
				sprites_addback(&node, new_node);
				new_node = sprites_lstnew();
			}
		}
	}
	free(new_node);
	return (node);
}

void sort_sprites(t_spt **begin_list)
{
	t_spt	*current;
	t_spt	*prev;
	t_spt	*next;
	bool	swapped;

	prev = NULL;
	next = NULL;
	swapped = true;
	while (swapped)
	{
		swapped = false;
		current = (*begin_list);
		prev = NULL;
		while (current && current->next)
		{
			next = current->next;
			if (current->dist > next->dist)
			{
				if (prev)
					prev->next = next;
				else
					*begin_list = next;
				current->next = next->next;
				next->next = current;
				prev = next;
				swapped = true;
			}
			else
			{
				prev = current;
				current = current->next;
			}
		}
	}
}

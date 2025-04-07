/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:23:44 by antauber          #+#    #+#             */
/*   Updated: 2025/04/07 16:25:42 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

static void	init_loop(bool *swapped, t_spt *current, t_spt *prev, t_spt **head)
{
	*swapped = false;
	current = (*head);
	prev = NULL;
}

static void	link_nodes(bool *swapped, t_spt *current, t_spt *prev, t_spt *next)
{
	current->next = next->next;
	next->next = current;
	prev = next;
	*swapped = true;
}

static void	skip_nodes(t_spt *prev, t_spt *current)
{
	prev = current;
	current = current->next;
}

void	sort_sprites(t_spt **begin_list, bool swapped)
{
	t_spt	*current;
	t_spt	*prev;
	t_spt	*next;

	prev = NULL;
	next = NULL;
	current = NULL;
	while (swapped)
	{
		init_loop(&swapped, current, prev, begin_list);
		while (current && current->next)
		{
			next = current->next;
			if (current->dist > next->dist)
			{
				if (prev)
					prev->next = next;
				else
					*begin_list = next;
				link_nodes(&swapped, current, prev, next);
			}
			else
				skip_nodes(prev, current);
		}
	}
}

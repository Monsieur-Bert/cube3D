/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:57:58 by ygorget           #+#    #+#             */
/*   Updated: 2025/04/04 15:01:15 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

bool	close_door_minimap(t_door **door, double y, double x)
{
	t_door	*tmp;

	if (!door)
		return (false);
	tmp = *door;
	while (tmp)
	{
		if (tmp->x == (int)x && tmp->y == (int)y && tmp->open == false)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

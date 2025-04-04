/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:50:57 by ygorget           #+#    #+#             */
/*   Updated: 2025/04/04 15:51:39 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

bool	is_door(t_door *tmp, double y, double x, int rl)
{
	if (tmp->x == (int)x && tmp->y == (int)y
		&& tmp->open == false && rl == NO_RL)
		return (true);
	else if (tmp->x == (int)x && tmp->y == (int)(y + 0.2)
		&& tmp->open == false && rl == RL_Y)
		return (true);
	else if (tmp->x == (int)x && tmp->y == (int)(y - 0.2)
		&& tmp->open == false && rl == RL_Y)
		return (true);
	else if (tmp->x == (int)(x + 0.2) && tmp->y == (int)y
		&& tmp->open == false && rl == RL_X)
		return (true);
	else if (tmp->x == (int)(x - 0.2) && tmp->y == (int)y
		&& tmp->open == false && rl == RL_X)
		return (true);
	return (false);
}

bool	door_close(t_door **door, double y, double x, int rl)
{
	t_door	*tmp;

	if (!door)
		return (false);
	tmp = *door;
	while (tmp)
	{
		if (is_door(tmp, y, x, rl))
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

void	open_door(t_cube *cube, t_door **door)
{
	t_door	*tmp;
	int		i;
	int		j;

	i = (int)cube->ray.pos_y - 2;
	tmp = *door;
	while (++i < (int)cube->ray.pos_y + 2)
	{
		j = (int)cube->ray.pos_x - 2;
		while (++j < (int)cube->ray.pos_x + 2)
		{
			if (cube->map.map[i][j] == 'D'
				&& (i != (int)cube->ray.pos_y || j != (int)cube->ray.pos_x))
			{
				while (tmp)
				{
					if (tmp->y == i && tmp->x == j)
						tmp->open = !tmp->open;
					tmp = tmp->next;
				}
				tmp = *door;
			}
		}
	}
	cube->mlx.keys[SPACE] = false;
}

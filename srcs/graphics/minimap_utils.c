/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:07:02 by ygorget           #+#    #+#             */
/*   Updated: 2025/04/02 11:15:37 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

double	limit(double pos)
{
	if (pos - 4 > 0)
		return (pos + 4);
	return (pos - (int)pos + 7.5);
}

void	limit_xy(t_minimap *plan)
{
	plan->limit_x = 10 - ((plan->j - (int)plan->j) * 10);
	plan->limit_y = 10 - ((plan->i - (int)plan->i) * 10);
}

int	newline_minimap(t_cube *cube, t_minimap *plan, double fmo_i, double tmp)
{
	plan->j -= (plan->j - tmp);
	if (plan->i + fmo_i == cube->ray.pos_y + 4)
	{
		plan->count_i++;
		plan->i += fmo_i;
	}
	else
		plan->i += plan->limit_y * 0.1;
	if (plan->i >= limit(cube->ray.pos_y))
	{
		plan->count_i--;
		return (1);
	}
	plan->x = 0;
	plan->y += plan->limit_y;
	limit_xy(plan);
	plan->count_j = 0;
	return (0);
}

void	new_element(t_cube *cube, t_minimap *plan, double fmo_j)
{
	if (plan->j + fmo_j == cube->ray.pos_x + 4)
	{
		plan->count_j++;
		plan->j += fmo_j;
	}
	else
		plan->j += plan->limit_x * 0.1;
}

void	init_plan(t_cube *cube, t_minimap *plan)
{
	if (cube->ray.pos_x - 4 > 0)
		plan->j = cube->ray.pos_x - 4;
	else
		plan->j = 0;
	if (cube->ray.pos_y - 4 >= 0)
		plan->i = cube->ray.pos_y - 4;
	else
		plan->i = 0;
	plan->x = 0;
	plan->y = 0;
	plan->count_j = 0;
	plan->count_i = 0;
}

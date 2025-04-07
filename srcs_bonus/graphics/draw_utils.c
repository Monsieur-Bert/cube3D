/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:53:00 by ygorget           #+#    #+#             */
/*   Updated: 2025/04/04 15:54:24 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

void	ft_put_pixel(t_img *img, int x, int y, int color)
{
	int	pixel;

	pixel = y * img->line_len + ((x * img->bpp) >> 3);
	img->addr[pixel] = color & 255;
	img->addr[pixel + 1] = (color >> 8) & 255;
	img->addr[pixel + 2] = (color >> 16) & 255;
}

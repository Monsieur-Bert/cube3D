/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:34:53 by antauber          #+#    #+#             */
/*   Updated: 2025/03/26 16:36:55 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# define WIN_WIDTH	920
# define WIN_HEIGHT	480
# define MOVE_SPEED	8.5
# define ROT_SPEED	1.5

typedef	struct s_ray
{
	int		x;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	cam_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	bool	hit;
	bool	side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		prev_start[WIN_WIDTH];
	int		prev_end[WIN_WIDTH];
	double	offset;
	double	wall_x;
}	t_ray;

typedef	struct s_text
{
	double	x;
	int		y;
	double	step;
	double	pos;
	int		pixl;
	int		color;
}	t_text;


typedef struct s_img
{
	void	*img;
	int		height;
	int		width;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*init;
	void	*win;
	int		*keys;
	t_img	render;
	t_img	wall_no;
	t_img	wall_so;
	t_img	wall_we;
	t_img	wall_ea;
}	t_mlx;

enum	e_key_hooks
{
	START,
	W_MV_FOR,
	S_MV_BACK,
	A_MV_LEFT,
	D_MV_RIGHT,
	LR_MV_BOOST,
	L_RT_LEFT,
	R_RT_RIGHT,
	U_RT_UP,
	D_RT_DOWN,
	Q_QUIT,
};

#endif
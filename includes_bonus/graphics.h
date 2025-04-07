/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:34:53 by antauber          #+#    #+#             */
/*   Updated: 2025/04/07 15:06:46 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# define WIN_WIDTH		920
# define WIN_HEIGHT		480
# define MOVE_SPEED		5.5
# define ROT_SPEED		2.5
# define MOUSE_SENSI 	0.5
# define SPRITE_SPEED	0.1

typedef struct s_ray
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
	double	z_buffer[WIN_WIDTH];
	double	offset;
	double	wall_x;
}	t_ray;

typedef struct s_text
{
	double	x;
	int		y;
	double	step;
	double	pos;
	int		pixl;
	int		color;
}	t_text;

typedef struct s_spt
{
	double			x;
	double			y;
	double			dist;
	struct s_spt	*next;
}	t_spt;

typedef struct s_ray_spt
{
	double	sprite_x;
	double	sprite_y;
	double	inv_det;
	double	trans_x;
	double	trans_y;
	int		screen_x;
	int		height;
	int		width;
	int		start_y;
	int		end_y;
	int		start_x;
	int		end_x;
	double	relative_x;
	int		text_x;
	int		d;
	int		text_y;
	int		text_pxl;
	int		text_color;
	int		stripe;
	int		y;
}	t_ray_spt;


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
	int		half_width;
	int		half_height;
	t_img	render;
	t_img	wall_no;
	t_img	wall_so;
	t_img	wall_we;
	t_img	wall_ea;
	t_spt	*sprites;
	t_img	sprite_fire[4];
	double	sprite_timer;
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
	MAP,
	MOUSE,
	Q_QUIT,
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:23:12 by ygorget           #+#    #+#             */
/*   Updated: 2025/03/26 12:31:58 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 247
# endif

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
}	t_texture;

typedef struct s_wall
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_wall;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_pos
{
	char	pos;
	int		x;
	int		y;
}	t_pos;

typedef struct s_map
{
	char	**map;
	t_pos	pos;
	t_wall	img;
	int		floor;
	int		ceiling;
}	t_map;

typedef struct s_buff
{
	char			buffer[BUFFER_SIZE + 1];
	struct s_buff	*next;
}	t_buff;

typedef struct s_minimap
{
	double i;
	double j;
	int x;
	int y;
	double	limit_x;
	double	limit_y;
}	t_minimap;

typedef	struct	s_cube
{
	char	**tab;
	t_mlx	mlx;
	t_map	map;
	t_ray	ray;
}	t_cube;

enum e_minimap
{
	WALL = 0x000000,
	FLOOR = 0xbfc9ca,
	PLAYER = 0xFFFFFF,
	VOID = 0x780015,
};

#endif
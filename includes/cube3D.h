/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:19:57 by ygorget           #+#    #+#             */
/*   Updated: 2025/04/17 13:41:25 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>
# include <unistd.h>
# include <sys/time.h>

# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"

# include "graphics.h"
# include "define.h"
# include "struct.h"

//cube3D.c
void	print_error(char *str);

/* ************************************************************************** */
/*                                  PARSING                                   */
/* ************************************************************************** */

//init.c
void	init_texture(t_texture *img);
int		init_struct(char **tab, t_texture *img, t_map *map);
int		ft_ato(const char *nptr);
int		no_map(int i);

//create_tab.c
char	**create_tab(char *file, char *str);

//texture_utils.c
int		check_color(char *color, char *str, int count, int digit);
int		check_space(char *img);

//texture.c
int		texture(char **tab, t_texture *img);

//read_fd_utils.c
t_buff	*ft_lst_last(t_buff *lst);
void	ft_lst_clear(t_buff **lst);
void	ft_lstaddback(t_buff **lst, t_buff *new);
t_buff	*ft_lst_new(void);

//read_fd.c
char	*read_fd(int fd, int count);

//maps_utils.c
int		one_charactere(int p);
int		ft_maplen(char **tab);

//maps.c
bool	is_character(char c);
int		maps(char **tab, int p, int i);

/* ************************************************************************** */
/*                                  GRAPHICS                                  */
/* ************************************************************************** */
void	graphics(t_cube *cube);

//init_mlx.c
bool	get_walls_addr(t_mlx *mlx);
bool	get_walls_textures(t_mlx *mlx, t_map *map);
void	init_mlx(t_mlx *mlx);

//close_mlx
void	free_error(t_cube *cube, char *error_message);
int		close_window(t_cube *cube);

//handle_hooks
int		mouse_hook(int x, int y, t_cube *cube);
int		key_release(int keysym, t_cube *cube);
int		key_press(int keysym, t_cube *cube);
void	set_keystab(t_cube *cube);

//dda_algo
void	perform_dda(t_ray *ray, char **map);
void	find_step_dda(t_ray *ray);

//raycaster
void	raycaster(t_cube *cube);
void	set_player(t_ray *ray, t_map *map);

//draw
void	draw_background(t_cube *cube);
void	ft_put_pixel(t_img *img, int x, int y, int color);
void	draw_walls(t_ray *ray, t_mlx *mlx);

//move_player
void	rotate_player(t_ray *ray, int dir, double speed);
void	move_player(t_cube *cube, double delta_time);

//minimap
void	minimap(t_cube *cube);

//minimap_utils
double	limit(double pos);
void	limit_xy(t_minimap *plan);
void	init_plan(t_cube *cube, t_minimap *plan);
void	new_element(t_cube *cube, t_minimap *plan, double fmo_j);
int		newline_minimap(t_cube *cube, t_minimap *plan,
			double fmo_i, double tmp);

#endif
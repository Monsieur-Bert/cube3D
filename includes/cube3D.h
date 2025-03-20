/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bert <bert@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:19:57 by ygorget           #+#    #+#             */
/*   Updated: 2025/03/20 09:26:09 by bert             ###   ########.fr       */
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

# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"

# include "graphics.h"
# include "define.h"
# include "struct.h"


//create_tab.c
char	*ft_strstr(const char *big, const char *little, size_t len);
int		backslash(char *str);
void	skip_element(char *str, int *i);
char	**create_tab(char *file);

//cube3D.c
void	print_error(char *str);
void	*ft_free_tabstr(char **tab);
int		parsing(char **tab, t_texture *img, t_map *map);

//texture_utils.c
int		check_color(char *color, char *str, int count);
int		check_space(char *img);
int		start_color(char *color, char *str);

//texture.c
int		good_texture(t_texture *img);
char	*add_texture(char *str, char *text);
int		texture(char **tab, t_texture *img);

//init.c
void	init_texture(t_texture *img);
int		rgb(t_color *color, char *str);  
int		init_struct(char **tab, t_texture *img, t_map *map);

//maps_utils.c
int		one_charactere(int p);
int		ft_maplen(char **tab);

//maps.c
bool	is_character(char c);
bool	wall_or_floor(char c);
int		check_around(char **tab, int i, int j);
int		good_items(char **tab, int i, int j, int *p);
int		maps(char **tab, int p);

//read_fd_utils.c
t_buff	*ft_lst_last(t_buff *lst);
void	ft_lst_clear(t_buff **lst);
void	ft_lstaddback(t_buff **lst, t_buff *new);
t_buff	*ft_lst_new(void);

//read_fd.c
void	ft_strcpy(char *dest, char *src);
char	*new_string(t_buff *node, int count);
char	*read_fd(int fd, int count);


//dda_algo
void	perform_dda(t_ray *ray, char **map);
void	find_step_dda(t_ray *ray);

//raycaster
void	raycaster(t_cube *cube);
void	set_player_dir(t_ray *ray, char dir);

//draw
void	draw_background(t_cube *cube);
void	ft_put_pixel(t_img *img, int x, int y, int color);
void	draw_walls(t_ray *ray, t_mlx *mlx);



//graphics
void	free_walls_textures(t_mlx *mlx);
void	free_mlx(t_mlx *mlx);
int		close_window(t_cube *cube);
void	init_mlx(t_mlx *mlx);
void	graphics(t_cube *cube);

//keyhooks
int handle_keyhooks(int keysym, t_cube *cube);

#endif
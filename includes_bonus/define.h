/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:21:55 by ygorget           #+#    #+#             */
/*   Updated: 2025/04/02 14:05:37 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define ERR_MALLOC		"memory allocation failed\n"
# define ERR_WALL		"the map is not surrounded by a wall\n"
# define ERR_ITEMS		"there are a wrong item\n"
# define ERR_CHARACTERS	"there aren't 1 character\n"
# define ERR_FLOOR		"the color of the floor is missing\n"
# define ERR_CEILING	"the ceiling color is missing\n"
# define ERR_SPACES		"there are spaces in the information given\n"
# define ERR_COLOR		"one of the RGB colors is missing\n"
# define ERR_VALUE      "the color is larger than 255\n"
# define ERR_NO_IMG		"there aren't image\n"
# define ERR_FILE		"it's not .cub\n"
# define ERR_RGB		"there are whitespaces between numbers\n"
# define ERR_PARAM      "I need 1 argument\n"
# define ERR_MLX_INIT	"mlx initialisation error\n"
# define ERR_MLX_WIN	"mlx create window error\n"
# define ERR_MLX_RENDER	"mlx create image error\n"
# define ERR_MLX_TEXT	"mlx create wall texture error\n"
# define ERR_MLX_SPRITE	"mlx create sprite texture error\n"
# define ERR_DOOR   	"a door isn't into a wall\n"


#endif
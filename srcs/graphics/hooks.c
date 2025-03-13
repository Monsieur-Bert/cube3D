/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:43:37 by ygorget           #+#    #+#             */
/*   Updated: 2025/03/13 18:16:53 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

int handle_keyhooks(int keysym, t_cube *cube)
{
	double	move_speed = 0.5;

	if (keysym == XK_Escape || keysym == XK_q)
		close_window(cube);
	if (keysym == XK_w)
	{
		if(cube->map.map[(int)(floor(cube->ray.pos_x) + cube->ray.dir_x * move_speed)][(int)floor(cube->ray.pos_y)] != '1')
			cube->ray.pos_x += cube->ray.dir_x * move_speed;
		if(cube->map.map[(int)floor(cube->ray.pos_x)][(int)(floor(cube->ray.pos_y) + cube->ray.dir_y * move_speed)] != '1')
			cube->ray.pos_y += cube->ray.dir_y * move_speed;		
	}
	//move backwards if no wall behind you
    if (keysym == XK_s)
    {
		if(cube->map.map[(int)(floor(cube->ray.pos_x) - cube->ray.dir_x * move_speed)][(int)floor(cube->ray.pos_y)] != '1')
			cube->ray.pos_x -= cube->ray.dir_x * move_speed;
		if(cube->map.map[(int)floor(cube->ray.pos_x)][(int)(floor(cube->ray.pos_y) - cube->ray.dir_y * move_speed)] != '1')
			cube->ray.pos_y -= cube->ray.dir_y * move_speed;
    }
	if (keysym == XK_d)
    {
		if(cube->map.map[(int)(floor(cube->ray.pos_x) - cube->ray.dir_x * move_speed)][(int)floor(cube->ray.pos_y)] != '1')
		cube->ray.pos_y -= cube->ray.dir_x * move_speed;
		if(cube->map.map[(int)floor(cube->ray.pos_x)][(int)(floor(cube->ray.pos_y) - cube->ray.dir_y * move_speed)] != '1')
		cube->ray.pos_x -= cube->ray.dir_y * move_speed;
    }
	if (keysym == XK_a)
    {
        if(cube->map.map[(int)(floor(cube->ray.pos_x) + cube->ray.dir_x * move_speed)][(int)floor(cube->ray.pos_y)] != '1')
			cube->ray.pos_y += cube->ray.dir_x * move_speed;
        if(cube->map.map[(int)floor(cube->ray.pos_x)][(int)(floor(cube->ray.pos_y) + cube->ray.dir_y * move_speed)] != '1')
			cube->ray.pos_x += cube->ray.dir_y * move_speed;
    }
	// raycaster(cube);
	// mlx_put_image_to_window(cube->mlx.init, cube->mlx.win, cube->mlx.render.img, 0, 0);
    // //rotate to the right
    // if (keysym == XK_d)
    // {
    //   //both camera direction and camera plane must be rotated
    //   double oldDirX = dirX;
    //   dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
    //   dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
    //   double oldPlaneX = planeX;
    //   planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
    //   planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
    // }
    // //rotate to the left
    // if (keyDown(SDLK_LEFT))
    // {
    //   //both camera direction and camera plane must be rotated
    //   double oldDirX = dirX;
    //   dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
    //   dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
    //   double oldPlaneX = planeX;
    //   planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
    //   planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
    // }
	return (0);
}


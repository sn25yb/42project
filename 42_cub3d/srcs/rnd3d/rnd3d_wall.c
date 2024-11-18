/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rnd3d_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:24:18 by yubshin           #+#    #+#             */
/*   Updated: 2024/11/13 10:40:47 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rnd3d.h"

void	rnd3d_wall(t_rnd3d *rnd, char **map)
{
	int	x;

	x = 0;
	while (x < SCREEN_W)
	{
		rnd->wall.door_flag = 0;
		cal_raydir_pair(rnd->view, &rnd->wall, x);
		cal_map_pair(rnd->view, &rnd->wall);
		cal_deltadist_pair(&rnd->wall);
		cal_sidedist_pair(rnd->view, &rnd->wall);
		cal_step_pair(&rnd->wall);
		dda_wall(&rnd->wall, map);
		cal_perpwalldist(rnd->view, &rnd->wall);
		rnd->obj.z_buffer[x] = rnd->wall.perpwalldist;
		cal_lineheight(&rnd->wall);
		cal_drawstartend(&rnd->wall);
		set_texture(&rnd->wall, rnd->tex3d, map);
		cal_wall_x(rnd->view, &rnd->wall);
		draw_canvas_wall(&rnd->wall, &rnd->tex3d, x);
		x++;
	}
}

void	rnd3d_door(t_rnd3d *rnd, char **map)
{
	int	x;

	x = 0;
	while (x < SCREEN_W)
	{
		cal_raydir_pair(rnd->view, &rnd->wall, x);
		cal_map_pair(rnd->view, &rnd->wall);
		cal_deltadist_pair(&rnd->wall);
		cal_sidedist_pair(rnd->view, &rnd->wall);
		cal_step_pair(&rnd->wall);
		dda_door(&rnd->wall, rnd->tex3d.anim, map);
		if (is_door(map[rnd->wall.map.y][rnd->wall.map.x]))
		{
			cal_perpwalldist(rnd->view, &rnd->wall);
			if (rnd->tex3d.anim.prox_fidx[rnd->wall.map.y][rnd->wall.map.x] < 2)
				rnd->obj.z_buffer[x] = rnd->wall.perpwalldist;
			cal_lineheight(&rnd->wall);
			cal_drawstartend(&rnd->wall);
			set_texture(&rnd->wall, rnd->tex3d, map);
			cal_wall_x(rnd->view, &rnd->wall);
			draw_canvas_wall(&rnd->wall, &rnd->tex3d, x);
		}
		x++;
	}
}

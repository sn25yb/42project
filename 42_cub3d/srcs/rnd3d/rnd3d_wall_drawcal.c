/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rnd3d_wall_drawcal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:16:01 by yubshin           #+#    #+#             */
/*   Updated: 2024/11/08 15:14:47 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rnd3d.h"

void	cal_perpwalldist(t_view view, t_wall *wall)
{
	if (wall->side == 0)
		wall->perpwalldist \
		= (wall->map.x - view.pos.x + (1 - wall->step.x) / 2) / wall->raydir.x;
	else
		wall->perpwalldist \
		= (wall->map.y - view.pos.y + (1 - wall->step.y) / 2) / wall->raydir.y;
	if (wall->perpwalldist <= 0)
		wall->perpwalldist = 0.25;
}

void	cal_lineheight(t_wall *wall)
{
	wall->lineheight = (int)(SCREEN_H / wall->perpwalldist);
}

void	cal_drawstartend(t_wall *wall)
{
	wall->drawstart = (-wall->lineheight / 2) + (SCREEN_H / 2);
	if (wall->drawstart < 0)
		wall->drawstart = 0;
	wall->drawend = (wall->lineheight / 2) + (SCREEN_H / 2);
	if (wall->drawend >= SCREEN_H)
		wall->drawend = SCREEN_H - 1;
}

void	set_texture(t_wall *wall, t_tex3d tex3d, char **map)
{
	int			fidx;
	char		texnum;

	fidx = (int)tex3d.anim.prox_fidx[wall->map.y][wall->map.x];
	texnum = map[wall->map.y][wall->map.x];
	if (texnum == '1')
	{
		if (wall->side == 0 && wall->raydir.x < 0)
			wall->texture = tex3d.wall[I_WEST].addr;
		else if (wall->side == 0 && wall->raydir.x >= 0)
			wall->texture = tex3d.wall[I_EAST].addr;
		else if (wall->side == 1 && wall->raydir.y < 0)
			wall->texture = tex3d.wall[I_NORTH].addr;
		else if (wall->side == 1 && wall->raydir.y >= 0)
			wall->texture = tex3d.wall[I_SOUTH].addr;
	}
	else if (texnum == 'e')
		wall->texture = tex3d.door[0][fidx].addr;
	else if (texnum == 'd')
		wall->texture = tex3d.door[0][fidx].addr;
}

void	cal_wall_x(t_view view, t_wall *wall)
{
	if (wall->side == 0)
		wall->wall_x = view.pos.y + wall->perpwalldist * wall->raydir.y;
	else
		wall->wall_x = view.pos.x + wall->perpwalldist * wall->raydir.x;
	wall->wall_x -= floor(wall->wall_x);
}

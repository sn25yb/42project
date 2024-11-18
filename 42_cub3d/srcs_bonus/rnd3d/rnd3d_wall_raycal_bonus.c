/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rnd3d_wall_raycal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:11:52 by yubshin           #+#    #+#             */
/*   Updated: 2024/11/13 16:15:15 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rnd3d_bonus.h"

void	cal_raydir_pair(t_view view, t_wall *wall, int x)
{
	double	camera_x;

	camera_x = (2 * x / (double)SCREEN_W - 1);
	wall->raydir.x = view.dir.x + view.plane.x * camera_x;
	wall->raydir.y = view.dir.y + view.plane.y * camera_x;
}

void	cal_map_pair(t_view view, t_wall *wall)
{
	wall->map.x = (int)(view.pos.x);
	wall->map.y = (int)(view.pos.y);
}

void	cal_deltadist_pair(t_wall *wall)
{
	wall->deltadist.x \
		= sqrt(1 + (wall->raydir.y * wall->raydir.y) \
			/ (wall->raydir.x * wall->raydir.x));
	wall->deltadist.y \
		= sqrt(1 + (wall->raydir.x * wall->raydir.x) \
			/ (wall->raydir.y * wall->raydir.y));
}

void	cal_sidedist_pair(t_view view, t_wall *wall)
{
	if (wall->raydir.x >= 0)
		wall->sidedist.x = (wall->map.x + 1.0 - view.pos.x) * wall->deltadist.x;
	else
		wall->sidedist.x = (view.pos.x - wall->map.x) * wall->deltadist.x;
	if (wall->raydir.y >= 0)
		wall->sidedist.y = (wall->map.y + 1.0 - view.pos.y) * wall->deltadist.y;
	else
		wall->sidedist.y = (view.pos.y - wall->map.y) * wall->deltadist.y;
}

void	cal_step_pair(t_wall *wall)
{
	if (wall->raydir.x >= 0)
		wall->step.x = 1;
	else
		wall->step.x = -1;
	if (wall->raydir.y >= 0)
		wall->step.y = 1;
	else
		wall->step.y = -1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rnd3d_wall_dda.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:02:09 by yubshin           #+#    #+#             */
/*   Updated: 2024/11/13 10:41:40 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rnd3d.h"

static int	wall_hit(t_wall *wall, char **map);
static int	door_hit(t_wall *wall, t_anim anim, char **map);

// side = 0 : east, west
// side = 1 : north, south
void	dda_wall(t_wall *wall, char **map)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (wall->sidedist.x <= wall->sidedist.y)
		{
			wall->sidedist.x += wall->deltadist.x;
			wall->side = 0;
			wall->map.x += wall->step.x;
			if (wall->map.x < 0 || !map[wall->map.y][wall->map.x])
				hit = 1;
		}
		else
		{
			wall->sidedist.y += wall->deltadist.y;
			wall->side = 1;
			if (wall->map.y < 0 || !map[wall->map.y][wall->map.x])
				hit = 1;
			wall->map.y += wall->step.y;
		}
		hit = wall_hit(wall, map);
	}
}

void	dda_door(t_wall *wall, t_anim anim, char **map)
{
	int	hit;

	(void)anim;
	hit = 0;
	while (hit == 0)
	{
		if (wall->sidedist.x <= wall->sidedist.y)
		{
			wall->sidedist.x += wall->deltadist.x;
			wall->side = 0;
			wall->map.x += wall->step.x;
			if (wall->map.x < 0 || !map[wall->map.y][wall->map.x])
				hit = 1;
		}
		else
		{
			wall->sidedist.y += wall->deltadist.y;
			wall->side = 1;
			if (wall->map.y < 0 || !map[wall->map.y][wall->map.x])
				hit = 1;
			wall->map.y += wall->step.y;
		}
		hit = door_hit(wall, anim, map);
	}
}

static int	wall_hit(t_wall *wall, char **map)
{
	if (is_wall(map[wall->map.y][wall->map.x]) \
	|| map[wall->map.y][wall->map.x] == 'e')
		return (1);
	else if (map[wall->map.y][wall->map.x] == 'd')
	{
		if (wall->door_flag++ == 1)
			return (1);
	}
	return (0);
}

static int	door_hit(t_wall *wall, t_anim anim, char **map)
{
	if (is_wall(map[wall->map.y][wall->map.x]) \
	|| (is_door(map[wall->map.y][wall->map.x])))
	{
		if (map[wall->map.y][wall->map.x] == 'd')
		{
			if (anim.prox_fidx[wall->map.y][wall->map.x] < 2)
				return (1);
		}
		else
			return (1);
	}
	return (0);
}

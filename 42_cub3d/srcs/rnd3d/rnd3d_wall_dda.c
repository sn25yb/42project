/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rnd3d_wall_dda.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:02:09 by yubshin           #+#    #+#             */
/*   Updated: 2024/11/01 15:50:32 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rnd3d.h"

static int	is_solid_map(char mapcode);

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
		if (is_solid_map(map[wall->map.y][wall->map.x]))
			hit = 1;
	}
}

static int	is_solid_map(char mapcode)
{
	if (mapcode && (mapcode == '1' || mapcode == 'd' || mapcode == 'e'))
		return (TRUE);
	return (FALSE);
}

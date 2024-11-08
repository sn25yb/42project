/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rnd3d_obj_cal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:24:06 by yubshin           #+#    #+#             */
/*   Updated: 2024/11/01 14:46:15 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rnd3d.h"

static void	init_sprite_pos(t_obj *object);
static int	mapcode_to_idx(char mapcode);

void	save_sprite_pos(char **map, t_obj *object)
{
	t_pair_int	midx;
	int			sidx;

	init_sprite_pos(object);
	midx.y = 0;
	while (map[midx.y])
	{
		midx.x = 0;
		while (map[midx.y][midx.x])
		{
			sidx = mapcode_to_idx(map[midx.y][midx.x]);
			if (sidx >= 0)
			{
				object->sprites[sidx].pos.x = midx.x;
				object->sprites[sidx].pos.y = midx.y;
				object->sprites[sidx].dist = 0;
				object->sprites[sidx].idx = sidx;
			}
			midx.x++;
		}
		midx.y++;
	}
}

static void	init_sprite_pos(t_obj *object)
{
	int	idx;

	idx = 0;
	while (idx < N_OBJ)
	{
		object->sprites[idx].pos.x = 0;
		object->sprites[idx].pos.y = 0;
		object->sprites[idx].dist = 0;
		object->sprites[idx].idx = 0;
		idx++;
	}
}

static int	mapcode_to_idx(char mapcode)
{
	int			idx;
	const char	mapcodes[N_OBJ] = {'A', 'L', 'F', 'R', 'H', 'b', 'c', 'k', 'w'};

	idx = 0;
	while (mapcodes[idx])
	{
		if (mapcodes[idx] == mapcode)
			return (idx);
		idx++;
	}
	return (-1);
}

void	cal_sprite_distance(t_view view, t_obj *object)
{
	int			idx;
	t_pair_dbl	dist;

	idx = 0;
	while (idx < N_OBJ)
	{
		dist.x = object->sprites[idx].pos.x - view.pos.x;
		dist.y = object->sprites[idx].pos.y - view.pos.y;
		object->sprites[idx].dist = sqrt(dist.x * dist.x + dist.y * dist.y);
		idx++;
	}
}

void	sort_sprites(t_obj *object)
{
	t_sprite	tmp;
	int			i;
	int			j;

	i = 0;
	while (i < N_OBJ - 1)
	{
		j = 0;
		while (j < N_OBJ - i - 1)
		{
			if (object->sprites[j].dist < object->sprites[j + 1].dist)
			{
				tmp = object->sprites[j];
				object->sprites[j] = object->sprites[j + 1];
				object->sprites[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:41:31 by yubshin           #+#    #+#             */
/*   Updated: 2024/11/01 13:42:28 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tex3d.h"

static void	update_global_fidx(t_anim *anim);
static void	update_prox_fidx(t_anim *anim, t_pair_dbl pos, char **map);
static void	update_prox_door(t_anim *anim, t_pair_dbl pos, t_pair_int idx);

void	update_anim(t_anim *anim, t_pair_dbl pos, char **map)
{
	update_global_fidx(anim);
	update_prox_fidx(anim, pos, map);
}

static void	update_global_fidx(t_anim *anim)
{
	int	idx;

	idx = 0;
	while (idx < N_OBJ)
	{	
		if (update_anim_clock(&anim->global_ftime, OBJ_FTIME) == TIME_PASSED)
			anim->global_fidx = (anim->global_fidx + 1) % N_ANIM;
		idx++;
	}
}

static void	update_prox_fidx(t_anim *anim, t_pair_dbl pos, char **map)
{
	double		prox;
	t_pair_int	start;
	t_pair_int	end;

	prox = PROX_ANIM;
	end.y = (int)pos.y + prox;
	start.y = (int)fmax(pos.y - prox, 0);
	while (start.y < end.y && map[start.y])
	{
		end.x = (int)pos.x + prox;
		start.x = (int)fmax(pos.x - prox, 0);
		while (start.x < end.x && map[start.y][start.x])
		{
			if (map[start.y][start.x] == 'e' || map[start.y][start.x] == 'd')
				update_prox_door(anim, pos, start);
			start.x++;
		}
		start.y++;
	}
}

static void	update_prox_door(t_anim *anim, t_pair_dbl pos, t_pair_int d_idx)
{
	t_pair_dbl	relpos;
	double		dist;
	double		prox;
	int			fidx;

	relpos.x = d_idx.x - pos.x;
	relpos.y = d_idx.y - pos.y;
	dist = sqrt(relpos.x * relpos.x + relpos.y * relpos.y);
	prox = PROX_ANIM;
	fidx = fmin(prox - dist, N_ANIM - 1);
	if (fidx == 0 || fidx == 3)
		anim->prox_fidx[d_idx.y][d_idx.x] = (char)fidx;
	else if (anim->prox_fidx[d_idx.y][d_idx.x] >= 0 \
		&& anim->prox_fidx[d_idx.y][d_idx.x] <= 2 \
		&& update_anim_clock(&anim->prox_ftime, DOOR_FTIME) == TIME_PASSED)
		anim->prox_fidx[d_idx.y][d_idx.x]++;
}

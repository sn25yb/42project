/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:41:31 by yubshin           #+#    #+#             */
/*   Updated: 2024/11/13 10:35:41 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tex3d_bonus.h"

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
	t_pair_int	idx;

	prox = PROX_ANIM;
	idx.y = 0;
	while (map[idx.y])
	{
		idx.x = 0;
		while (map[idx.y][idx.x])
		{
			if (map[idx.y][idx.x] == 'e' || map[idx.y][idx.x] == 'd')
				update_prox_door(anim, pos, idx);
			idx.x++;
		}
		idx.y++;
	}
}

static void	update_prox_door(t_anim *anim, t_pair_dbl pos, t_pair_int d_idx)
{
	t_pair_dbl	relpos;
	double		dist;
	int			fidx;

	fidx = 0;
	relpos.x = d_idx.x - pos.x;
	relpos.y = d_idx.y - pos.y;
	dist = sqrt(relpos.x * relpos.x + relpos.y * relpos.y);
	if (dist > PROX_ANIM)
	{
		anim->prox_fidx[d_idx.y][d_idx.x] = 0;
		return ;
	}
	fidx = fmin(PROX_ANIM - dist, N_ANIM - 1);
	if (fidx == 0)
		anim->prox_fidx[d_idx.y][d_idx.x] = (char)fidx;
	else if (anim->prox_fidx[d_idx.y][d_idx.x] >= 0 \
		&& anim->prox_fidx[d_idx.y][d_idx.x] <= 2 \
		&& update_anim_clock(&anim->prox_ftime, DOOR_FTIME) == TIME_PASSED)
		anim->prox_fidx[d_idx.y][d_idx.x] += 1;
}

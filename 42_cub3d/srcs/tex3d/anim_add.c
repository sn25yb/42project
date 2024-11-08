/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:08:41 by yubshin           #+#    #+#             */
/*   Updated: 2024/11/01 14:22:38 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tex3d.h"

static void	init_anim_global(t_anim *anim);
static void	init_anim_prox(t_anim *anim, char **map);

void	add_anim(t_anim *anim, char **map)
{
	init_anim_global(anim);
	init_anim_prox(anim, map);
}

static void	init_anim_global(t_anim *anim)
{
	anim->global_fidx = 0;
	anim->global_ftime = timeval_to_long();
}

static void	init_anim_prox(t_anim *anim, char **map)
{
	t_pair_int	idx;

	anim->prox_fidx = arrcpy(map);
	anim->prox_ftime = anim->global_ftime;
	idx.y = 0;
	while (map[idx.y])
	{
		idx.x = 0;
		while (map[idx.y][idx.x])
		{
			if (anim->prox_fidx[idx.y][idx.x] == 'e' \
			|| anim->prox_fidx[idx.y][idx.x] == 'd')
				anim->prox_fidx[idx.y][idx.x] = 0;
			else
				anim->prox_fidx[idx.y][idx.x] = N_ANIM;
			idx.x++;
		}
		idx.y++;
	}
}

void	free_anim(t_anim *anim)
{
	free_array(anim->prox_fidx);
}

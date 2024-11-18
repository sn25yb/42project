/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rnd3d_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:23:49 by yubshin           #+#    #+#             */
/*   Updated: 2024/11/08 15:16:34 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rnd3d_bonus.h"

void	rnd_obj(t_rnd3d*rnd, char **map)
{
	int	idx;

	idx = 0;
	save_sprite_pos(map, &rnd->obj);
	cal_sprite_distance(rnd->view, &rnd->obj);
	sort_sprites(&rnd->obj);
	while (idx < N_OBJ)
	{
		cal_sprite_screen_params(rnd->obj.sprites[idx], rnd->view, &rnd->obj);
		cal_sprite_display_range(&rnd->obj);
		draw_canvas_obj(&rnd->obj, &rnd->tex3d, rnd->obj.sprites[idx]);
		idx++;
	}
}

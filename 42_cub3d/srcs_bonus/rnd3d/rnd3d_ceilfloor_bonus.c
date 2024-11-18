/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rnd3d_ceilfloor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:53:37 by yubshin           #+#    #+#             */
/*   Updated: 2024/11/01 12:56:14 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rnd3d_bonus.h"

void	rnd_ceilfloor(t_canvas *display, t_rgb ceil, t_rgb floor)
{
	double		dist_from_cent;
	t_pair_int	idx;
	int			pxl;

	idx.y = 0;
	while (idx.y < SCREEN_H)
	{
		idx.x = 0;
		while (idx.x < SCREEN_W)
		{
			dist_from_cent = 1.0 - (double)idx.y / (double)SCREEN_H;
			pxl = blur_rgb(ceil, dist_from_cent, 255);
			display->addr[(SCREEN_H - 1 - idx.y) * SCREEN_W + idx.x] = pxl;
			pxl = blur_rgb(floor, dist_from_cent, 255);
			display->addr[idx.y * SCREEN_W + idx.x] = pxl;
			idx.x++;
		}
		idx.y++;
	}
}

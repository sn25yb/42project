/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:33:03 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/31 11:52:31 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "view.h"

void	change_pos(t_view *player, int keycode)
{
	double	rad;
	t_view	p;

	p = *player;
	rad = cal_radian(p.dir);
	if (keycode == KEY_DOWN)
		rad += M_PI;
	else if (keycode == KEY_RIGHT)
		rad += M_PI / 2L;
	else if (keycode == KEY_LEFT)
		rad -= M_PI / 2L;
	p.pos.y += P_STEP * sin(rad);
	p.pos.x += P_STEP * cos(rad);
	p.map_pos = make_pair_int(p.pos.x, p.pos.y);
	*player = p;
}

void	change_dir(t_view *p, double x)
{
	double		rad;
	t_pair_dbl	conv;

	conv = p->dir;
	rad = -1 * (x - SCREEN_W / 2) * M_PI / SCREEN_W / 4;
	if (rad < 0)
	{
		p->dir.x = conv.x * cos(-1 * rad) + sin(rad) * conv.y;
		p->dir.y = conv.y * cos(-1 * rad) - sin(rad) * conv.x;
	}
	else
	{
		p->dir.x = conv.x * cos(rad) + sin(rad) * conv.y;
		p->dir.y = conv.y * cos(rad) - sin(rad) * conv.x;
	}
	p->rad = cal_radian(p->dir);
}

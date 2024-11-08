/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rnd3d_wall_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:32:08 by yubshin           #+#    #+#             */
/*   Updated: 2024/11/01 16:21:33 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rnd3d.h"

static void	draw_pxline_wall(t_wall *wall, t_tex3d *tex3d, int x);

void	draw_canvas_wall(t_wall *wall, t_tex3d *tex3d, int x)
{
	wall->tex.x \
	= (int)((tex3d->bsize.x - wall->wall_x) * (double)tex3d->bsize.x);
	wall->tex.x = wall->tex.x % tex3d->bsize.x;
	if ((wall->side == 0 && wall->raydir.x > 0) \
		|| (wall->side == 1 && wall->raydir.y < 0))
		wall->tex.x = tex3d->bsize.x - wall->tex.x - 1;
	draw_pxline_wall(wall, tex3d, x);
}

int	set_brightness(int color, float factor)
{
	t_rgb	rgb;

	rgb.r = (color >> 16) & 0xFF;
	rgb.g = (color >> 8) & 0xFF;
	rgb.b = color & 0xFF;
	rgb.r *= factor;
	rgb.g *= factor;
	rgb.b *= factor;
	return (rgb_to_int(rgb.r, rgb.g, rgb.b));
}

static void	draw_pxline_wall(t_wall *wall, t_tex3d *tex3d, int x)
{
	double	texpos;
	double	step;
	int		y;
	int		pxl;

	step = 1.0 * tex3d->bsize.y / wall->lineheight;
	texpos = (wall->drawstart - SCREEN_H / 2 + wall->lineheight / 2) * step;
	y = wall->drawstart;
	while (y < wall->drawend && wall->texture)
	{
		wall->tex.y = (int)texpos & (tex3d->bsize.y - 1);
		wall->tex.y = wall->tex.y % tex3d->bsize.y;
		texpos += step;
		pxl = wall->texture[tex3d->bsize.y * wall->tex.y + wall->tex.x];
		if (wall->side == 1)
			pxl = set_brightness(pxl, 0.9f);
		if (wall->side == 0 && wall->raydir.x >= 0)
			pxl = set_brightness(pxl, 0.7f);
		tex3d->display.addr[y * SCREEN_W + x] = pxl;
		y++;
	}
}

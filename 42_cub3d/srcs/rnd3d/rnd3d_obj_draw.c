/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rnd3d_obj_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:33:11 by yubshin           #+#    #+#             */
/*   Updated: 2024/11/08 20:40:25 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rnd3d.h"

static t_pair_dbl	sprite_to_view(t_sprite sprite, t_view view);
static void			draw_pxline_obj(t_obj *obj, t_tex3d *tex3d, \
	t_sprite sprite, t_pair_int draw);

void	cal_sprite_screen_params(t_sprite sprite, t_view view, t_obj *obj)
{
	t_pair_dbl	tranf;

	tranf = obj->transform;
	tranf = sprite_to_view(sprite, view);
	obj->transform = tranf;
	obj->sprite_screenx = (int)((SCREEN_W / 2) * (1 + tranf.x / tranf.y));
	obj->sprite_h = abs((int)(SCREEN_H / tranf.y));
	obj->sprite_w = abs((int)(SCREEN_H / tranf.y));
}

static t_pair_dbl	sprite_to_view(t_sprite sprite, t_view view)
{
	t_pair_dbl	transform;
	t_pair_dbl	sprite_rel_pos;
	double		inv;

	sprite_rel_pos.x = sprite.pos.x - view.pos.x + 0.5;
	sprite_rel_pos.y = sprite.pos.y - view.pos.y + 0.5;
	inv = 1.0 / (view.plane.x * view.dir.y - view.dir.x * view.plane.y);
	transform.x = inv * \
		(view.dir.y * sprite_rel_pos.x - view.dir.x * sprite_rel_pos.y);
	transform.y = inv * \
		(-view.plane.y * sprite_rel_pos.x + view.plane.x * sprite_rel_pos.y);
	return (transform);
}

void	cal_sprite_display_range(t_obj *obj)
{
	obj->drawstart.y = -obj->sprite_h / 2 + SCREEN_H / 2;
	obj->drawend.y = obj->sprite_h / 2 + SCREEN_H / 2;
	if (obj->drawstart.y < 0)
		obj->drawstart.y = 0;
	if (obj->drawend.y >= SCREEN_H)
		obj->drawend.y = SCREEN_H - 1;
	obj->drawstart.x = -obj->sprite_w / 2 + obj->sprite_screenx;
	obj->drawend.x = obj->sprite_w / 2 + obj->sprite_screenx;
	if (obj->drawstart.x < 0)
		obj->drawstart.x = 0;
	if (obj->drawend.x >= SCREEN_W)
		obj->drawend.x = SCREEN_W - 1;
}

void	draw_canvas_obj(t_obj *obj, t_tex3d *tex3d, t_sprite sprite)
{
	t_pair_int	draw;
	int			offset_x;
	int			scaled_offset;

	draw.x = obj->drawstart.x;
	while (draw.x < obj->drawend.x)
	{
		offset_x = draw.x - (-obj->sprite_w / 2 + obj->sprite_screenx);
		scaled_offset = 256 * offset_x * tex3d->bsize.x;
		obj->tex.x = scaled_offset / obj->sprite_w / 256;
		if (obj->transform.y > 0 && obj->transform.y < obj->z_buffer[draw.x] \
			&& draw.x > 0 && draw.x < SCREEN_W)
		{
			draw.y = obj->drawstart.y;
			draw_pxline_obj(obj, tex3d, sprite, draw);
		}
		draw.x++;
	}
}

static void	draw_pxline_obj(t_obj *obj, t_tex3d *tex3d, \
	t_sprite sprite, t_pair_int draw)
{
	int	pxl_pos;
	int	pxl;

	while (draw.y < obj->drawend.y)
	{
		pxl_pos = draw.y * 256 - SCREEN_H * 128 + obj->sprite_h * 128;
		obj->tex.y = ((pxl_pos * tex3d->bsize.y) / obj->sprite_h) / 256;
		pxl = tex3d->obj[sprite.idx][tex3d->anim.global_fidx].addr \
			[tex3d->bsize.y * obj->tex.y + obj->tex.x];
		if ((pxl & 0x00FFFFFF) != 0)
			tex3d->display.addr[draw.y * SCREEN_W + draw.x] = pxl;
		draw.y++;
	}
}

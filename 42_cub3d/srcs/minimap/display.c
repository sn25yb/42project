/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:47:31 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/30 18:48:04 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "map2d.h"

void	display_player(t_map2d *map, void *mlx, void *win)
{
	t_imgs2d	*imgs;
	t_canvas	bg;
	t_pair_int	size;
	double		rad;

	imgs = &map->imgs;
	bg = imgs->way;
	rad = map->player->rad;
	draw_playerbg(&imgs->player_conv);
	draw_playerimg(&imgs->player_conv, imgs->player, rad + M_PI / 2L);
	size = make_pair_int(MAP2D_WIDTH / 2 * bg.size.x, \
	SCREEN_H - (MAP2D_HEIGHT / 2 + 1) * bg.size.y);
	mlx_put_image_to_window(mlx, win, imgs->player_conv.img, size.x, size.y);
}

void	display_map(t_map2d *info, void *mlx, void *win)
{
	t_pair_int	pos;
	t_pair_int	id;
	t_canvas	img;
	char		**map;

	map = info->map;
	pos = info->player->map_pos;
	id.y = pos.y;
	pos.y += MAP2D_HEIGHT;
	while (id.y < pos.y)
	{
		id.x = pos.x;
		while (id.x < pos.x + MAP2D_WIDTH)
		{
			img = select_image(&map[id.y][id.x], info->imgs);
			mlx_put_image_to_window(mlx, win, img.img, (id.x - pos.x) * \
			img.size.x, SCREEN_H + (id.y - pos.y) * img.size.y);
			id.x++;
		}
		id.y++;
	}
}

void	display_bg(t_map2d *info, void *mlx, void *win)
{
	t_canvas	img;
	t_pair_int	id;
	char		what;

	id.y = 0;
	what = '0';
	img = select_image(&what, info->imgs);
	while (id.y < MAP2D_HEIGHT - 1)
	{
		id.x = 0;
		while (id.x < MAP2D_WIDTH)
		{
			mlx_put_image_to_window(mlx, win, img.img, img.size.x \
			* id.x, SCREEN_H + (id.y - MAP2D_HEIGHT) * img.size.y);
			id.x++;
		}
		id.y++;
	}
}

void	display_minimap(t_map2d *info, void *mlx, void *win)
{
	draw_minimap(info, *(info->src), get_maxsize(*(info->src)));
	display_bg(info, mlx, win);
	display_map(info, mlx, win);
	display_player(info, mlx, win);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:48:15 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/30 18:48:17 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map2d_bonus.h"

void	draw_minimap(t_map2d *map, char **src, t_pair_int size)
{
	int		id;
	char	*inside;
	char	*dst;

	id = 0;
	while (id < size.y + MAP2D_HEIGHT - 1)
	{
		dst = map->map[id];
		ft_memset(dst, ' ', size.x + MAP2D_WIDTH - 1);
		if (id >= MAP2D_HEIGHT / 2 && id < size.y + MAP2D_HEIGHT / 2)
		{
			inside = src[id - MAP2D_HEIGHT / 2];
			ft_memcpy(dst + MAP2D_HEIGHT / 2, inside, ft_strlen(inside));
		}
		id++;
	}
}

void	draw_playerbg(t_canvas *ret)
{
	t_pair_int	xy;

	xy.y = 0;
	while (xy.y < ret->size.y)
	{
		xy.x = 0;
		while (xy.x < ret->size.x)
		{
			ret->addr[ret->size_l / (ret->bpp / 8) * xy.y + xy.x] = WAY_COLOR;
			xy.x++;
		}
		xy.y++;
	}
}

void	draw_playerimg(t_canvas *ret, t_canvas src, double rad)
{
	t_pair_int	xy;
	t_pair_int	nxy;
	t_pair_dbl	cxy;

	xy.y = 0;
	cxy = make_pair_dbl((double)src.size.x / 2, (double)src.size.y / 2 - 0.5);
	while (xy.y < src.size.y)
	{
		xy.x = 0;
		while (xy.x < src.size.x)
		{
			nxy.x = cos(rad) * ((double)xy.x - cxy.x) + \
			cxy.x - sin(rad) * ((double)xy.y - cxy.y) + 0.001;
			nxy.y = cos(rad) * ((double)xy.y - cxy.y) + \
			sin(rad) * ((double)xy.x - cxy.x) + cxy.y + 0.001;
			if (nxy.x >= 0 && nxy.y >= 0 && \
			nxy.y < src.size.y && nxy.x < src.size.x)
				ret->addr[ret->size_l / (ret->bpp / 8) * nxy.y + nxy.x] \
				= src.addr[xy.y * ret->size_l / (ret->bpp / 8) + xy.x];
			xy.x++;
		}
		xy.y++;
	}
}

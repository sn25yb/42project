/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:27:28 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/30 17:31:04 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "map2d.h"

int	add_mapinfo(t_map2d *map, char **src)
{
	t_pair_int	size;

	size = get_maxsize(src);
	map->map = make_array(size.y + MAP2D_HEIGHT - 1, size.x + MAP2D_WIDTH - 1);
	if (!map->map)
		return (EXTRA);
	draw_minimap(map, src, size);
	return (EXIT_SUCCESS);
}

int	add_player2d(t_canvas *conv, t_canvas player, void *mlx)
{
	*conv = player;
	conv->img = mlx_new_image(mlx, conv->size.x, conv->size.y);
	if (!conv->img)
		return (EXTRA);
	conv->addr = (unsigned int *)mlx_get_data_addr(conv->img, \
	&conv->bpp, &conv->size_l, &conv->endian);
	return (EXIT_SUCCESS);
}

int	add_mapimg2d(t_imgs2d *imgs, void *mlx)
{
	if (get_canvas(mlx, &imgs->target, "./texture/2d/obj.xpm"))
		return (IMG_FAILED);
	if (get_canvas(mlx, &imgs->way, "./texture/2d/way.xpm"))
		return (IMG_FAILED);
	if (get_canvas(mlx, &imgs->wall, "./texture/2d/wall.xpm"))
		return (IMG_FAILED);
	if (get_canvas(mlx, &imgs->door[0], "./texture/2d/door0.xpm"))
		return (IMG_FAILED);
	if (get_canvas(mlx, &imgs->door[1], "./texture/2d/door1.xpm"))
		return (IMG_FAILED);
	if (get_canvas(mlx, &imgs->empty, "./texture/2d/empty.xpm"))
		return (IMG_FAILED);
	if (get_canvas(mlx, &imgs->player, "./texture/2d/player.xpm"))
		return (IMG_FAILED);
	return (add_player2d(&imgs->player_conv, imgs->player, mlx));
}

int	add_minimap(t_map2d *map, char ***src, void *mlx)
{
	if (add_mapinfo(map, *src))
		return (EXTRA);
	map->src = src;
	return (add_mapimg2d(&map->imgs, mlx));
}

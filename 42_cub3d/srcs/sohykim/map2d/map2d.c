/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:27:28 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/24 14:27:34 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "map2d.h"

int	add_mapinfo(t_map2d *map, char **src)
{
	t_pair_int	xy;
	int			id;	

	ft_memset(&xy, 0, sizeof(t_pair_int));
	while (src[xy.y])
	{
		if ((int)ft_strlen(src[xy.y]) > xy.x)
			xy.x = (int)ft_strlen(src[xy.y]);
		xy.y++;
	}
	map->map = ft_calloc(xy.y + 11, sizeof(char *));
	if (!map->map)
		return (EXTRA);
	id = 0;
	while (id < xy.y + 10)
	{
		map->map[id] = ft_calloc(xy.x + 11, sizeof(char));
		if (!map->map[id])
			return (EXTRA);
		ft_memset(map->map[id], ' ', xy.x + 10);
		if (id >= 5 && id < xy.y + 5)
			ft_memcpy(map->map[id] + 5, src[id - 5], ft_strlen(src[id - 5]));
		id++;
	}
	return (EXIT_SUCCESS);
}

//door.xpm -> exit.xpm 수정 필요
int	add_objimg2d(t_map2d *map)
{
	char	**files;
	int		index;
	int		fd;
	int		code;

	index = -1;
	code = 0;
	files = ft_calloc(12, sizeof(char *));
	if (!files)
		code = EXTRA;
	fd = 0;
	while (++index < 9 && !code)
	{
		if (read_next_line("./textures/imglst/invlst", &files[index], &fd))
			code = EXTRA;
		if (!code && (!files[index] || \
		get_image(map->mlx, &map->object[index + 1], files[index])))
			code = IMG_FAILED;
	}
	if (fd > 0)
		close(fd);
	free_array(files);
	return (code);
}

//door -> exit.xpm
int	add_mapimg2d(t_map2d *map)
{
	if (get_image(map->mlx, &map->target, "./textures/2d/obj.xpm"))
		return (IMG_FAILED);
	if (get_image(map->mlx, &map->way, "./textures/2d/way.xpm"))
		return (IMG_FAILED);
	if (get_image(map->mlx, &map->wall, "./textures/2d/wall.xpm"))
		return (IMG_FAILED);
	if (get_image(map->mlx, &map->door[0], "./textures/2d/door0.xpm"))
		return (IMG_FAILED);
	if (get_image(map->mlx, &map->door[1], "./textures/2d/door1.xpm"))
		return (IMG_FAILED);
	if (get_image(map->mlx, &map->empty, "./textures/2d/empty.xpm"))
		return (IMG_FAILED);
	return (EXIT_SUCCESS);
}


int	add_minimap(t_map2d *map, char **src)
{
	int	code;

	code = add_objimg2d(map);
	if (!code)
		code = add_mapimg2d(map);
	if (!code)
		code = add_mapinfo(map, src);
	// if (get_image(map->mlx, &map->start, "./textures/2d/start.xpm"))
	// 	return (IMG_FAILED);
	// if (get_image(map->mlx, &map->logo, "./textures/2d/logo.xpm"))
	// 	return (IMG_FAILED);
	return (code);
}
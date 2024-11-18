/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:31:12 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/30 17:31:14 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "map2d.h"

char	**make_array(int h, int w)
{
	char	**ret;
	int		index;

	ret = ft_calloc(h + 1, sizeof(char *));
	if (!ret)
		return (NULL);
	index = 0;
	while (index < h)
	{
		ret[index] = ft_calloc(w + 1, sizeof(char));
		if (!ret[index])
		{
			free_array(ret);
			return (NULL);
		}
		index++;
	}
	return (ret);
}

t_pair_int	get_maxsize(char **src)
{
	t_pair_int	xy;

	ft_memset(&xy, 0, sizeof(t_pair_int));
	while (src[xy.y])
	{
		if ((int)ft_strlen(src[xy.y]) > xy.x)
			xy.x = (int)ft_strlen(src[xy.y]);
		xy.y++;
	}
	return (xy);
}

t_canvas	select_image(char *what, t_imgs2d imgs)
{
	if (*what == ' ')
		return (imgs.empty);
	else if (*what == '0' || *what == 'e')
		return (imgs.way);
	else if (*what == '1')
		return (imgs.wall);
	else if (*what != 'd')
		return (imgs.target);
	else if (*what == 'd' && is_wall(*(what + 1)))
		return (imgs.door[1]);
	return (imgs.door[0]);
}

void	free_2dmap_images(t_imgs2d *imgs, void *mlx)
{
	free_canvas(&imgs->wall, mlx);
	free_canvas(&imgs->empty, mlx);
	free_canvas(&imgs->way, mlx);
	free_canvas(&imgs->door[0], mlx);
	free_canvas(&imgs->door[1], mlx);
	free_canvas(&imgs->target, mlx);
	free_canvas(&imgs->player, mlx);
	free_canvas(&imgs->player_conv, mlx);
}

void	free_2dmap(t_map2d *map, void *mlx)
{
	free_array(map->map);
	free_2dmap_images(&map->imgs, mlx);
	ft_memset(map, 0, sizeof(t_map2d));
}

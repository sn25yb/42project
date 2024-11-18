/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:59:52 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/08 16:47:11 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	**make_intarray(t_pair_int size)
{
	int	**ret;
	int	id;

	ret = malloc(size.y * sizeof(int *));
	if (!ret)
		return (NULL);
	id = 0;
	while (id < size.y)
	{
		ret[id] = malloc(size.x * sizeof(int));
		if (!ret[id])
		{
			free_intarray(ret, size.y);
			return (NULL);
		}
		ft_memset(ret[id], 0, sizeof(int) * size.x);
		id++;
	}
	return (ret);
}

int	bfs(t_queues *q, int ***map_ptr, char **src)
{
	int			**map;
	t_pair_int	npos;
	t_pair_int	*pos;
	int			index;

	map = *map_ptr;
	index = 0;
	while (q->head)
	{
		index %= 4;
		pos = q->head->val;
		npos = make_dir(*pos, index++);
		if (!is_forbidden_route(src, npos.x, npos.y) && \
		(!map[npos.y][npos.x] || map[npos.y][npos.x] > \
		map[pos->y][pos->x] + 1) && !is_wall(src[npos.y][npos.x]))
		{
			map[npos.y][npos.x] = map[pos->y][pos->x] + 1;
			if (push(q, npos))
				return (EXTRA);
		}
		if (index % 4 == 0)
			pop(q);
	}
	*map_ptr = map;
	return (EXIT_SUCCESS);
}

t_pair_int	find_obj(char **map, char *c)
{
	t_pair_int		xy;
	t_pair_int		ret;
	char			*target;

	xy.y = 0;
	ft_memset(&ret, 0, sizeof(t_pair_int));
	while (map[xy.y])
	{
		target = ft_strchrset(map[xy.y], c);
		if (target)
		{
			xy.x = (int)(target - map[xy.y]);
			ret = make_pair_int(xy.x, xy.y);
			break ;
		}
		xy.y++;
	}
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:45:49 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/12 10:23:47 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d/cub3d_bonus.h"

void	make_escapemap(t_huibao *hui, char **src)
{
	t_pair_int	exit_pos;
	t_queues	q;
	int			**ret;
	t_pair_int	size;

	q.head = NULL;
	size = get_maxsize(src);
	ret = make_intarray(size);
	if (ret == NULL)
		return ;
	exit_pos = find_obj(src, "e");
	if (push(&q, exit_pos))
	{
		free_intarray(ret, size.y);
		return ;
	}
	ret[exit_pos.y][exit_pos.x] = 0;
	hui->map = ret;
	if (bfs(&q, &hui->map, src))
	{
		free_intarray(ret, size.y);
		hui->map = NULL;
		free_queue(q.head);
	}
	hui->mapsize = size.y;
}

int	add_huibao(t_huibao *hui, char **map)
{
	hui->map_pos = find_obj(map, "H");
	make_escapemap(hui, map);
	if (hui->map)
		return (EXIT_SUCCESS);
	return (EXTRA);
}

int	change_huipos(t_huibao *hui, char ***map, t_pair_int next)
{
	char		**set;

	set = *map;
	if (is_forbidden_route(set, next.x, next.y) || is_door(set[next.y][next.x]) \
	|| get_num_objs(set[next.y][next.x]) || !hui->map[next.y][next.x])
		return (EXIT_FAILURE);
	if (hui->map[next.y][next.x] > hui->map[hui->map_pos.y][hui->map_pos.x])
	{
		set[next.y][next.x] = 'H';
		set[hui->map_pos.y][hui->map_pos.x] = '0';
		hui->map_pos = next;
		*map = set;
		hui->block = FALSE;
		return (EXIT_SUCCESS);
	}
	hui->block = TRUE;
	return (EXIT_FAILURE);
}

void	escape_hui(t_huibao *hui, char ***map)
{
	int			index;
	t_pair_int	*pos;
	t_pair_int	next;

	index = 4;
	pos = &hui->map_pos;
	if (hui->block && hui->map[pos->y][pos->x] >= 2)
		hui->map[pos->y][pos->x]--;
	while (--index >= 0)
	{
		next = make_dir(*pos, index);
		if (!change_huipos(hui, map, next))
			break ;
	}
}

void	free_huibao(t_huibao *hui)
{
	free_intarray(hui->map, hui->mapsize);
}

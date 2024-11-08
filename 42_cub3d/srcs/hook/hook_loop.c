/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:45:49 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/08 16:47:36 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d/cub3d.h"

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

void	escape_hui(t_huibao *hui, char ***map)
{
	int			index;
	t_pair_int	next;
	t_pair_int	*pos;
	char		**set;

	index = 4;
	pos = &hui->map_pos;
	set = *map;
	while (--index >= 0)
	{
		next = make_dir(hui->map_pos, index);
		if (is_forbidden_route(set, next.x, next.y) || \
		get_num_objs(set[next.y][next.x]) || !hui->map[next.y][next.x])
			continue ;
		if (hui->map[next.y][next.x] > hui->map[pos->y][pos->x] || hui->flag)
		{
			set[next.y][next.x] = 'H';
			set[pos->y][pos->x] = '0';
			*pos = next;
			*map = set;
			hui->flag = FALSE;
			return ;
		}
	}
	hui->flag = TRUE;
}

void	free_huibao(t_huibao *hui)
{
	free_intarray(hui->map, hui->mapsize);
}

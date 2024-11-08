/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:51:22 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/24 12:51:24 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rule.h"

static t_boolean	is_player(char c)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return (TRUE);
	return (FALSE);
}

t_boolean	is_validplayer(char **map, t_pair_int *pos)
{
	t_pair_int	xy;
	int			flag;

	xy.y = 0;
	flag = 0;
	while (map[xy.y])
	{
		xy.x = 0;
		while (map[xy.y][xy.x])
		{
			if (is_player(map[xy.y][xy.x]))
			{
				*pos = xy;
				flag++;
			}
			xy.x++;
		}
		xy.y++;
	}
	if (flag != 1)
		return (FALSE);
	return (TRUE);
}

// void	print_array(char **arr)
// {
// 	for (int i = 0; arr[i] != 0; i++)
// 	{
// 		for (int j = 0; arr[i][j] != 0; j++)
// 			printf("%c", arr[i][j]);
// 		printf("\n");
// 	}
// }

int	is_allthings(int objs[11])
{
	if (count_objs(objs) && objs[10] == 1)
		return (EXIT_SUCCESS);
	return (MAP_FAILED);
}

t_err	check_route(t_queues *q, char **map, char **cpy)
{
	t_pair_int	npos;
	t_pair_int	*pos;
	int			index;
	int			objs[11];

	ft_memset(objs, 0, sizeof(objs));
	index = 0;
	while (q->head)
	{
		pos = q->head->val;
		npos = make_dir(*pos, index++ % 4);
		if (is_forbidden_route(map, npos.x, npos.y))
			return (MAP_FAILED);
		pick_objs(objs, cpy[npos.y][npos.x]);
		pick_exit(cpy[npos.y][npos.x], &objs[10]);
		if (cpy[npos.y][npos.x] != 'e' && cpy[npos.y][npos.x] != '1')
		{
			if (push(q, npos))
				return (EXTRA);
		}
		cpy[npos.y][npos.x] = '1';
		if (index % 4 == 0)
			pop(q);
	}
	return (is_allthings(objs));
}

t_err	check_player(char **map)
{
	char		**cpy;
	t_queues	q;
	t_err		code;
	t_pair_int	pos;

	if (!is_validplayer(map, &pos))
		return (MAP_FAILED);
	cpy = arrcpy(map);
	q.head = NULL;
	if (!cpy || push(&q, pos))
	{
		free_array(cpy);
		return (EXTRA);
	}
	cpy[pos.y][pos.x] = '1';
	code = check_route(&q, map, cpy);
	free_array(cpy);
	free_queue(q.head);
	return (code);
}

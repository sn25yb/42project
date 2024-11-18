/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:51:00 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/13 10:45:24 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rule_bonus.h"

t_boolean	is_forbidden_route(char **map, int x, int y)
{
	if (x < 0 || y < 0)
		return (TRUE);
	if (!map[y] || (int)ft_strlen(map[y]) <= x)
		return (TRUE);
	if (map[y][x] == ' ')
		return (TRUE);
	return (FALSE);
}

// valid door must be from '0' to '0' (or object/panda)
// valid door has wall on both sides (inline).
// valid door must not be with another door or exit.
t_boolean	is_validdoor(char **map, t_pair_int xy)
{
	t_pair_int	nxy;
	int			index;
	int			wall[4];

	index = -1;
	while (++index < 4)
	{
		nxy = make_dir(xy, index);
		if (is_forbidden_route(map, nxy.x, nxy.y))
			return (FALSE);
		else if (map[nxy.y][nxy.x] == 'd' || map[nxy.y][nxy.x] == 'e')
			return (FALSE);
		else if (is_wall(map[nxy.y][nxy.x]))
			wall[index] = 1;
		else
			wall[index] = 0;
	}
	if (wall[NORTH] && wall[SOUTH] && !wall[EAST] && !wall[WEST])
		return (TRUE);
	if (!wall[NORTH] && !wall[SOUTH] && wall[EAST] && wall[WEST])
		return (TRUE);
	return (FALSE);
}

t_err	check_door(char **map)
{
	t_pair_int	xy;

	xy.y = 0;
	while (map[xy.y])
	{
		xy.x = 0;
		while (map[xy.y][xy.x])
		{
			if (map[xy.y][xy.x] == 'd' && !is_validdoor(map, xy))
				return (MAP_FAILED);
			xy.x++;
		}
		xy.y++;
	}
	return (EXIT_SUCCESS);
}

// valid exit must not be with another door.
// valid exit must be route to out(' ' or '\0' or invalid index)
t_boolean	is_validexit(char **map, t_pair_int xy)
{
	t_pair_int	nxy;
	int			index;
	int			wall[4];
	int			flag;

	index = -1;
	flag = 0;
	ft_memset(wall, 0, sizeof(int) * 4);
	while (++index < 4)
	{
		nxy = make_dir(xy, index);
		if (is_forbidden_route(map, nxy.x, nxy.y))
			flag = 1;
		else if (map[nxy.y][nxy.x] == 'd')
			return (FALSE);
		else if (is_wall(map[nxy.y][nxy.x]))
			wall[index] = 1;
	}
	if (flag && wall[NORTH] && wall[SOUTH] && !wall[EAST] && !wall[WEST])
		return (TRUE);
	if (flag && !wall[NORTH] && !wall[SOUTH] && wall[EAST] && wall[WEST])
		return (TRUE);
	return (FALSE);
}

t_err	check_exit(char **map)
{
	t_pair_int	xy;

	xy.y = 0;
	while (map[xy.y])
	{
		if (ft_strchr(map[xy.y], 'e'))
		{
			xy.x = ft_strchr(map[xy.y], 'e') - map[xy.y];
			if (is_validexit(map, xy))
				return (EXIT_SUCCESS);
			break ;
		}
		xy.y++;
	}
	return (MAP_FAILED);
}

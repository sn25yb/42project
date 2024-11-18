/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:42:44 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/13 11:21:01 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rule_bonus.h"

t_boolean	check_left(char *line, int id)
{
	while (id >= 0 && line[id])
	{
		if (is_wall(line[id]) || line[id] == 'e')
			return (TRUE);
		if (line[id] == ' ')
			return (FALSE);
		id--;
	}
	return (FALSE);
}

t_boolean	check_right(char *line, int id)
{
	while (line[id])
	{
		if (is_wall(line[id]) || line[id] == 'e')
			return (TRUE);
		if (line[id] == ' ')
			return (FALSE);
		id++;
	}
	return (FALSE);
}

t_boolean	check_bottom(char **check, t_pair_int xy)
{
	int	len;

	while (check[xy.y])
	{
		len = ft_strlen(check[xy.y]);
		if (len <= xy.x)
			return (FALSE);
		if (check[xy.y][xy.x] == '1' || check[xy.y][xy.x] == 'e')
			return (TRUE);
		if (check[xy.y][xy.x] == ' ')
			return (FALSE);
		xy.y++;
	}
	return (FALSE);
}

t_boolean	check_top(char **check, t_pair_int xy)
{
	int	len;

	while (xy.y >= 0 && check[xy.y])
	{
		len = ft_strlen(check[xy.y]);
		if (len <= xy.x)
			return (FALSE);
		if (check[xy.y][xy.x] == '1' || check[xy.y][xy.x] == 'e')
			return (TRUE);
		if (check[xy.y][xy.x] == ' ')
			return (FALSE);
		xy.y--;
	}
	return (FALSE);
}

// in the condition of map without invalid char
// the valid objs has wall or exit for end of four sides.
// cpy value has changed to '1' if it is ok, for calculation to reduce.
t_err	is_surrbywall(char **map, char **cpy)
{
	t_pair_int	xy;

	xy.y = -1;
	while (map[++xy.y])
	{
		xy.x = -1;
		while (map[xy.y][++xy.x])
		{
			if (map[xy.y][xy.x] == '0' || get_num_objs(map[xy.y][xy.x]))
			{
				if (!check_bottom(cpy, xy) || !check_top(cpy, xy) || \
				!check_left(cpy[xy.y], xy.x) || !check_right(cpy[xy.y], xy.x))
					return (MAP_FAILED);
				cpy[xy.y][xy.x] = '1';
			}
		}
	}
	return (EXIT_SUCCESS);
}

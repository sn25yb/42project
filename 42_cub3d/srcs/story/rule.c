/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:34:48 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/26 19:55:23 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "script.h"

t_objs	find_preq(t_objs panda)
{
	if (panda == LEBAO)
		return (wotou);
	else if (panda == AIBAO)
		return (kangbao);
	else if (panda == HUIBAO)
		return (boots);
	else if (panda == RUIBAO)
		return (carrot);
	else
		return (no_obj);
}

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
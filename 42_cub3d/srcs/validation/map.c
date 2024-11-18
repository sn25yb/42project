/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:24:20 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/13 11:37:48 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rule.h"

// map must not have "\n\n" in the middle of the map.
t_err	set_map(char ***map, char *line)
{
	size_t	idx;
	char	*target;

	idx = 0;
	if (!line)
		return (MAP_FAILED);
	while (line[idx] == '\n')
		idx++;
	target = ft_strnstr(&line[idx], "\n\n", ft_strlen(&line[idx]));
	while (target && *target == '\n')
		target++;
	if (target && *target)
		return (MAP_FAILED);
	*map = ft_split(line, "\n");
	if (*map == NULL)
		return (EXTRA);
	return (EXIT_SUCCESS);
}

t_err	check_validmap(char **map)
{
	t_err	code;
	char	**cpy;

	code = EXIT_SUCCESS;
	cpy = arrcpy(map);
	if (!cpy)
		code = EXTRA;
	if (!code)
		code = is_surrbywall(map, cpy);
	if (!code)
		code = check_object(map);
	if (!code)
		code = check_player(map);
	if (!code)
		code = check_door(map);
	if (!code)
		code = check_exit(map);
	free_array(cpy);
	return (code);
}

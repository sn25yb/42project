/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:24:20 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/24 16:24:22 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rule.h"

t_err	set_map(char ***map, char *line)
{
	if (!line)
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
	if (code)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:45:24 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/30 18:45:26 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

t_err	add_line(t_game *game, char **line)
{
	char	**sp;
	t_err	code;

	sp = ft_split(*line, " \n\t\f\v\r");
	free(*line);
	*line = NULL;
	if (!sp)
		code = EXTRA;
	else if (sp[0] && sp[1] && !sp[2])
		code = check_info(game, sp);
	else if (sp[0])
		code = MAP_FAILED;
	else
		code = EXIT_FAILURE;
	free_array(sp);
	return (code);
}

t_err	set_next_line(char **line, int fd)
{
	*line = get_next_line(fd);
	if (*line == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

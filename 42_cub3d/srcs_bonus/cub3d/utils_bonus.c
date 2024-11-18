/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:45:24 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/14 10:38:22 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_err	add_line(t_game *game, char **line, int *cnt)
{
	char	**sp;
	t_err	code;

	sp = ft_split(*line, " \t\f\v\r");
	free(*line);
	*line = NULL;
	code = EXIT_SUCCESS;
	if (!sp)
		code = EXTRA;
	else if (sp[0] && sp[1] && !sp[2])
		code = check_info(game, sp);
	else if (sp[0])
		code = MAP_FAILED;
	if (!code && sp[0])
		*cnt += 1;
	free_array(sp);
	return (code);
}

t_err	set_next_line(char **line, int fd)
{
	*line = get_next_line(fd);
	if (*line == NULL)
	{
		close(fd);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

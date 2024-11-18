/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:39:59 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/13 11:22:30 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	add_wall(t_game *game, char *file, int index)
{
	if (game->rnd3d.texfile[index])
		return (MAP_FAILED);
	game->rnd3d.texfile[index] = ft_strdup(file);
	if (!game->rnd3d.texfile[index])
		return (EXTRA);
	return (EXIT_SUCCESS);
}

void	check_valid(t_game *game, int argc, char **argv)
{
	size_t	len;

	if (argc != 2)
		exit_game(game, ARG_FAILED);
	len = ft_strlen(argv[1]);
	if (len < 5)
		exit_game(game, ARG_FAILED);
	if (ft_memcmp(argv[1] + len - 4, ".cub", 5))
		exit_game(game, ARG_FAILED);
}

t_err	check_rgb(t_rgb *rgb, char *rgb_line)
{
	char	**rgb_lines;
	int		code ;

	if (*rgb_line && (rgb_line[ft_strlen(rgb_line) - 1] == ',' \
	|| ft_strnstr(rgb_line, ",,", ft_strlen(rgb_line)) || *rgb_line == ','))
		return (MAP_FAILED);
	rgb_lines = ft_split(rgb_line, ",");
	if (!rgb_lines)
		return (EXTRA);
	if (!rgb_lines[0] || !rgb_lines[1] || !rgb_lines[2] || rgb_lines[3])
	{
		free_array(rgb_lines);
		return (MAP_FAILED);
	}
	rgb->r = ft_atoi(rgb_lines[0]);
	rgb->g = ft_atoi(rgb_lines[1]);
	rgb->b = ft_atoi(rgb_lines[2]);
	code = check_rgbnum(ft_atoi(rgb_lines[0]), rgb_lines[0]);
	if (!code)
		code = check_rgbnum(ft_atoi(rgb_lines[1]), rgb_lines[1]);
	if (!code)
		code = check_rgbnum(ft_atoi(rgb_lines[2]), rgb_lines[2]);
	free_array(rgb_lines);
	return (code);
}

t_err	check_info(t_game *game, char **info)
{
	const char	*id[6] = {"EA", "WE", "SO", "NO", "F", "C"};
	int			index;

	index = 0;
	while (index < 4)
	{
		if (!ft_memcmp(info[0], id[index], 3))
			return (add_wall(game, info[1], index));
		index++;
	}
	if (!ft_memcmp(info[0], id[index], 2) && !game->rnd3d.tex3d.floor.flag)
	{
		game->rnd3d.tex3d.floor.flag = 1;
		return (check_rgb(&game->rnd3d.tex3d.floor, info[1]));
	}
	if (!ft_memcmp(info[0], id[++index], 2) && !game->rnd3d.tex3d.ceil.flag)
	{
		game->rnd3d.tex3d.ceil.flag = 1;
		return (check_rgb(&game->rnd3d.tex3d.ceil, info[1]));
	}
	return (MAP_FAILED);
}

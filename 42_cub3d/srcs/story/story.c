/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   story.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:25:39 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/24 16:25:42 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "script.h"

int	set_script(t_script *script, char *file)
{
	char	*line;
	int		len;
	int		index;
	int		fd;

	len = 0;
	index = 0;
	fd = 0;
	script->id = 0;
	script->ing = TRUE;
	script->lines = ft_calloc(10, sizeof(char *));
	while (TRUE)
	{
		if (read_next_line(file, &script->lines[index], &fd))
			return (EXTRA);
		if (!script->lines[index])
			break ;
		index++;
	}
	// for (int i = 0; script->lines[i] != 0; i++)
	// 	printf("%s\n", script->lines[i]);
	return (EXIT_SUCCESS);
}

int	set_scene(t_script *script)
{
	const char	*files[13] = {"", "wotou", "boots", "carrot", "kangbao", "lebao"\
	, "aibao", "fubao", "huibao", "ruibao", "outro1", "outro2", "intro"};
	const char	*base = "script/";
	char		*ret;
	
	ret = ft_strjoin(base, files[script->scene_num]);
	if (!ret || set_script(script, ret))
	{
		free(ret);
		return (EXTRA);
	}
	free(ret);
	return (EXIT_SUCCESS);
}

void	show_msg(t_script *script, void *mlx, void *win)
{
	int			scene_num;
	t_pair_int	size;

	size = script->chat.size;
	scene_num = script->scene_num;
	if (scene_num == INTRO || scene_num == OUTRO || scene_num == OUTRO2)
		mlx_clear_window(mlx, win);
	mlx_put_image_to_window(mlx, win, script->chat.image, SCREEN_WIDTH / 2 - \
	size.x / 2, SCREEN_HEIGHT - size.y);
	mlx_string_put(mlx, win, SCREEN_WIDTH / 2 - size.x / 2 + MARGIN_L, \
	SCREEN_HEIGHT - size.y / 2, FONT_DARK, script->lines[script->id]);
}
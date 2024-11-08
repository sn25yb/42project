/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   script.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:00:56 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/08 17:59:10 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "script.h"

int	set_script(t_script *script, char *file)
{
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

void	display_msgbox(t_script *script, void *mlx, void *win)
{
	t_pair_int	size;

	size = script->chat.size;
	mlx_put_image_to_window(mlx, win, script->chat.img, SCREEN_W / 2 - \
	size.x / 2, SCREEN_H - size.y);
	mlx_string_put(mlx, win, SCREEN_W / 2 - size.x / 2 + MARGIN_L, \
	SCREEN_H - size.y / 2, FONT_DARK, script->lines[script->id]);
}

int	get_profile_idx(t_script *script)
{
	const char	*name[N_PROFILE] = \
	{"[Songbao] ", "[Aibao]", "[Lebao]", "[Fubao]", "[Ruibao]", "[Huibao]", "[Kangbao]"};
	int			idx;
	int			cur_id;

	idx = 0;
	cur_id = script->id;
	while (idx < N_PROFILE && name[idx])
	{
		if (!ft_memcmp(script->lines[cur_id], name[idx], ft_strlen(name[idx])))
			return (idx);
		idx++;
	}
	return (-1);
}

void	display_profile(t_script *script, void *mlx, void *win)
{
	t_pair_int	pos;
	int			idx;
	int			scene_num;

	scene_num = script->scene_num;
	if (scene_num == INTRO || scene_num == OUTRO || scene_num == OUTRO2)
		mlx_clear_window(mlx, win);
	idx = get_profile_idx(script);
	if (idx == -1)
		return ;
	pos.x = SCREEN_W / 2 - script->chat.size.x / 2;
	pos.y = SCREEN_H - script->chat.size.y - script->profile->size.y;
	if (idx)
		pos.x += script->chat.size.x - script->profile->size.x;
	mlx_put_image_to_window(mlx, win, script->profile[idx].img, pos.x, pos.y);
}

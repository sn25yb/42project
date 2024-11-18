/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:41:51 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/11 17:00:37 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "script_bonus.h"

int	add_msgbox(t_script *script, void *mlx)
{
	while (script->scene_num != INTRO)
	{
		script->scene_num += 1;
		if (set_scene(script))
			return (EXTRA);
		init_scriptinfo(script);
	}
	return (get_canvas(mlx, &script->chat, SCRIPT_IMG));
}

int	add_profile(t_script *script, void *mlx)
{
	int			code;
	int			fd;
	int			idx;
	char		*file;

	code = EXIT_SUCCESS;
	fd = 0;
	idx = 0;
	while (idx < N_PROFILE && code == EXIT_SUCCESS)
	{
		code = read_next_line("./texture/texlst/profile", &file, &fd);
		if (code == EXIT_SUCCESS)
			code = get_canvas(mlx, &script->profile[idx], file);
		free(file);
		idx++;
	}
	if (fd > 0)
		close(fd);
	return (code);
}

void	free_script(t_script *script, void *mlx)
{
	free_canvas(&script->chat, mlx);
	free_array(script->lines);
	ft_memset(script, 0, sizeof(t_script));
}

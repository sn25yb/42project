/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:41:51 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/30 18:41:53 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "script.h"

int	add_msgbox(t_script *script, void *mlx)
{
	script->scene_num = INTRO;
	return (get_canvas(mlx, &script->chat, SCRIPT_IMG));
}

int	add_profile(t_script *script, void *mlx)
{
	char	*file;
	int		idx;
	int		fd;
	int		code;

	fd = 0;
	idx = 0;
	code = EXIT_SUCCESS;
	while (idx < N_PROFILE)
	{
		if (read_next_line("./texture/texlst/profile", &file, &fd))
			code = EXTRA;
		if (!code && (!file || get_canvas(mlx, &script->profile[idx], file)))
			code = IMG_FAILED;
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

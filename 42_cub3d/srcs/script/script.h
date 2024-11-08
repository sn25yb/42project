/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   script.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:08:42 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/08 18:00:22 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCRIPT_H
# define SCRIPT_H
# include "mlx/mlx.h"
# include "../canvas/canvas.h"
# include "srcs/object/object.h"
# include "libft/libft/libft.h"
# include "libft/base/lib.h"

# define SCREEN_W 1920
# define SCREEN_H 1080
# define FONT_LIGHT 0xffffff
# define FONT_DARK 0x000000
# define MARGIN_L 50
# define SCRIPT_IMG "./texture/2d/script.xpm"
# define N_PROFILE 7

typedef struct s_script
{
	t_canvas	chat;
	t_canvas	profile[N_PROFILE];
	char		**lines;
	int			id;
	int			scene_num;
	t_boolean	ing;
}	t_script;

typedef enum e_storyline
{
	OUTRO = 10,
	OUTRO2,
	INTRO,
}	t_storyline;

t_objs		find_preq(t_objs panda);
t_boolean	is_forbidden_route(char **map, int x, int y);
void		display_msgbox(t_script *script, void *mlx, void *win);
void		display_profile(t_script *script, void *mlx, void *win);
int			set_scene(t_script *script);
void		free_script(t_script *script, void *mlx);
int			add_msgbox(t_script *script, void *mlx);
int			add_profile(t_script *script, void *mlx);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   script.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:08:42 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/14 15:16:31 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCRIPT_BONUS_H
# define SCRIPT_BONUS_H
# include "mlx/mlx.h"
# include "../canvas/canvas_bonus.h"
# include "srcs_bonus/object/object_bonus.h"
# include "srcs_bonus/utils/utils_bonus.h" 
# include "libft/libft/libft.h"
# include "libft/base/lib.h"

# define FONT_LIGHT 0xffffff
# define FONT_DARK 0x000000
# define MARGIN_L 50
# define MARGIN_T 50
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
	NO_SCENE = 0,
	OUTRO = 10,
	OUTRO2,
	INTRO,
	GAME_OVER
}	t_storyline;

t_objs		find_preq(t_objs panda);
void		display_msgbox(t_script *script, void *mlx, void *win);
void		display_profile(t_script *script, void *mlx, void *win);
int			set_scene(t_script *script);
void		free_script(t_script *script, void *mlx);
int			add_msgbox(t_script *script, void *mlx);
int			add_profile(t_script *script, void *mlx);
void		init_scriptinfo(t_script *script);

#endif

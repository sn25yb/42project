/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:30:34 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/13 12:06:43 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "libft/libft/libft.h"
# include "libft/error/ft_err.h"
# include "libft/libgnl/get_next_line.h"
# include "libft/queue/queue.h"
# include "libft/base/pair.h"
# include "srcs/minimap/map2d.h"
# include "srcs/object/object.h"
# include "srcs/script/script.h"
# include "srcs/rnd3d/rnd3d.h"
# include "srcs/view/view.h"
# include "srcs/utils/utils.h"
# include "srcs/validation/rule.h"

# define DESTROY_NOTIFY 17
# define KEY_RELEASE 3
# define KEY_PRESS 2
# define MOUSE_PRESS 4
# define MOUSE_RELEASE 5
# define MOUSE_MOVE 6

typedef struct s_key
{
	t_pair_int	pos;
	t_boolean	on;
}	t_key;

typedef struct s_setting
{
	t_key		mouse;
	t_key		btn;
	t_boolean	is_begin;
	t_boolean	game_over;
	t_boolean	game_clear;
	t_boolean	is_ending;
	t_pair_int	exit_pos;
	long		start_time;
}	t_setting;

typedef struct s_rnd2d
{
	void		**mlx;
	void		**win;
	t_map2d		minimap;
	t_script	script;
	t_canvas	startbg;
	t_inventory	inventory;
}	t_rnd2d;

typedef struct s_huibao
{
	t_pair_int	map_pos;
	int			mapsize;
	int			**map;
	int			speed;
	t_boolean	block;
}	t_huibao;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	t_huibao	hui;
	t_view		player;
	t_rnd3d		rnd3d;
	t_rnd2d		rnd2d;
	t_setting	set;
}	t_game;

// huibao.c
int			add_huibao(t_huibao *hui, char **map);
void		escape_hui(t_huibao *hui, char ***map);
void		free_huibao(t_huibao *hui);

// event.c
void		player_move(t_game *game, int keycode);
int			check_event(t_game *game);
int			get_scene(t_game *game);

// exit.c
void		exit_game(t_game *game, int code);

// hook.c
int			event_wt_user(int keycode, t_game *game);
int			mouse_motion(int x, int y, t_game *game);
int			display_images_hook(t_game *game);
int			destroy_game(t_game *game);

// arg.c
void		check_valid(t_game *game, int argc, char **argv);
t_err		check_info(t_game *game, char **info);

// setting.c
void		add(t_game *game, char *file);

// display.c
void		display_startscreen(t_game *game);
void		display_images(t_game *game);

// utils.c
t_err		set_next_line(char **line, int fd);
t_err		add_line(t_game *game, char **line, int *cnt);

// rule.c
void		start_game(t_game *game);
t_boolean	collect_pandas(t_game *game);
void		end_game(t_game *game);
t_boolean	get_objs(t_game *game, t_objs objs);
int			check_escape(t_game *game);

//rendering(3d)
int			add_tex3d(t_game *game);
void		display_3ds(t_game *game);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:30:34 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/27 00:30:09 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <sys/time.h>
# include <fcntl.h>
# include <stdio.h>

# include "mlx/mlx.h"
# include "libft/libft/libft.h"
# include "libft/ft_err.h"
# include "libft/libgnl/get_next_line.h"
# include "libft/queue/queue.h"
# include "libft/base/pair.h"
# include "srcs/sohykim/map2d/map2d.h"
# include "srcs/sohykim/object/object.h"
# include "srcs/story/script.h"
# include "srcs/yubshin/rnd3d.h"

# define DESTROY_NOTIFY 17
# define KEY_RELEASE 3
# define KEY_PRESS 2
# define MOUSE_PRESS 4
# define MOUSE_RELEASE 5
# define MOUSE_MOVE 6

# define KEY_SPACE 49
# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_ENTER 36
# define KEY_ESC 53

# define EAST 0
# define WEST 1
# define SOUTH 2
# define NORTH 3
// # define SCREEN_WIDTH 640
// # define SCREEN_HEIGHT 480
# define WAY_COLOR 0xFCF9D4

# define P_STEP 0.5
# define TIMELIMIT 100

typedef struct s_player
{
	t_pair_dbl	pos;
	t_pair_dbl	dir;
	double		rad;
}	t_player;

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
	long		gamestart;
}	t_setting;

typedef struct s_rnd2d
{
	/* data */
	t_map2d		minimap;
	t_script	script;
	t_img2d		startbg;
	t_inventory	inventory;
}	t_rnd2d;


typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	t_player	player;
	t_rnd3d		rnd;
	t_rnd2d		rnd2d;
	t_setting	set;
}	t_game;

// utils.c
const char	*numstr(t_objs objs);
t_pair_dbl	dir_to_coord(int dir);
double		cal_radian(t_pair_dbl dir);
void		change_pos(t_player *p, int keycode);
void		change_dir(t_player *p, double x);

// event.c
t_boolean	is_reachable(char **map, int x, int y);

// rule.c
t_boolean	get_objs(t_game *game, t_objs objs);
int			check_escape(t_game *game);

//map.c
t_err		set_next_line(char **line, int fd);
t_err		set_map(t_game *game, char *line);
t_err		add_line(t_game *game, char **line);

//object.c
void		pick_exit(char c, int *num);
t_err		check_object(char **map);
t_boolean	count_objs(int objs[11]);

// player.c
void		pick_objs(int objs[11], char c);
t_err		check_player(char **map, t_pair_dbl *pos);

// exit.c
void		exit_game(t_game *game, int code);
int			destroy_game(t_game *game);

// arg.c
void		check_valid(t_game *game, int argc, char **argv);
t_err		check_info(t_game *game, char **info);

// setting.c
void		add(t_game *game, char *file);

// map.c
t_err		check_validmap(char **map, t_pair_dbl *pos);
t_pair_int	make_dir(t_pair_int xy, int dir);

// event.c
int			event_wt_user(int keycode, t_game *game);
int			mouse_motion(int x, int y, t_game *game);
int			mouse_release(int button, int x, int y, t_game *game);
int			get_scene(t_game *game);

// draw.c
int			draw_images_hook(t_game *game);
void		draw_images(t_game *game);
void		draw_startscreen(t_game *game);

//door.c
t_err		check_door(char **map);
t_err		check_exit(char **map);

// wall.c
t_err		is_surrbywall(char **map, char **cpy);

// rule.c
t_boolean	collect_pandas(t_game *game);
void		start_game(t_game *game);
void		end_game(t_game *game);

//rendering(3d)
void		add_imgs3d(t_game *game);
void		draw_3dmap(t_game *game);
void		init_render(t_rnd3d*rnd, t_player player, char **map);
#endif

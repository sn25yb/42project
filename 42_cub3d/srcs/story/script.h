#ifndef SCRIPT_H
# define SCRIPT_H
# include "../../mlx/mlx.h"
# include "../sohykim/image2d/image2d.h"
# include "../sohykim/object/object.h"
# include "libft/libft/libft.h"

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define FONT_LIGHT 0xffffff
# define FONT_DARK 0x000000
# define MARGIN_L 50
# define SCRIPT_IMG "./textures/2d/script.xpm"

typedef struct s_script
{
    t_img2d 	chat;
	char		**lines;
	int			id;
	int			scene_num;
	t_boolean	ing;
}   t_script;

typedef enum e_storyline
{
	OUTRO = 10,
	OUTRO2,
	INTRO,
}	t_storyline;

t_objs		find_preq(t_objs panda);
t_boolean	is_forbidden_route(char **map, int x, int y);
void		show_msg(t_script *script, void *mlx, void *win);
int			set_scene(t_script *script);

# endif
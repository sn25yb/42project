/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rnd3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:22:52 by yubshin           #+#    #+#             */
/*   Updated: 2024/11/08 16:29:42 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RND3D_H
# define RND3D_H

# include "../../libft/base/pair.h"
# include "../tex3d/tex3d.h"
# include "srcs/view/view.h"

# include <stdio.h>

typedef struct s_sprite
{
	t_pair_dbl		pos;
	double			dist;
	int				idx;
}	t_sprite;

typedef struct s_wall
{
	t_pair_int		map;
	t_pair_int		step;
	t_pair_dbl		raydir;
	t_pair_dbl		deltadist;
	t_pair_dbl		sidedist;
	double			perpwalldist;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	double			wall_x;
	unsigned int	*texture;
	t_pair_int		tex;

}	t_wall;

typedef struct s_obj
{
	double			z_buffer[SCREEN_W];
	t_sprite		sprites[N_OBJ];
	t_pair_dbl		transform;
	int				sprite_screenx;
	int				sprite_h;
	int				sprite_w;
	t_pair_int		drawstart;
	t_pair_int		drawend;
	t_pair_int		tex;
}	t_obj;

typedef struct s_rnd3d
{
	t_view		view;
	t_wall		wall;
	t_obj		obj;
	t_tex3d		tex3d;
	char		*texfile[N_WALL];
}	t_rnd3d;

// rnd3d_view.c
void	update_rnd3d_view(t_rnd3d *rnd3d, t_view view);
// anim_update.c
void	update_anim(t_anim *anim, t_pair_dbl pos, char **map);
// rnd3d_ceilfloor.c
void	rnd_ceilfloor(t_canvas *display, t_rgb ceil, t_rgb floor);
// rnd3d_obj.c
void	rnd_obj(t_rnd3d*rnd, char **map);
// rnd3d_wall.c
void	rnd3d_wall(t_rnd3d *rnd, char **map);
// rnd3d_wall_dda.c
void	dda_wall(t_wall *wall, char **map);
// rnd3d_wall_raycal.c
void	cal_raydir_pair(t_view view, t_wall *wall, int x);
void	cal_map_pair(t_view view, t_wall *wall);
void	cal_deltadist_pair(t_wall *wall);
void	cal_sidedist_pair(t_view view, t_wall *wall);
void	cal_step_pair(t_wall *wall);
// rnd3d_wall_drawcal.c
void	cal_perpwalldist(t_view view, t_wall *wall);
void	cal_lineheight(t_wall *wall);
void	cal_drawstartend(t_wall *wall);
void	set_texture(t_wall *wall, t_tex3d tex3d, char **map);
void	cal_wall_x(t_view view, t_wall *wall);
// rnd3d_wall_draw.c
void	draw_canvas_wall(t_wall *wall, t_tex3d *tex3d, int x);
// rnd3d_obj_cal.c
void	save_sprite_pos(char **map, t_obj *obj);
void	cal_sprite_distance(t_view view, t_obj *obj);
void	sort_sprites(t_obj *obj);
// rnd3d_obj_draw.c
void	cal_sprite_screen_params(t_sprite sprite, t_view view, t_obj *obj);
void	cal_sprite_display_range(t_obj *obj);
void	draw_canvas_obj(t_obj *obj, t_tex3d *tex3d, t_sprite sprite);

#endif

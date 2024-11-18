/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:34:43 by yubshin           #+#    #+#             */
/*   Updated: 2024/11/14 15:15:29 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEX3D_BONUS_H
# define TEX3D_BONUS_H

# include "../libft/base/pair.h"
# include "../canvas/canvas_bonus.h"
# include "../libft/base/lib.h"
# include "../time/time_bonus.h"
# include <math.h>

# define OBJ_FTIME 0.5
# define DOOR_FTIME 0.1
# define PROX_ANIM 3.0

typedef enum e_texnum
{
	N_WALL = 4,
	N_OBJ = 9,
	N_ANIM = 4,
	N_DOOR = 1
}	t_texnum;

typedef enum e_wall_idx
{
	I_EAST = 0,
	I_WEST = 1,
	I_SOUTH = 2,
	I_NORTH = 3
}	t_wall_idx;

typedef enum e_obj_idx
{
	I_AIBAO = 0,
	I_LEBAO = 1,
	I_FUBAO = 2,
	I_RUIBAO = 3,
	I_HUIBAO = 4,
	I_BOOTS = 5,
	I_CARROT = 6,
	I_KANG = 7,
	I_WOTOU = 8
}	t_obj_idx;

typedef struct s_anim
{
	long	global_ftime;
	long	prox_ftime;
	int		global_fidx;
	char	**prox_fidx;
}	t_anim;

typedef struct s_tex3d
{
	t_pair_int		bsize;
	t_canvas		wall[N_WALL];
	t_canvas		obj[N_OBJ][N_ANIM];
	t_canvas		door[N_DOOR][N_ANIM];
	t_canvas		display;
	t_rgb			ceil;
	t_rgb			floor;
	t_anim			anim;
}	t_tex3d;

// tex3d_add.c
void	free_tex3d(t_tex3d *tex3d, void *mlx);
// anim_add.c
void	add_anim(t_anim *anim, char **map);
void	free_anim(t_anim *anim);
// anim_update.c
void	update_anim(t_anim *anim, t_pair_dbl pos, char **map);

#endif

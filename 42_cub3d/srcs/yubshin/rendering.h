#ifndef RENDERING_H
# define RENDERING_H

#include "../../libft/base/pair.h"

typedef struct s_rnd
{
	t_pair_dbl	pos;
	t_pair_dbl	dir;
	t_pair_dbl	plane;
	t_pair_int	map;
	t_pair_int	step;

	double		camera_x;
	t_pair_dbl	raydir;
	t_pair_dbl	delta_dist;
	t_pair_dbl	side_dist;
	double		per_wall_dist;

	int			hit; // 벽에 부딪혔는지
	int			side; // 부딪힌 벽이 NS인지 EW인지
	
	int			line_height;

	t_pair_int	wh_pxl;

	long		cframetime;
	long		pframetime;

	int			draw_start;
	int			draw_end;

	int			textnum;
	double		wall_x;
	int			text_x;
	
}	t_rnd;

#endif

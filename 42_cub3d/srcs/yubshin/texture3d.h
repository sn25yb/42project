#ifndef TEXTURE3D_H
# define TEXTURE3D_H

//텍스처 개수
typedef enum e_texnum
{
	N_WALL = 4,
	N_OBJECT = 9,
	N_SPRITE = 4,
	N_DOOR = 2
}t_texnum;

//벽 인덱스
typedef enum e_wall_idx
{
	I_EAST = 0,
	I_WEST = 1,
	I_SOUTH = 2,
	I_NORTH = 3
}t_wall_idx;

//오브젝트 인덱스
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
}t_obj_idx;

//rgb값
typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
	int	flag;
}	t_rgb;

typedef struct s_canvas_3d
{
	void			*img;
	unsigned int	*addr;
}	t_canvas_3d;

typedef struct s_tex3d
{
	t_canvas_3d 	*wall;
	t_canvas_3d 	**object;
	t_canvas_3d 	*door;

	t_rgb			ceiling;
	t_rgb			floor;

	t_canvas_3d		display;

	t_pair_int		widtheight;
	int				bpp; //bits per pixel
	int				line; //size_line
	int 			endian;
}	t_tex3d;

#endif
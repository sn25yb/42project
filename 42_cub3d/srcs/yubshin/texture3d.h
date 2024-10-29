#ifndef TEXTURE3D_H
# define TEXTURE3D_H

#define OBJSPEED 0.5
#define DOORSPEED 0.1

//텍스처 개수
typedef enum e_texnum
{
	N_WALL = 4,
	N_OBJECT = 9,
	N_ANIMATION = 4,
	N_DOOR = 1
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
	int				bpp;     //bits per pixel
	int				size_l;  //size_line
	int 			endian;
	t_pair_int		size;
	int				animation;
	long			time;
}	t_canvas_3d;

typedef struct s_tex3d
{
	t_pair_int		widtheight;

	t_canvas_3d 	wall[N_WALL];
	t_canvas_3d 	object[N_OBJECT][N_ANIMATION];
	t_canvas_3d 	door[N_DOOR][N_ANIMATION];
	
	char			**doormap;
	long			time;
	int				openclose;

	t_canvas_3d		display;

	t_rgb			ceiling;
	t_rgb			floor;
	
}	t_tex3d;

#endif
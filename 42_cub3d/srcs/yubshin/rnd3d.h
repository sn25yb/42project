#ifndef RND3D_H
# define RND3D_H

# include "../../libft/base/pair.h"
# include "texture3d.h"
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
// # define SCREEN_WIDTH 1280
// # define SCREEN_HEIGHT 720
// # define SCREEN_WIDTH 640
// # define SCREEN_HEIGHT 480

typedef struct s_sprite
{
	t_pair_dbl		pos;
	double			dist;
	int				idx;
}	t_sprite; 

// 벽 렌더링 구조체
typedef struct s_wall
{
	t_pair_int		map;
	t_pair_int		step;        // 광선의 이동 방향 (단위 벡터)
	t_pair_dbl		raydir;      // 광선의 방향 벡터
	t_pair_dbl		deltadist;   // 광선이 각 축을 통과하는 거리
	t_pair_dbl		sidedist;    // 광선이 처음 각 축에 닿는 위치까지의 거리
	double			perpwalldist;// 플레이어와 벽까지의 수직 거리
	int				hit;
	int				side;        // 충돌한 벽의 방향 (NS or EW)
	int				lineheight;  // 그릴 벽의 높이
	int				drawstart;   
	int				drawend;     
	double			wall_x;      // 벽에 충돌한 정확한 X 좌표
	unsigned int	*texture;    // 벽 텍스처 데이터
}	t_wall;

// 오브젝트 렌더링 구조체
typedef struct s_object
{
	double			z_buffer[SCREEN_WIDTH]; // 각 x 좌표의 거리 버퍼
	t_sprite		sprites[N_OBJECT]; // 렌더링할 스프라이트 리스트

	t_pair_dbl		transform;  // 변환된 스프라이트의 화면상 좌표
	int				spritescreenx; // 스프라이트가 화면의 X 좌표에서 위치할 픽셀
	int				spriteheight;
	int				spritewidth;
	t_pair_int		drawstart;
	t_pair_int		drawend;

} t_object;

// 렌더링 정보 (카메라 및 플레이어 상태) 구조체
typedef struct s_view
{
	t_pair_dbl	pos;
	t_pair_dbl	dir;
	t_pair_dbl	plane; //카메라 평면 벡터
} 	t_view;

typedef struct s_rnd3d
{
	t_view		view;
	t_wall		wall;
	t_object	object;
	t_tex3d		tex3d;
	char		*texfile[N_WALL]; //map texture path
}	t_rnd3d;



#endif

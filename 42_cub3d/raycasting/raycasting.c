#include "../cub3d.h"

#define mapWidth 24
#define mapHeight 24
#define PIXEL 32

char worldMap[mapWidth][mapHeight]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

typedef struct s_coord_int
{
	int	y;
	int	x;
}	t_coord_int;

// typedef struct s_rendering
// {
// 	t_coord pos;
// 	t_coord dir;
// 	t_coord plane;
// 	t_coord raydir;
// 	t_coord side_dist;
// 	t_coord delta_dist;


// 	double	camera_x;
// 	double	per_wall_dist;

// 	t_coord_int map;
// 	t_coord_int step;

// 	int	side;
// 	int	line_height;
// 	int	pitch;

// 	long cframetime;
// 	long pframetime;
// }	t_rendering;


// int	init_rendering(t_rendering *rendering, t_game *game)
// {
// 	rendering->pos.x = game->player.pos.x;
// 	rendering->pos.y = game->player.pos.y;
// 	rendering->dir.x = game->player.dir.x;
// 	rendering->dir.y = game->player.dir.y;
// 	rendering->plane.x = 0;
// 	rendering->plane.y = 0.66;
// 	rendering->raydir.x = 

// }


/*
1. DDA
2. 어안렌즈효과 보정
3. 벽 그리기 
*/


unsigned int drawimg(t_game *game, int x, int y)
{
	int bits_per_pixel = 1; // 픽셀의 색상을 표현하는데 필요한 비트의 수(= 색의 깊이)
	int size_line = 1; //메모리 안에서 이미지 한 줄을 저장하는데 필요한 바이트의 수(이미지의 한 줄에서 다른 줄로 이동하는데 사용)
	int endian = 1; // 이미지의 픽셀 색상을 little (endian == 0) 또는 big (endian == 1)에 저장해야하는지 여부를 의미

	unsigned int *addr = (unsigned int *)mlx_get_data_addr(game->image.wall[0], &bits_per_pixel, &size_line, endian);
	unsigned int *point = (unsigned int *)((char *)addr + size_line * y + bits_per_pixel / 8 * x); 
	

	// int     mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
	mlx_pixel_put(game->mlx, game->win, x, y, (int)*point);
}




int raycasting(t_game *game)
{
	double posX = 22, posY = 12;
	double dirX = -1, dirY = 0;
	double planeX = 0, planeY = 0.66;

	long	cframetime = 0, pframetime = 0;

	while (1)
	{
		int x = 0;
		int wpxl = mapWidth * PIXEL;
		while (x < wpxl) // x픽셀 0에서 wpxl까지
		{
			// 레이의 위치와 방향 계산
			double cameraX = 2 * x / (double)wpxl - 1; //카메라 공간의 좌표 : -1 에서 1 사이의 실수값을 가진다. 
			double raydirX = dirX + planeX * cameraX; // 레이의 x방향 
			double raydirY = dirY + planeY * cameraX; //레이의 y방향 

			// 현재 위치의 맵 박스
			int mapX = (int)posX;
			int mapY = (int)posY;

			// x 또는 y 사이드에서 다음 사이드까지의 레이 길이
			double deltaDistX;
			double deltaDistY;
			deltaDistX = sqrt(1 + (raydirY * raydirY) / (raydirX * raydirX));
			deltaDistY = sqrt(1 + (raydirX * raydirX) / (raydirY * raydirY));

			// 현재 위치에서 다음 x 또는 y 사이드까지의 레이 길이
			double sideDistX;
			double sideDistY;
			// 이동방향 (1, -1)
			int	stepX, stepY;
			if(raydirX < 0)
			{
				stepX = -1; //왼쪽 이동
				sideDistX = (posX - mapX) * deltaDistX; // 현재 위치에서 다음 x 사이드까지의 레이 길이
			}
			else
			{
				stepX = 1; //오른쪽 이동
				sideDistX = (mapX + 1.0 - posX) * deltaDistX; // 현재 위치에서 다음 x 사이드까지의 레이 길이
			}
			if(raydirY < 0)
			{
				stepY = -1; //아래로 이동
				sideDistY = (posY - mapY) * deltaDistY; // 현재 위치에서 다음 y 사이드까지의 레이 길이
			}
			else
			{
				stepY = 1; //위로 이동
				sideDistY = (mapY + 1.0 - posY) * deltaDistY; // 현재 위치에서 다음 y 사이드까지의 레이 길이
			}

			/* DDA */
			// 벽에 부딪혔는지
			int	hit = 0;
			// 부딪힌 벽이 NS인지 EW인지
			int	side;
			while (hit == 0)
			{
				// x 방향 또는 y 방향으로 다음 맵 사각형으로 점프?
				if (sideDistX < sideDistY)
				{
					sideDistX += deltaDistX; // x방향 거리 증가
					mapX += stepX; // 맵의 x좌표 이동 
					side = 0; // ns 벽을 hit 
				}
				else //sideDistX >= sideDistY
				{
					sideDistY += deltaDistY; // y방향 거리 증가
					mapY += stepY; // 맵의 y좌표 이동 
					side = 1; //ew 벽을 hit 
				}
				// 레이가 벽에 부딪혔는지 확인
				if (worldMap[mapX][mapY] == 1) // 벽이 있으면 hit
					hit = 1;
			}

			// 수직 레이의 거리 계산 (유클리드 거리는 물고기눈 효과를 줄 수 있음)
			double	perpWallDist;
			if (side == 0) 
				perpWallDist = (sideDistX - deltaDistX);
			else
				perpWallDist = (sideDistY - deltaDistY);

			// 화면에 그릴 선의 높이 계산
			int	lineHeight = (int) (mapHeight / perpWallDist); //화면 높이 비율

			//그리기 오프셋
			int pitch = 100;

			// 
			


			x++;
		}
	}

}
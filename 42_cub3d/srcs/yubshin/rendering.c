#include "../../cub3d.h"

void	init_rnd(t_game *game)
{
	game->rnd.cal.pos.x = game->player.pos.x;
	game->rnd.cal.pos.y = game->player.pos.y;
	game->rnd.cal.dir.x = game->player.dir.x;
	game->rnd.cal.dir.y = game->player.dir.y;
	game->rnd.cal.plane.x = 0;
	game->rnd.cal.plane.y = 0.8;
}

void cal_loop(t_game *game, t_rnd *rnd)
{
	int x;

	x = 0;

	while (x < SCREEN_WIDTH)
	{
		double camera_x = (2 * x / (double)SCREEN_WIDTH - 1);
		t_pair_dbl raydir;
		raydir.x = rnd->cal.dir.x + rnd->cal.plane.x * camera_x;
		raydir.y = rnd->cal.dir.y + rnd->cal.plane.y * camera_x;
		
		t_pair_int map;
		map.x= (int)(rnd->cal.pos.x);
		map.y= (int)(rnd->cal.pos.y);

		t_pair_dbl sidedist;
		t_pair_dbl deltadist;
		deltadist.x = fabs(1 / raydir.x);
		deltadist.y = fabs(1 / raydir.y);
	// rnd->cal.delta_dist.x = sqrt(1 + (rnd->cal.raydir.y * rnd->cal.raydir.y) / (rnd->cal.raydir.x * rnd->cal.raydir.x));
	// rnd->cal.delta_dist.y = sqrt(1 + (rnd->cal.raydir.x * rnd->cal.raydir.x) / (rnd->cal.raydir.y * rnd->cal.raydir.y));
		double perpwalldist;

		t_pair_int step;
		int side;

		if (raydir.x < 0)
		{
			sidedist.x = (rnd->cal.pos.x - map.x) * deltadist.x;
			step.x = -1;
		}
		else
		{
			step.x = 1;
			sidedist.x = (rnd->cal.map.x + 1.0 - rnd->cal.pos.x) * deltadist.x;
		}
		if (raydir.y < 0)
		{
			step.y = -1;
			sidedist.y = (rnd->cal.pos.y - map.y) * deltadist.y;
		}
		else
		{
			step.y = 1;
			sidedist.y = (rnd->cal.map.y + 1.0 - rnd->cal.pos.y) * deltadist.y;
		}
		int hit = 0;

		while (1)
		{
			if (sidedist.x < sidedist.y)
			{
				sidedist.x += deltadist.x;
				map.x += step.x;
				if (map.x < 0)
					map.x = 0;
				side = 0;
			}
			else
			{
				sidedist.y += deltadist.y;
				map.y += step.y;
				if (map.y < 0)
					map.y = 0;
				side = 1;
			}
			// if (game->map[map.y][map.x] && game->map[map.y][map.x] != '0')
	// printf("%f,%f\n", rnd->cal.pos.y, rnd->cal.pos.x);
	// printf("%d,%d\n", map.y, map.x);
			if (game->map[map.y][map.x] == '1')
			{
				hit = 1;
				break ; 
			}

		}

		if (side == 0)
			perpwalldist = (map.x - rnd->cal.pos.x + (1 - step.x) / 2) / raydir.x;
		else 
			perpwalldist = (map.y - rnd->cal.pos.y + (1 - step.y) / 2) / raydir.y;
		int lineheight = (int)(SCREEN_HEIGHT / perpwalldist);

		int drawstart = (- lineheight / 2) + (SCREEN_HEIGHT / 2);
		if (drawstart < 0)
			drawstart = 0;
		int drawend = (lineheight / 2) + (SCREEN_HEIGHT / 2);
		if (drawend >= SCREEN_HEIGHT)
			drawend = SCREEN_HEIGHT - 1;
		printf("drawend: %d\n", drawend);
		char texnum = game->map[map.y][map.x];
		unsigned int *texture;

		if (texnum == '1')
		{
			if (side == 1)
			{
				if (step.x < 0)
					texture = rnd->tex3d.wall[2].addr; //동
				else 
					texture = rnd->tex3d.wall[0].addr; //북
			}
			else if (side == 0)
			{
				if (step.y < 0)
					texture = rnd->tex3d.wall[3].addr; //서
				else 
					texture = rnd->tex3d.wall[1].addr; //남
			}
		}
		// else if (texnum == 'e')
		// 	texture = game->texture.door[1];
		// else if (texnum == 'd')
		// 	texture = game->texture.door[0];
		// else if (texnum == 'A')
		// 	texture = game->texture.character[0];

		
		double wallx;
		if (side == 0)
			wallx = rnd->cal.pos.y + perpwalldist * raydir.y;
		else 
			wallx = rnd->cal.pos.x + perpwalldist * raydir.x;
		wallx -= floor(wallx);

		int texwidth = 32;
		int texheight = 32;
		t_pair_int tex;

		tex.x = (int)(wallx * (double)texwidth);
		tex.x = tex.x % texwidth;
		// tex.x = (tex.x + texwidth) % texwidth;  // tex.x를 texwidth로 나눈 나머지로 제한
		if ((side == 0 && raydir.x > 0) || (side == 1 && raydir.y < 0))
			tex.x = texwidth - tex.x - 1;

		double step2 = 1.0 * texheight / lineheight;

		double texpos = (drawstart - SCREEN_HEIGHT / 2 + lineheight / 2 ) * step2;
	
		int y = drawstart;
		while (y < drawend)
		{
			tex.y = (int)texpos & (texheight - 1);
			tex.y = tex.y % texheight;
			texpos += step2;
			int color = texture[texheight * tex.y + tex.x];
			// if (side == 1)
			// 	color = (color >> 1) & 835571;
			rnd->tex3d.display.addr[y * SCREEN_WIDTH + x]  = color;
			y++;
		}
		x++;

	}

}

int rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	draw_floor(t_rnd *rnd, t_game *game)
{
	int y;

	y = 0; // y 좌표 초기화
	while (y < SCREEN_HEIGHT) // 화면 높이만큼 반복
	{
		// 바닥과 천장의 시작 방향 벡터 계산
		float raydirx0 = rnd->cal.dir.x - rnd->cal.plane.x;
		float raydiry0 = rnd->cal.dir.y - rnd->cal.plane.y;
		float raydirx1 = rnd->cal.dir.x + rnd->cal.plane.x;
		float raydiry1 = rnd->cal.dir.y + rnd->cal.plane.y;

		int p = y - SCREEN_HEIGHT / 2; // y 중심점으로부터의 거리
		float posz = 0.2 * SCREEN_HEIGHT; // 카메라 높이 (0.5)
		float rowdist = posz / p; // 각 행의 거리 계산

		// 바닥 텍스처의 스텝 계산
		float floorstepx = rowdist * (raydirx1 - raydirx0) / SCREEN_WIDTH;
		float floorstepy = rowdist * (raydiry1 - raydiry0) / SCREEN_WIDTH;

		// 현재 픽셀에 대한 바닥 좌표 초기화
		float floorx = rnd->cal.pos.x + rowdist * raydirx0;
		float floory = rnd->cal.pos.y + rowdist * raydiry0;
		
		int x; 
		int texwidth = 32; // 텍스처의 너비
		int texheight = 32; // 텍스처의 높이

		x = 0;
		while (x < SCREEN_WIDTH) // 화면 너비만큼 반복
		{
			// 현재 셀의 좌표 계산
			int cellx = (int)(floorx);
			int celly = (int)(floory);

			// 텍스처 좌표 계산
			int tx = (int)(texwidth * (floorx - cellx)) & (texwidth - 1);
			int ty = (int)(texheight * (floory - celly)) & (texheight - 1);

			// 다음 픽셀의 바닥 좌표로 이동
			floorx += floorstepx;
			floory += floorstepy;

			// 바닥 텍스처에서 색상 가져오기
			int color = rgb_to_int(rnd->tex3d.floor.rgb.r, rnd->tex3d.floor.rgb.g, rnd->tex3d.floor.rgb.b);
			rnd->tex3d.display.addr[y * SCREEN_WIDTH + x] = color; // 현재 y좌표의 바닥 픽셀에 색상 저장

			// 천장 텍스처에서 색상 가져오기
			color = rgb_to_int(rnd->tex3d.ceiling.rgb.r, rnd->tex3d.ceiling.rgb.g, rnd->tex3d.ceiling.rgb.b);
			rnd->tex3d.display.addr[(SCREEN_HEIGHT - y - 1) * SCREEN_WIDTH + x] = color; // 반대 y좌표의 천장 픽셀에 색상 저장
			x++; // 다음 x좌표로 이동
		}
		y++; // 다음 y좌표로 이동
	}
}

// void	rendering_main(t_game *game)
void	draw_3dmap(t_game *game)
{
	init_rnd(game);
	draw_floor(&game->rnd, game);
	cal_loop(game, &game->rnd);
	// draw_loop(&game->rnd);
	mlx_put_image_to_window(game->mlx, game->win, game->rnd.tex3d.display.img, 0, 0);
	// printf("here4\n");

}
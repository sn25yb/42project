#include "../../cub3d.h"

void	cal_raydir_pair(t_view view, t_wall *wall, int x)
{
	double	camera_x;

	camera_x = (2 * x / (double)SCREEN_WIDTH - 1);
	wall->raydir.x = view.dir.x + view.plane.x * camera_x;
	wall->raydir.y = view.dir.y + view.plane.y * camera_x;	
}

void	cal_map_pair(t_view view, t_wall *wall)
{
	wall->map.x = (int)(view.pos.x);
	wall->map.y = (int)(view.pos.y);
}

void	cal_deltadist_pair(t_wall *wall)
{
	// wall->deltadist.x = fabs(1 / wall->raydir.x);
	// wall->deltadist.y = fabs(1 / wall->raydir.y);
	wall->deltadist.x = sqrt(1 + (wall->raydir.y * wall->raydir.y) / (wall->raydir.x * wall->raydir.x));
	wall->deltadist.y = sqrt(1 + (wall->raydir.x * wall->raydir.x) / (wall->raydir.y * wall->raydir.y));
}

void cal_sidedist_pair(t_view view, t_wall *wall)
{
	if (wall->raydir.x >= 0)
		wall->sidedist.x = (wall->map.x + 1.0 - view.pos.x) * wall->deltadist.x;
	else 
		wall->sidedist.x = (view.pos.x - wall->map.x) * wall->deltadist.x;
	if (wall->raydir.y >= 0)
		wall->sidedist.y = (wall->map.y + 1.0 - view.pos.y) * wall->deltadist.y;
	else
		wall->sidedist.y = (view.pos.y - wall->map.y) * wall->deltadist.y;
}

void cal_step_pair(t_wall *wall)
{
	if (wall->raydir.x >= 0)
		wall->step.x = 1;
	else 
		wall->step.x = -1;
	if (wall->raydir.y >= 0)
		wall->step.y = 1;
	else
		wall->step.y = -1;
}

int	is3dwall(char mapcode)
{
	if (mapcode && (mapcode == '1' || mapcode == 'd' || mapcode == 'e'))
		return (TRUE);
	return (FALSE);
}

void dda(t_wall *wall, char **map)
{
	int hit = 0;

	while (hit == 0)
	{
		if (wall->sidedist.x <= wall->sidedist.y)
		{
			wall->sidedist.x += wall->deltadist.x;
			wall->map.x += wall->step.x;
			wall->side = 0; //동서 벽
			if (wall->map.x < 0 || !map[wall->map.y][wall->map.x])
				hit = 1;
		}
		else
		{
			wall->sidedist.y += wall->deltadist.y;
			wall->map.y += wall->step.y;
			wall->side = 1; //북남 벽
			if (wall->map.y < 0 || !map[wall->map.y][wall->map.x])
				hit = 1;
		}
		if (is3dwall(map[wall->map.y][wall->map.x]))
			hit = 1;
	}
}

void	cal_perpwalldist(t_view view, t_wall *wall)
{
	if (wall->side == 0)
		wall->perpwalldist = (wall->map.x - view.pos.x + (1 - wall->step.x) / 2) / wall->raydir.x;
	else 
		wall->perpwalldist = (wall->map.y - view.pos.y + (1 - wall->step.y) / 2) / wall->raydir.y;
}

void	cal_lineheight(t_wall *wall)
{
	wall->lineheight = (int)(SCREEN_HEIGHT / wall->perpwalldist);
}

void	cal_drawstartend(t_wall *wall)
{
	wall->drawstart = (-wall->lineheight / 2) + (SCREEN_HEIGHT / 2);
	if (wall->drawstart < 0)
		wall->drawstart = 0;
	wall->drawend = (wall->lineheight / 2) + (SCREEN_HEIGHT / 2);
	if (wall->drawend >= SCREEN_HEIGHT)
		wall->drawend = SCREEN_HEIGHT - 1;
}

void	set_texture(t_wall *wall, t_tex3d tex3d, char **map)
{
	char texnum;
	
	texnum = map[wall->map.y][wall->map.x];
	if (texnum == '1')
	{
		if (wall->side == 0)
		{
			if (wall->raydir.x < 0)
				wall->texture = tex3d.wall[I_WEST].addr; //서 
			else if (wall->raydir.x >= 0) 
				wall->texture = tex3d.wall[I_EAST].addr; //동
		}
		else
		{
			if (wall->raydir.y < 0)
				wall->texture = tex3d.wall[I_NORTH].addr; //북
			else if (wall->raydir.y >= 0)
				wall->texture = tex3d.wall[I_SOUTH].addr; //남
		}
	}
	else if (texnum == 'e')
		wall->texture = tex3d.door[1].addr;
	else if (texnum == 'd')
		wall->texture = tex3d.door[0].addr;
}

void cal_wall_x(t_view view, t_wall *wall)
{
	if (wall->side == 0)
		wall->wall_x = view.pos.y + wall->perpwalldist * wall->raydir.y;
	else 
		wall->wall_x = view.pos.x + wall->perpwalldist * wall->raydir.x;
	wall->wall_x -= floor(wall->wall_x);
}

void	draw_pixeline_wall(t_wall wall, t_tex3d *tex3d, int x)
{
	t_pair_int	tex;
	double		texpos;
	double		onestep;
	int			y;
	int			pixel;

	tex.x = (int)((tex3d->widtheight.x - wall.wall_x) * (double)tex3d->widtheight.x);
	tex.x = tex.x % tex3d->widtheight.x; // tex.x를 texwidth로 나눈 나머지로 제한
	if ((wall.side == 0 && wall.raydir.x > 0) || (wall.side == 1 && wall.raydir.y < 0))
		tex.x = tex3d->widtheight.x - tex.x - 1;
	onestep = 1.0 * tex3d->widtheight.y / wall.lineheight;
	texpos = (wall.drawstart - SCREEN_HEIGHT / 2 + wall.lineheight / 2 ) * onestep;
	y = wall.drawstart;
	while (y < wall.drawend && wall.texture)
	{
		tex.y = (int)texpos & (tex3d->widtheight.y - 1);
		tex.y = tex.y % tex3d->widtheight.y;
		texpos += onestep;
		pixel = wall.texture[tex3d->widtheight.y * tex.y + tex.x];
		// if (wall.side == 1)
		// 	pixel = (pixel >> 1) & 835571;
		tex3d->display.addr[y * SCREEN_WIDTH + x] = pixel;
		y++;
	}
}

void render_wall(t_rnd *rnd, char **map)
{
	int x;

	x = 0;

	while (x < SCREEN_WIDTH)
	{
		cal_raydir_pair(rnd->view, &rnd->wall, x);
		cal_map_pair(rnd->view, &rnd->wall);
		cal_deltadist_pair(&rnd->wall);
		cal_sidedist_pair(rnd->view, &rnd->wall);
		cal_step_pair(&rnd->wall);
		dda(&rnd->wall, map);
		cal_perpwalldist(rnd->view, &rnd->wall);
		rnd->object.z_buffer[x] = rnd->wall.perpwalldist;
		cal_lineheight(&rnd->wall);
		cal_drawstartend(&rnd->wall);
		set_texture(&rnd->wall, rnd->tex3d, map);
		cal_wall_x(rnd->view, &rnd->wall);
		draw_pixeline_wall(rnd->wall, &rnd->tex3d, x);
		x++;
	}
}

int rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	render_ceilfloor(t_rnd *rnd)
{
	int y;

	y = 0; // y 좌표 초기화
	while (y < SCREEN_HEIGHT) // 화면 높이만큼 반복
	{
		// 바닥과 천장의 시작 방향 벡터 계산
		float raydirx0 = rnd->view.dir.x - rnd->view.plane.x;
		float raydiry0 = rnd->view.dir.y - rnd->view.plane.y;
		float raydirx1 = rnd->view.dir.x + rnd->view.plane.x;
		float raydiry1 = rnd->view.dir.y + rnd->view.plane.y;

		int p = y - SCREEN_HEIGHT / 2; // y 중심점으로부터의 거리
		float posz = 0.2 * SCREEN_HEIGHT; // 카메라 높이 (0.5)
		float rowdist = posz / p; // 각 행의 거리 계산

		// 바닥 텍스처의 스텝 계산
		float floorstepx = rowdist * (raydirx1 - raydirx0) / SCREEN_WIDTH;
		float floorstepy = rowdist * (raydiry1 - raydiry0) / SCREEN_WIDTH;

		// 현재 픽셀에 대한 바닥 좌표 초기화
		float floorx = rnd->view.pos.x + rowdist * raydirx0;
		float floory = rnd->view.pos.y + rowdist * raydiry0;
		
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
			int color = rgb_to_int(rnd->tex3d.floor.r, rnd->tex3d.floor.g, rnd->tex3d.floor.b);
			rnd->tex3d.display.addr[y * SCREEN_WIDTH + x] = color; // 현재 y좌표의 바닥 픽셀에 색상 저장

			// 천장 텍스처에서 색상 가져오기
			color = rgb_to_int(rnd->tex3d.ceiling.r, rnd->tex3d.ceiling.g, rnd->tex3d.ceiling.b);
			rnd->tex3d.display.addr[(SCREEN_HEIGHT - y - 1) * SCREEN_WIDTH + x] = color; // 반대 y좌표의 천장 픽셀에 색상 저장
			x++; // 다음 x좌표로 이동
		}
		y++; // 다음 y좌표로 이동
	}
}

int mapcode_to_idx(char mapcode)
{
	char	mapcodes[N_OBJECT] = {'A','L','F','R','H','b','c','k','w'};
	int		idx;

	idx = 0;
	while (mapcodes[idx])
	{
		if (mapcodes[idx] == mapcode)
			return (idx);
		idx++;
	}
	return (-1);
}

void	save_sprites_pos(char **map, t_object *object)
{
	t_pair_int	midx; 
	int			sidx;

	midx.y = 0;
	while (map[midx.y])
	{
		midx.x = 0;
		while (map[midx.y][midx.x])
		{
			sidx = mapcode_to_idx(map[midx.y][midx.x]);
			if (sidx >= 0)
			{
				object->sprites[sidx].pos.x = midx.x;
				object->sprites[sidx].pos.y = midx.y;
				object->sprites[sidx].dist = 0;
				object->sprites[sidx].idx = sidx;
			}
			midx.x++;
		}
		midx.y++;
	}
}

void cal_sprite_distance(t_view view, t_object *object)
{
	int			idx;
	t_pair_dbl	dist;
		
	idx = 0;
	while (idx < N_OBJECT)
	{
		dist.x = object->sprites[idx].pos.x - view.pos.x;
		dist.y = object->sprites[idx].pos.y - view.pos.y;
		object->sprites[idx].dist = sqrt(dist.x * dist.x + dist.y * dist.y);
		// printf("Sprite %d distance: %f\n", idx, object->sprites[idx].dist);
		idx++;
	}
}


void sort_sprites(t_object *object)
{
	int i;
	int j;
	t_sprite tmp;

	i = 0;
	while (i < N_OBJECT - 1)
	{
		j = 0;
		while (j < N_OBJECT - i - 1)
		{
			if (object->sprites[j].dist < object->sprites[j + 1].dist)
			{
				tmp = object->sprites[j];
				object->sprites[j] = object->sprites[j + 1];
				object->sprites[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}


t_pair_dbl	sprite_to_view(t_sprite sprite, t_view view)
{
	t_pair_dbl	transform; // 변환된 스프라이트의 화면상 좌표
	t_pair_dbl	sprite_rel_pos; // 스프라이트의 위치를 나타내는 변수
	double		invdet;	// 역행렬 값 저장을 위한 변수

	// 스프라이트의 월드 좌표 계산
	sprite_rel_pos.x = sprite.pos.x - view.pos.x + 0.5; // 스프라이트의 X 좌표에서 플레이어의 X 좌표를 뺀 뒤 0.5를 더함
	sprite_rel_pos.y = sprite.pos.y - view.pos.y + 0.5; // 스프라이트의 Y 좌표에서 플레이어의 Y 좌표를 뺀 뒤 0.5를 더함
	// 이 위치 값은 플레이어를 기준으로 한 상대적인 스프라이트의 위치입니다.

	// 변환 행렬의 역행렬 계산
	// invdet은 3D 좌표계에서 2D 스크린 좌표로 변환하기 위한 값입니다.
	// 플레이어의 평면(plane) 벡터와 방향(dir) 벡터를 사용하여 역행렬을 구합니다.
	invdet = 1.0 / (view.plane.x * view.dir.y - view.dir.x * view.plane.y);

	// 스프라이트의 화면상 X 좌표 변환
	transform.x = invdet * (view.dir.y * sprite_rel_pos.x - view.dir.x * sprite_rel_pos.y);
	// transform->x는 변환된 스프라이트의 화면상 X 좌표이며, 이 좌표는 플레이어의 방향 벡터에 영향을 받습니다.

	// 스프라이트의 화면상 Y 좌표 변환 (깊이 정보 포함)
	transform.y = invdet * (-view.plane.y * sprite_rel_pos.x + view.plane.x * sprite_rel_pos.y);
	// transform->y는 변환된 스프라이트의 Y 좌표를 의미하며, 깊이 정보가 포함되어 있어 Z-Buffer에서의 깊이 확인에 사용됩니다.
	// 이 변환은 스프라이트가 플레이어 시야에 대해 어느 위치에 있는지 판단할 수 있게 합니다.
	return (transform);
}

void	cal_sprite_screen_params(t_sprite sprite, t_view view, t_object *object)
{
	// 스프라이트의 변환 및 위치 계산
	object->transform = sprite_to_view(sprite, view);
	// 스프라이트가 화면의 X 좌표에서 위치할 픽셀 계산
	object->spritescreenx = (int)((SCREEN_WIDTH / 2) * (1 + object->transform.x / object->transform.y));
	// 스프라이트의 화면상 높이 및 너비 계산
	object->spriteheight = abs((int)(SCREEN_HEIGHT / object->transform.y)); // 스프라이트 높이, Y 좌표 기준으로 스케일링
	object->spritewidth = abs((int)(SCREEN_HEIGHT / object->transform.y)); // 스프라이트 너비, Y 좌표 기준으로 스케일링
}

void	cal_sprite_draw_bounds(t_object *object)
{
	object->drawstart.y = -object->spriteheight / 2 + SCREEN_HEIGHT / 2; // 시작 Y 좌표
	object->drawend.y = object->spriteheight / 2 + SCREEN_HEIGHT / 2; // 끝 Y 좌표
	if (object->drawstart.y < 0)
		object->drawstart.y = 0; // 화면 경계를 벗어나지 않도록 최소값 설정
	if (object->drawend.y >= SCREEN_HEIGHT)
		object->drawend.y = SCREEN_HEIGHT - 1; // 화면 경계를 벗어나지 않도록 최대값 설정
	// 스프라이트의 X 좌표에서 시작과 끝 설정
	object->drawstart.x = -object->spritewidth / 2 + object->spritescreenx; // 시작 X 좌표
	object->drawend.x = object->spritewidth / 2 + object->spritescreenx; // 끝 X 좌표
	if (object->drawstart.x < 0)
		object->drawstart.x = 0; // 화면 경계를 벗어나지 않도록 최소값 설정
	if (object->drawend.x >= SCREEN_WIDTH)
		object->drawend.x = SCREEN_WIDTH - 1; // 화면 경계를 벗어나지 않도록 최대값 설정
}

void draw_pixeline_object(t_object object, t_tex3d *tex3d, t_sprite sprite)
{
	t_pair_int	tex;
	t_pair_int	draw; // 스프라이트의 X, Y 좌표
	int			d; // 픽셀 위치 계산을 위한 변수
	int			color; // 텍스처 색상 값

	draw.x = object.drawstart.x; // 스프라이트의 시작 X 좌표로 draw.x 초기화
	// 스프라이트의 각 열에 대해
	while (draw.x < object.drawend.x) // 스프라이트의 끝 X 좌표까지 반복
	{
		// 텍스처의 X 좌표 계산
		tex.x = (int)(256 * (draw.x - (-object.spritewidth / 2 + object.spritescreenx)) * tex3d->widtheight.x / object.spritewidth) / 256;
		// 스프라이트의 깊이 체크 및 화면에 그리기
		if (object.transform.y > 0 && draw.x > 0 && draw.x < SCREEN_WIDTH && object.transform.y < object.z_buffer[draw.x])
		{
			draw.y = object.drawstart.y; // 스프라이트의 시작 Y 좌표를 초기화
			// 스프라이트의 각 행에 대해
			while (draw.y < object.drawend.y) // 스프라이트의 끝 Y 좌표까지 반복
			{
				// 텍스처 Y 좌표 계산
				d = draw.y * 256 - SCREEN_HEIGHT * 128 + object.spriteheight * 128; // 픽셀 위치
				tex.y = ((d * tex3d->widtheight.y) / object.spriteheight) / 256; // 텍스처의 Y 좌표 계산
				// 텍스처 픽셀 색상 가져오기
				color = tex3d->object[sprite.idx][0].addr[tex3d->widtheight.y * tex.y + tex.x]; // 텍스처로부터 색상 값 가져오기
				// if ((color & 0x00FFFFFF) != 0) // 투명도 처리
				tex3d->display.addr[draw.y * SCREEN_WIDTH + draw.x] = color; // 최종 픽셀 값 설정
				draw.y++; // 다음 Y 좌표로 이동
			}
		}
		draw.x++; // 다음 X 좌표로 이동
	}
}


void render_object(t_rnd *rnd, char **map)
{
	int idx;

	idx = 0;
	save_sprites_pos(map, &rnd->object);
	// 1. 플레이어와 스프라이트의 거리 계산
	cal_sprite_distance(rnd->view, &rnd->object);
	// 2. 거리 기준으로 스프라이트 정렬
	sort_sprites(&rnd->object);
	while (idx < N_OBJECT)
	{
		cal_sprite_screen_params(rnd->object.sprites[idx], rnd->view, &rnd->object);
		// 스프라이트가 화면에 그려질 시작 및 끝 Y 좌표 계산
		cal_sprite_draw_bounds(&rnd->object);
		// Z_BUFFER를 이용한 깊이 체크 및 스프라이트 그리기
		draw_pixeline_object(rnd->object, &rnd->tex3d, rnd->object.sprites[idx]);
		idx++;
	}
}

void draw_3dmap(t_game *game)
{
	init_render(&game->rnd, game->player);
	render_ceilfloor(&game->rnd);
	render_wall(&game->rnd, game->map);
	render_object(&game->rnd, game->map);
	mlx_put_image_to_window(game->mlx, game->win, game->rnd.tex3d.display.img, 0, 0);
}

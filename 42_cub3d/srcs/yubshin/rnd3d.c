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
	// printf("(%f, %f) -> (%d, %d)\n", view.pos.y, view.pos.x, wall->map.y, wall->map.x);
}

void	cal_deltadist_pair(t_wall *wall)
{
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
	{
		wall->texture = tex3d.door[0][(int)tex3d.doormap[wall->map.y][wall->map.x]].addr;
		// printf("(%d, %d) %d\n", wall->map.y, wall->map.x, tex3d.doormap[wall->map.y][wall->map.x]);
	}
	else if (texnum == 'd')
	{
		wall->texture = tex3d.door[0][(int)tex3d.doormap[wall->map.y][wall->map.x]].addr;
	}
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
	tex.x = tex.x % tex3d->widtheight.x;
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

void render_wall(t_rnd3d*rnd, char **map)
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

void	render_ceilfloor(t_rnd3d*rnd)
{
	int y;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		// 바닥과 천장의 시작 방향 벡터 계산
		t_pair_dbl	raydir0;
		t_pair_dbl	raydir1;

		raydir0.x = rnd->view.dir.x - rnd->view.plane.x;
		raydir0.y = rnd->view.dir.y - rnd->view.plane.y;
		raydir1.x = rnd->view.dir.x + rnd->view.plane.x;
		raydir1.y = rnd->view.dir.y + rnd->view.plane.y;

		int p = y - SCREEN_HEIGHT / 2; // y 중심점으로부터의 거리
		double posz = 0.2 * SCREEN_HEIGHT; // 카메라 높이 (0.5)
		double rowdist = posz / p; // 각 행의 거리 계산

		t_pair_dbl floorstep;
		t_pair_dbl floor;

		// 바닥 텍스처의 스텝 계산
		floorstep.x = rowdist * (raydir1.x - raydir0.x) / SCREEN_WIDTH;
		floorstep.y = rowdist * (raydir1.y - raydir0.y) / SCREEN_WIDTH;
		// 현재 픽셀에 대한 바닥 좌표 초기화
		floor.x = rnd->view.pos.x + rowdist * raydir0.x;
		floor.y = rnd->view.pos.y + rowdist * raydir0.y;
		
		int color;
		int x;
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			// 다음 픽셀의 바닥 좌표로 이동
			floor.x += floorstep.x;
			floor.y += floorstep.y;
			// 바닥 텍스처에서 색상 가져오기
			color = rgb_to_int(rnd->tex3d.floor.r, rnd->tex3d.floor.g, rnd->tex3d.floor.b);
			// y좌표의 바닥 픽셀에 색상 저장
			rnd->tex3d.display.addr[y * SCREEN_WIDTH + x] = color;
			// 천장 텍스처에서 색상 가져오기
			color = rgb_to_int(rnd->tex3d.ceiling.r, rnd->tex3d.ceiling.g, rnd->tex3d.ceiling.b);
			// y좌표의 천장 픽셀에 색상 저장
			rnd->tex3d.display.addr[(SCREEN_HEIGHT - y - 1) * SCREEN_WIDTH + x] = color;
			x++;
		}
		y++;
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

void	init_sprite_pos(t_object *object)
{
	int idx;

	idx = 0;
	while (idx < N_OBJECT)
	{
		object->sprites[idx].pos.x = 0;
		object->sprites[idx].pos.y = 0;
		object->sprites[idx].dist = 0;
		object->sprites[idx].idx = 0;
		idx++;
	}
}

void	save_sprite_pos(char **map, t_object *object)
{
	t_pair_int	midx; 
	int			sidx;

	init_sprite_pos(object);
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
	t_pair_dbl	transform; // 스프라이트의 화면상 좌표
	t_pair_dbl	sprite_rel_pos; // 스프라이트의 상대 좌표 (플레이어를 기준으로 한 상대적인 스프라이트의 위치)
	double		invdet;	// 역행렬 값

	// 스프라이트의 상대 좌표 계산
	sprite_rel_pos.x = sprite.pos.x - view.pos.x + 0.5;
	sprite_rel_pos.y = sprite.pos.y - view.pos.y + 0.5;
	// invdet: 3D 좌표계에서 2D 스크린 좌표로 변환하기 위한 값
	invdet = 1.0 / (view.plane.x * view.dir.y - view.dir.x * view.plane.y);
	// 스프라이트의 화면상 x좌표: 플레이어의 방향 벡터에 영향을 받는다.
	transform.x = invdet * (view.dir.y * sprite_rel_pos.x - view.dir.x * sprite_rel_pos.y);
	// 스프라이트의 화면상 y좌표: 깊이 정보가 포함되어 있어 z_buffer에서의 깊이 확인에 사용
	transform.y = invdet * (-view.plane.y * sprite_rel_pos.x + view.plane.x * sprite_rel_pos.y);
	return (transform);
}

void	cal_sprite_screen_params(t_sprite sprite, t_view view, t_object *object)
{
	// 스프라이트의 화면상 좌표
	object->transform = sprite_to_view(sprite, view);
	// 스프라이트가 화면의 X 좌표에서 위치할 픽셀 계산
	object->spritescreenx = (int)((SCREEN_WIDTH / 2) * (1 + object->transform.x / object->transform.y));
	// 스프라이트의 화면상 높이 및 너비 계산
	object->spriteheight = abs((int)(SCREEN_HEIGHT / object->transform.y));
	object->spritewidth = abs((int)(SCREEN_HEIGHT / object->transform.y));
}

void	cal_sprite_draw_bounds(t_object *object)
{
	object->drawstart.y = -object->spriteheight / 2 + SCREEN_HEIGHT / 2; 
	object->drawend.y = object->spriteheight / 2 + SCREEN_HEIGHT / 2;
	if (object->drawstart.y < 0)
		object->drawstart.y = 0;
	if (object->drawend.y >= SCREEN_HEIGHT)
		object->drawend.y = SCREEN_HEIGHT - 1; 
	object->drawstart.x = -object->spritewidth / 2 + object->spritescreenx; 
	object->drawend.x = object->spritewidth / 2 + object->spritescreenx;
	if (object->drawstart.x < 0)
		object->drawstart.x = 0;
	if (object->drawend.x >= SCREEN_WIDTH)
		object->drawend.x = SCREEN_WIDTH - 1;
}

void draw_pixeline_object(t_object object, t_tex3d *tex3d, t_sprite sprite)
{
	t_pair_int	tex;
	t_pair_int	draw;
	int			pixelpos;
	int			color;

	draw.x = object.drawstart.x;
	while (draw.x < object.drawend.x)
	{
		// 텍스처의 X 좌표 계산
		tex.x = (int)(256 * (draw.x - (-object.spritewidth / 2 + object.spritescreenx)) * tex3d->widtheight.x / object.spritewidth) / 256;
		if (object.transform.y > 0 && draw.x > 0 && draw.x < SCREEN_WIDTH && object.transform.y < object.z_buffer[draw.x]) // 스프라이트의 깊이 체크 및 화면에 그리기
		{
			draw.y = object.drawstart.y;
			while (draw.y < object.drawend.y)
			{
				// 픽셀 위치
				pixelpos = draw.y * 256 - SCREEN_HEIGHT * 128 + object.spriteheight * 128;
				// 텍스처 Y 좌표 계산
				tex.y = ((pixelpos * tex3d->widtheight.y) / object.spriteheight) / 256;
				// 텍스처 픽셀 색상 가져오기
				color = tex3d->object[sprite.idx][tex3d->object[sprite.idx]->animation].addr[tex3d->widtheight.y * tex.y + tex.x];

				// if ((color & 0x00FFFFFF) != 0) // 투명도 처리
				tex3d->display.addr[draw.y * SCREEN_WIDTH + draw.x] = color; // 최종 픽셀 값 설정
				draw.y++;
			}
		}
		draw.x++;
	}
}


void render_object(t_rnd3d*rnd, char **map)
{
	int idx;

	idx = 0;
	// 0. 스프라이트 절대 위치 저장
	save_sprite_pos(map, &rnd->object);
	// 1. 플레이어와 스프라이트의 거리 계산
	cal_sprite_distance(rnd->view, &rnd->object);
	// 2. 거리 기준으로 스프라이트 정렬
	sort_sprites(&rnd->object);
	while (idx < N_OBJECT)
	{
		// 3. 스프라이트 화면상 좌표 그리기
		cal_sprite_screen_params(rnd->object.sprites[idx], rnd->view, &rnd->object);
		// 스프라이트가 화면에 그려질 시작 및 끝 좌표 계산
		cal_sprite_draw_bounds(&rnd->object);
		// z_buffer를 이용한 깊이 체크 및 스프라이트 그리기
		draw_pixeline_object(rnd->object, &rnd->tex3d, rnd->object.sprites[idx]);
		idx++;
	}
}

int animation_clock(long *pre, double wait)
{
	struct timeval	time;
	long			now_sec;
	long			now_usec;
	long			elapsed;

	// 현재 시간 가져오기
	gettimeofday(&time, NULL);
	now_sec = (long)(time.tv_sec);
	now_usec = (long)(time.tv_usec);
	if (!*pre)
		*pre = now_sec * 1000000 + now_usec; // 초기화 시점 저장 (마이크로초 단위)
	else
	{
		elapsed = (now_sec * 1000000 + now_usec) - *pre; // 경과 시간 계산 (마이크로초 단위)
		if (elapsed > wait * 1000000)
		{
			*pre = now_sec * 1000000 + now_usec; // 현재 시점 저장 (마이크로초 단위)
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_FAILURE);
}

void animation_door_anidx(t_rnd3d *rnd3d, t_pair_int idx, int offset)
{
	t_pair_dbl	relpos;
	double		dist;
	int			anidx;

	relpos.x = idx.x - rnd3d->view.pos.x + 0.8;
	relpos.y = idx.y - rnd3d->view.pos.y + 0.8;
	dist = sqrt(relpos.x * relpos.x + relpos.y * relpos.y);
	anidx = offset - dist;
	if (anidx >= N_ANIMATION)
		anidx = N_ANIMATION - 1;
	// printf("%d\n", anidx);
	if (anidx == 3 || anidx == 0)
		rnd3d->tex3d.doormap[idx.y][idx.x] = (char)anidx;
	else if (rnd3d->tex3d.doormap[idx.y][idx.x] >= 0 && rnd3d->tex3d.doormap[idx.y][idx.x] <= 2 \
			&& animation_clock(&rnd3d->tex3d.time, DOORSPEED) == EXIT_SUCCESS)
				rnd3d->tex3d.doormap[idx.y][idx.x]++;
	// printf("(%d, %d) = %f\n", idx.y, idx.x, dist);
}

// 플레이어의 근접성에 따라 문 애니메이션을 관리하는 함수
void animation_door(t_rnd3d *rnd3d, char **map)
{
	double		offset;
	t_pair_int	start;
	t_pair_int	end;
	t_pair_int	idx;

	// 플레이어 주변을 체크할 거리
	offset = 4.0;
	// 플레이어 주변을 체크할 범위 정의
	start.y = (int)fmax(rnd3d->view.pos.y - offset, 0);
	end.y = (int)rnd3d->view.pos.y + offset;
	idx.y = start.y;
	while (idx.y < end.y && map[idx.y])
	{
		start.x = (int)fmax(rnd3d->view.pos.x - offset, 0);
		end.x = (int)rnd3d->view.pos.x + offset;
		idx.x = start.x;
		while (idx.x < end.x && map[idx.y][idx.x])
		{
			if (map[idx.y][idx.x]== 'e' || map[idx.y][idx.x] == 'd')
				animation_door_anidx(rnd3d, idx, offset);
			idx.x++;
		}
		idx.y++;
	}
}

void	animation_object(t_game *game)
{
	int idx; 

	idx = 0;
	while (idx < N_OBJECT)
	{	
		if (animation_clock(&game->rnd.tex3d.object[idx]->time, OBJSPEED) == EXIT_SUCCESS)
			game->rnd.tex3d.object[idx]->animation =(game->rnd.tex3d.object[idx]->animation + 1) % N_ANIMATION;
		idx++;
	}
}

void draw_3dmap(t_game *game)
{
	init_render(&game->rnd, game->player, game->map);
	animation_object(game);
	animation_door(&game->rnd, game->map);
	render_ceilfloor(&game->rnd);
	render_wall(&game->rnd, game->map);
	render_object(&game->rnd, game->map);
	mlx_put_image_to_window(game->mlx, game->win, game->rnd.tex3d.display.img, 0, 0);
}

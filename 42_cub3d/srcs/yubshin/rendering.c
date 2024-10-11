#include "../../cub3d.h"

void	init_rnd(t_rnd *rnd, t_player player)
{
	rnd->pos.x = player.pos.x;
	rnd->pos.y = player.pos.y;
	rnd->dir.x = player.pos.x;
	rnd->dir.y = player.pos.y;
	rnd->plane.x = 0;
	rnd->plane.y = 0.66;
	rnd->cframetime = 0;	
	rnd->pframetime = 0;	
	// rnd->wh_pxl.x = width;
	// rnd->wh_pxl.y = height;
}

void	cal_step(t_rnd *rnd)
{
	if (rnd->raydir.x < 0)
		rnd->step.x = -1; //왼쪽 이동
	else
		rnd->step.x = 1; //오른쪽 이동
	if (rnd->raydir.y < 0)
		rnd->step.y = -1; //아래 이동
	else
		rnd->step.y = 1; //위 이동
}

void	cal_sidedist(t_rnd *rnd)
{
	if (rnd->raydir.x < 0)
		rnd->side_dist.x = (rnd->pos.x - rnd->map.x) * rnd->delta_dist.x;
	else
		rnd->side_dist.x = (rnd->pos.x + 1.0 - rnd->map.x) * rnd->delta_dist.x;
	if (rnd->raydir.y < 0)
		rnd->side_dist.y = (rnd->pos.y - rnd->map.y) * rnd->delta_dist.y;
	else
		rnd->side_dist.y = (rnd->pos.y + 1.0 - rnd->map.y) * rnd->delta_dist.y;
}

void	cal_deltadist(t_rnd *rnd)
{
	rnd->delta_dist.x = sqrt(1 + (rnd->raydir.y * rnd->raydir.y) / (rnd->raydir.x * rnd->raydir.x));
	rnd->delta_dist.y = sqrt(1 + (rnd->raydir.x * rnd->raydir.x) / (rnd->raydir.y * rnd->raydir.y));
}

void	cal_raydir(t_rnd *rnd, int x)
{
	rnd->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	rnd->raydir.x = rnd->dir.x + rnd->plane.x * rnd->camera_x;
	rnd->raydir.y = rnd->dir.y + rnd->plane.y * rnd->camera_x;
}

void	cal_dist(t_rnd *rnd, int x)
{
	cal_raydir(rnd, x);
	rnd->map.x = (int)rnd->pos.x;
	rnd->map.y = (int)rnd->pos.y;
	cal_deltadist(rnd);
	cal_step(rnd);
	cal_sidedist(rnd);
}

void	dda(t_rnd *rnd, char **map)
{
	rnd->hit = 0;
	while (rnd->hit == 0)
	{
		if (rnd->side_dist.x < rnd->side_dist.y)
		{
			rnd->side_dist.x += rnd->delta_dist.x;
			rnd->map.x += rnd->step.x;
			rnd->side = 0; //ns벽을 hit
		}
		else
		{
			rnd->side_dist.y += rnd->delta_dist.y;
			rnd->map.y += rnd->step.y;
			rnd->side = 1; //ew벽을 hit
		}
		if (map[rnd->map.x][rnd->map.y] == 1)
			rnd->hit = 1;
	}
}


void	cal_perp_wall_dist(t_rnd *rnd)
{
	if (rnd->side == 0)
		rnd->per_wall_dist = rnd->side_dist.x - rnd->delta_dist.x;
	else
		rnd->per_wall_dist = rnd->side_dist.y - rnd->delta_dist.y;
}

void	cal_lineheight(t_rnd *rnd)
{
	rnd->line_height = (int)(SCREEN_HEIGHT / rnd->per_wall_dist);
}

void	cal_drawstartend(t_rnd *rnd)
{
	int	pitch;

	pitch = 100;
	rnd->draw_start = -rnd->line_height / 2 + SCREEN_HEIGHT / 2 + pitch;
	if (rnd->draw_start < 0)
		rnd->draw_start = 0;
	rnd->draw_end = rnd->line_height / 2 + SCREEN_HEIGHT / 2 + pitch;
	if (rnd->draw_end < 0)
		rnd->draw_end = SCREEN_HEIGHT - 1;
}

void	cal_wall_x(t_rnd *rnd)
{
	if (rnd->side == 0)
		rnd->wall_x = rnd->pos.y + rnd->per_wall_dist * rnd->raydir.y;
	else
		rnd->wall_x = rnd->pos.x + rnd->per_wall_dist * rnd->raydir.x;
	rnd->wall_x -= floor(rnd->wall_x);
}

void	cal_text_x(t_rnd *rnd)
{
	int textwidth = 32;
	
	rnd->text_x = (int)(rnd->wall_x * (double)textwidth);
	if ((rnd->side == 0 && rnd->raydir.x > 0) || (rnd->side == 1 && rnd->raydir.y < 0)) 
 		rnd->text_x = textwidth - rnd->text_x - 1;
}

void	cal_loop(t_rnd *rnd, t_player player, char **map)
{
	int x;

	x = 0;
	init_rnd(rnd, player); //밖으로 뺴야할듯 
	while (x < SCREEN_WIDTH)
	{
		cal_dist(rnd, x);
		dda(rnd, map);
		cal_perp_wall_dist(rnd);
		cal_lineheight(rnd);
		cal_drawstartend(rnd);
		rnd->textnum = map[rnd->map.x][rnd->map.y] - 1;
		
		x++;
	}
}

#include "../../cub3d.h"

void	init_rnd(t_rnd *rnd, t_player player)
{
	rnd->pos.x = player.pos.x;
	rnd->pos.y = player.pos.y;
	rnd->dir.x = player.dir.x;
	rnd->dir.y = player.dir.y;
	rnd->plane.x = 0;
	rnd->plane.y = 0.66;
	rnd->cframetime = 0;
	rnd->pframetime = 0;
	rnd->pitch = 100;

	rnd->buffer = (unsigned int **)ft_calloc(SCREEN_HEIGHT, sizeof(unsigned int *));

	int idx = 0;
	while (idx < SCREEN_HEIGHT)
		rnd->buffer[idx++] = (unsigned int *)ft_calloc(SCREEN_WIDTH, sizeof(unsigned int));
}


void	cal_raydir(t_rnd *rnd, int x)
{
	rnd->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	rnd->raydir.x = rnd->dir.x + rnd->plane.x * rnd->camera_x;
	rnd->raydir.y = rnd->dir.y + rnd->plane.y * rnd->camera_x;
}

void	cal_deltadist(t_rnd *rnd)
{
	rnd->delta_dist.x = fabs(1 / rnd->raydir.x);
	rnd->delta_dist.y = fabs(1 / rnd->raydir.y);
	// rnd->delta_dist.x = sqrt(1 + (rnd->raydir.y * rnd->raydir.y) / (rnd->raydir.x * rnd->raydir.x));
	// rnd->delta_dist.y = sqrt(1 + (rnd->raydir.x * rnd->raydir.x) / (rnd->raydir.y * rnd->raydir.y));
}

void	cal_step(t_rnd *rnd)
{
	if (rnd->raydir.x < 0)
		rnd->step.x = -1; //동 이동
	else
		rnd->step.x = 1; //서 이동
	if (rnd->raydir.y < 0)
		rnd->step.y = -1; //남 이동
	else
		rnd->step.y = 1; //북 이동
}

void	cal_sidedist(t_rnd *rnd)
{
	if (rnd->raydir.x < 0)
		rnd->side_dist.x = (rnd->pos.x - rnd->map.x) * rnd->delta_dist.x;
	else
		rnd->side_dist.x = (rnd->map.x + 1.0 - rnd->pos.x) * rnd->delta_dist.x;
	if (rnd->raydir.y < 0)
		rnd->side_dist.y = (rnd->pos.y - rnd->map.y) * rnd->delta_dist.y;
	else
		rnd->side_dist.y = (rnd->map.y + 1.0 - rnd->pos.y) * rnd->delta_dist.y;
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
	while (1)
	{
		if (rnd->side_dist.x < rnd->side_dist.y)
		{
			rnd->side_dist.x += rnd->delta_dist.x;
			rnd->map.x += rnd->step.x;
			//ns벽을 hit
			rnd->side = 0;
		}
		else
		{
			rnd->side_dist.y += rnd->delta_dist.y;
			rnd->map.y += rnd->step.y;
			//ew벽을 hit
			rnd->side = 1;
		}
		// printf("%d, %d\n", rnd->map.y, rnd->map.x);
		// printf("%c\n", map[rnd->map.y][rnd->map.x]);
		if (map[rnd->map.y][rnd->map.x] == '1')
		{
			rnd->hit = 1;
			break ;
		}
	}
}

void	cal_perp_wall_dist(t_rnd *rnd)
{
	// if (rnd->side == 3 || rnd->side == 1)
	// 	rnd->per_wall_dist = rnd->side_dist.x - rnd->delta_dist.x;
	// else
	// 	rnd->per_wall_dist = rnd->side_dist.y - rnd->delta_dist.y;
	if (rnd->side == 0)
		rnd->per_wall_dist = (rnd->map.x - rnd->pos.x + (1 - rnd->step.x) / 2) / rnd->raydir.x; 
	else
		rnd->per_wall_dist = (rnd->map.y - rnd->pos.y + (1 - rnd->step.y) / 2) / rnd->raydir.y; 

}

void	cal_lineheight(t_rnd *rnd)
{
	rnd->line_height = (int)(SCREEN_HEIGHT / rnd->per_wall_dist);
}

void	cal_drawstartend(t_rnd *rnd)
{
	rnd->draw_start = -rnd->line_height / 2 + SCREEN_HEIGHT / 2;
	if (rnd->draw_start < 0)
		rnd->draw_start = 0;
	rnd->draw_end = rnd->line_height / 2 + SCREEN_HEIGHT / 2;
	if (rnd->draw_end >= SCREEN_HEIGHT)
		rnd->draw_end = SCREEN_HEIGHT - 1;
}

void	cal_textnum(t_rnd *rnd, char **map)
{
	rnd->texnum = map[rnd->map.y][rnd->map.x] - '0';
}

void	cal_wall_x(t_rnd *rnd)
{
	if (rnd->side == 0)
		rnd->wall_x = rnd->pos.y + rnd->per_wall_dist * rnd->raydir.y;
	else
		rnd->wall_x = rnd->pos.x + rnd->per_wall_dist * rnd->raydir.x;
	rnd->wall_x -= floor(rnd->wall_x); //?
}

void	cal_tex_x(t_rnd *rnd)
{
	double texwidth = 32;
	
	cal_wall_x(rnd);
	rnd->tex_x = (int)(rnd->wall_x * (double)texwidth);
	// if (((rnd->side == 3 || rnd->side == 1) && rnd->raydir.x > 0) || ((rnd->side == 2 || rnd->side == 0)&& rnd->raydir.y < 0)) 
	if ((rnd->side == 0 && rnd->raydir.x > 0) || (rnd->side == 1&& rnd->raydir.y < 0)) 
 		rnd->tex_x = texwidth - rnd->tex_x - 1;
}

void	cal_onestep(t_rnd *rnd)
{
	double	texheight = 32;

	rnd->one_step = 1.0 * texheight / rnd->line_height;
}

void	cal_texpos(t_rnd *rnd)
{
	rnd->tex_pos = (rnd->draw_start - SCREEN_HEIGHT / 2 + rnd->line_height / 2) * rnd->one_step;
	// printf("draw_start: %d\n", rnd->draw_start);
	// printf("pitch: %d\n", rnd->pitch);
	// printf("line_height: %d\n", rnd->line_height);
	// printf("one_step: %f\n", rnd->one_step);
	// printf("tex_pos: %d\n", rnd->tex_pos);
}

int	*find_texture(t_rnd *rnd, t_texture texture)
{
	return (texture.wall[3]);
	if (rnd->texnum == 1)
	{
		// if(rnd->side == 0 && rnd->raydir.x >= 0)
		// 	return (texture.wall[0]); // 왼쪽 벽 텍스처
		// else if(rnd->side == 0 && rnd->raydir.x < 0)
		// 	return (texture.wall[1]); // 오른쪽 벽 텍스처
		// else if(rnd->side == 1 && rnd->raydir.y >= 0)
		// 	return (texture.wall[2]); // 아래 벽 텍스처
		// else
			 // 위 벽 텍스처
		// if (rnd->side == 0) // West
		// 	return (texture.wall[0]); // 왼쪽 벽 텍스처
		// else if (rnd->side == 1) // East
		// 	return (texture.wall[1]); // 오른쪽 벽 텍스처
		// else if (rnd->side == 2) // South
		// 	return (texture.wall[2]); // 아래 벽 텍스처
		// else if (rnd->side == 3) // North
		// 	return (texture.wall[3]); // 위 벽 텍스처
	}
	return (NULL);
}

void 	set_pixeline(t_rnd *rnd, int *texture, int x)
{
	int				y;
	int				tex_y;
	int				texheight = 32;
	unsigned int	color;
	// char			*dst;

	y = rnd->draw_start;
	while (y < rnd->draw_end)
	{
		tex_y = (int)rnd->tex_pos & (texheight - 1);
		rnd->tex_pos += rnd->one_step;
		color = texture[texheight * tex_y + rnd->tex_x];
		// printf("%d, %d, %d\n", rnd->tex_x, tex_y, color);
		// if (rnd->side == 1)
		// 	color = (color >> 1) & 8355711;
		rnd->buffer[y][x] = color;
		// dst = *addr + (y * info.size_l + x * (info.bpp/8));
		// *(unsigned int *)dst = color;
		y++;
	}
}
void	ready_to_put_image(t_rnd *rnd)
{
	int x;
	int y;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			rnd->addr[y * SCREEN_WIDTH + x] = rnd->buffer[y][x];
			x++;
		}
		y++;
	}
}
void debug_rendering(t_rnd *rnd)
{
	printf("pos       | %f, %f\n", rnd->pos.x, rnd->pos.y);
	printf("dir       | %f, %f\n", rnd->dir.x, rnd->dir.y);
	printf("plane     | %f, %f\n", rnd->plane.x, rnd->plane.y);
	printf("map       | %d, %d\n", rnd->map.x, rnd->map.y);
	printf("step      | %d, %d\n", rnd->step.x, rnd->step.y);
	printf ("camera_x | %f\n", rnd->camera_x );
	printf("raydir    | %f, %f \n", rnd->raydir.x, rnd->raydir.y);
	printf("deltadist | %f, %f \n", rnd->delta_dist.x, rnd->delta_dist.y);
	printf("sidedist  | %f, %f \n", rnd->side_dist.x, rnd->side_dist.y);
	printf ("per_wall_dist | %f\n\n", rnd->per_wall_dist);
}

void	cal_loop(t_rnd *rnd, t_player player, t_texture texture, char **map)
{
	(void) texture;
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
		cal_textnum(rnd, map);
		cal_tex_x(rnd);
		cal_onestep(rnd);
		cal_texpos(rnd); 
		// debug_rendering(rnd);
		set_pixeline(rnd, find_texture(rnd, texture), x);
		x++;
	}
}




void	draw_3dmap(t_game *game)
{
	game->rnd.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->rnd.addr = mlx_get_data_addr(game->rnd.img, &game->texture.info.bpp, &game->texture.info.size_l, &game->texture.info.endian);

	cal_loop(&game->rnd, game->player, game->texture, game->map);
	// draw_floor(&game->rnd, game);
	ready_to_put_image(&game->rnd);
	mlx_put_image_to_window(game->mlx, game->win, game->rnd.img, 20, 20);

// while (x < SCREEN_WIDTH)
	// {
	// 	y = 0;
	// 	while (y < SCREEN_HEIGHT)
	// 	{
	// 		color = (int)game->rnd.buffer[y][x];
	// 		printf("%d, %d, %d\n", x, y, color);
	// 		// mlx_pixel_put(game->mlx, game->win, x, y, color);
	// 		y++;
	// 	}
	// 	x++;
	// }
}
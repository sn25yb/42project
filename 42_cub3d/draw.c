/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:23:49 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/24 16:29:23 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

t_img2d	select_image(char *what, t_map2d map)
{

	if (*what == ' ')
		return (map.empty);
	else if (*what == '0' || *what == 'e')
		return (map.way);
	else if (*what == '1')
		return (map.wall);
	else if (*what != 'd')
		return (map.target);
	else if (*what == 'd' && *(what + 1) == '1')
		return (map.door[1]);
	return (map.door[0]);
}


void	draw_bg(t_game *game)
{
	t_img2d		img;
	t_pair_int	id;
	const int	map_size = 10;
	char		what;

	id = make_pair_int(0, 0);
	what = '0';
	img = select_image(&what, game->rnd2d.minimap);
	while (id.y <= map_size)
	{
		id.x = 0;
		while (id.x <= map_size)
		{
			mlx_put_image_to_window(game->mlx, game->win,  \
			img.image, img.size.x * id.x, SCREEN_HEIGHT + \
			(id.y - 11) * img.size.y);
			id.x++;
		}
		id.y++;
	}
}

void	draw_map(t_game *game)
{
	t_pair_int	map_pos;
	t_pair_int	id;
	t_img2d		img;
	char		**map;	

	map = game->rnd2d.minimap.map;
	map_pos = make_pair_int(game->player.pos.x, game->player.pos.y);
	id.y = map_pos.y;
	while (id.y < map_pos.y + 11)
	{
		id.x = map_pos.x;
		while (id.x < map_pos.x + 11)
		{
			img = select_image(&map[id.y][id.x], game->rnd2d.minimap);
			mlx_put_image_to_window(game->mlx, game->win, \
			img.image, (id.x - map_pos.x) * img.size.x, SCREEN_HEIGHT + \
			(id.y - map_pos.y - 11) * img.size.y);
			id.x++;
		}
		id.y++;
	}
}


// t_pair_int	convert_halfup(t_pair_dbl xy)
// {
// 	t_pair_int	ret;
// 	t_pair_int	temp;
// 	t_pair_int	temp2;

// 	temp = make_pair_int(xy.x, xy.y);
// 	temp2 = make_pair_int(xy.x + 1, xy.y + 1);

// 	if (xy.x - (double)temp.x > (double)temp2.x - xy.x)
// 		ret.x = temp2.x;
// 	else
// 		ret.x = temp.x;
// 	if (xy.y - (double)temp.y > (double)temp2.y - xy.y)
// 		ret.y = temp2.y;
// 	else
// 		ret.y = temp.y;
// 	return (ret);
// }

void	put_playerbg(t_img2d *ret)
{
	t_pair_int	xy;

	xy.y = 0;
	while (xy.y < ret->size.y)
	{
		xy.x = 0;
		while (xy.x < ret->size.x)
		{
			ret->addr[ret->size_l / (ret->bpp / 8) * xy.y + xy.x] = WAY_COLOR;
			xy.x++;
		}
		xy.y++;
	}
}

void	put_playerimg(t_img2d *ret, t_img2d src, double rad)
{
	t_pair_int	xy;
	t_pair_dbl	cal_xy;
	t_pair_int	nxy;
	t_pair_dbl	cxy;

	xy.y = 0;
	cxy = make_pair_dbl((double)src.size.x / 2, (double)src.size.y / 2 - 0.5);
	while (xy.y < src.size.y)
	{
		xy.x = 0;
		while (xy.x < src.size.x)
		{
			nxy.x = cos(rad) * ((double)xy.x - cxy.x) + \
			cxy.x - sin(rad) * ((double)xy.y - cxy.y) + 0.001;
			nxy.y = cos(rad) * ((double)xy.y - cxy.y) + \
			sin(rad) * ((double)xy.x - cxy.x) + cxy.y + 0.001;
			if (nxy.x >= 0 && nxy.y >= 0 && \
			nxy.y < src.size.y && nxy.x < src.size.x)
				ret->addr[ret->size_l / (ret->bpp / 8) * nxy.y + nxy.x] \
				= src.addr[xy.y * ret->size_l / (ret->bpp / 8) + xy.x];
			xy.x++;
		}
		xy.y++;
	}
}

void	draw_player(t_game *game)
{
	t_star	*player;
	t_img2d	bg;

	player = &game->rnd2d.minimap.player;
	bg = game->rnd2d.minimap.way;
	put_playerbg(&player->player_conv);
	put_playerimg(&player->player_conv, player->player, game->player.rad + M_PI / 2L);
	mlx_put_image_to_window(game->mlx, game->win, player->player_conv.image, 5 * bg.size.x \
	, SCREEN_HEIGHT - 6 * bg.size.y);
}

void	draw_minimap(t_game *game)
{
	draw_bg(game);
	draw_map(game);
	draw_player(game);
}

void	draw_object(t_game *game, t_queue *node, int id)
{
	t_img2d		img;
	t_pair_int	xy;

	if (!node)
		img = game->rnd2d.inventory.img;
	else
		img = game->rnd2d.minimap.object[node->num];
	xy.x = SCREEN_WIDTH / 2 - img.size.x / 2 * 5;
	xy.y = 50;
	mlx_put_image_to_window(game->mlx, game->win, img.image, \
	xy.x + id * img.size.x, xy.y);
}

void	draw_inventory(t_game *game)
{
	t_queue	*head;
	t_queue	*node;
	int		index;

	head = game->rnd2d.inventory.pocket.head;
	node = head;
	index = 0;
	while (index < 5)
	{
		draw_object(game, node, index);
		if (node)
			node = node->next;
		if (node == head)
			node = NULL;
		index++;
	}
}

void	draw_gameclock(t_game *game)
{
	struct timeval	time;
	long			now_sec;
	long			now_usec;
	int				elapsed;
	int				timeleft;

	// 현재 시간 가져오기
	gettimeofday(&time, NULL);
	now_sec = (long)(time.tv_sec);
	now_usec = (long)(time.tv_usec);
	if (!game->set.gamestart)
		game->set.gamestart = now_sec * 1000000 + now_usec; // 초기화 시점 저장 (마이크로초 단위)
	elapsed = ((now_sec * 1000000 + now_usec) - game->set.gamestart) / 1000000; // 경과 시간 계산 (마이크로초 단위)
	timeleft = TIMELIMIT - elapsed;
	if (timeleft < 0)
	{
		game->set.game_over = TRUE;
		end_game(game);
		return ;
	}
	char *str0 = ft_itoa(timeleft);
	char *str1 = ft_strjoin(str0, "sec");
	mlx_string_put(game->mlx, game->win, 100, 100 ,0xFFFFFF, str1);
	free(str0);
	free(str1);
}

void	draw_images(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	draw_3dmap(game);
	draw_minimap(game);
	draw_inventory(game);
	draw_gameclock(game);
}

int	draw_images_hook(t_game *game)
{
	if (!game->set.is_begin || game->rnd2d.script.ing || game->set.is_ending)
		return (0);
	draw_images(game);
	return (0);
}

void	draw_startscreen(t_game *game)
{
	t_img2d	img;

	mlx_clear_window(game->mlx, game->win);
	img = game->rnd2d.startbg;
	mlx_put_image_to_window(game->mlx, game->win, img.image, 0, 0);
	// img = game->minimap.image.logo;
	// mlx_put_image_to_window(game->mlx, game->win, \
	// img.image, SCREEN_WIDTH / 2 - img.size.x / 2, SCREEN_HEIGHT * 1 / 5);
	// img = game->minimap.image.start;
	// mlx_put_image_to_window(game->mlx, game->win, \
	// img.image, SCREEN_WIDTH / 2 - img.size.x / 2, 4 * SCREEN_HEIGHT / 5);

	// mlx_string_put(game->mlx, game->win, 100, 100 ,0xFFFFFF, "I'm Korean Elite Zookeeper..!!\n");
}

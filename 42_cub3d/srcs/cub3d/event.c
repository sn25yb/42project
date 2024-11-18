/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:25:17 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/31 12:48:50 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_boolean	is_reachable(char **map, int x, int y)
{
	if (x < 0 || y < 0)
		return (FALSE);
	if (!map[y] || (int)ft_strlen(map[y]) <= x)
		return (FALSE);
	if (is_wall(map[y][x]))
		return (FALSE);
	return (TRUE);
}

void	init_scriptinfo(t_script *script)
{
	free_array(script->lines);
	script->lines = NULL;
	script->ing = FALSE;
	script->id = FALSE;
}

int	get_scene(t_game *game)
{
	t_script	*script;
	int			scene_num;

	script = &game->rnd2d.script;
	scene_num = script->scene_num;
	if (!script->lines && set_scene(script))
		return (EXTRA);
	if (script->lines[script->id])
	{
		display_profile(script, game->mlx, game->win);
		display_msgbox(script, game->mlx, game->win);
		script->id++;
		return (EXIT_SUCCESS);
	}
	init_scriptinfo(script);
	if (script->scene_num == INTRO)
		start_game(game);
	if (script->scene_num == OUTRO || script->scene_num == OUTRO2)
		end_game(game);
	script->scene_num = NO_SCENE;
	return (EXIT_SUCCESS);
}

void	player_move(t_game *game, int keycode)
{
	t_pair_int	map_pos;
	t_view		p;

	p = game->player;
	map_pos = make_pair_int(p.pos.x, p.pos.y);
	if (keycode == KEY_ARROW_L)
		change_dir(&p, M_PI / 20L);
	else if (keycode == KEY_ARROW_R)
		change_dir(&p, -M_PI / 20L);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT || \
	keycode == KEY_DOWN || keycode == KEY_UP)
		change_pos(&p, keycode);
	if (p.pos.y < 0 || p.pos.x < 0)
		p = game->player;
	else if (!is_reachable(game->map, p.map_pos.x, p.map_pos.y))
		p = game->player;
	else if (!is_reachable(game->map, map_pos.x, p.map_pos.y) && \
	!is_reachable(game->map, p.map_pos.x, map_pos.y))
		p = game->player;
	game->player = p;
}

int	check_event(t_game *game)
{
	t_pair_int	pos;

	pos = make_pair_int(game->player.pos.x, game->player.pos.y);
	if (game->map[pos.y][pos.x] == 'e')
		return (check_escape(game));
	if (!collect_pandas(game))
		display_images(game);
	return (get_scene(game));
}

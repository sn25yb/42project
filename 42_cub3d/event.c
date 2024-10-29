/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:25:17 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/24 16:25:19 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

t_boolean	is_reachable(char **map, int x, int y)
{
	if (x < 0 || y < 0)
		return (FALSE);
	if (!map[y] || (int)ft_strlen(map[y]) <= x)
		return (FALSE);
	if (map[y][x] == '1')
		return (FALSE);
	return (TRUE);
}

int	mouse_motion(int x, int y, t_game *game)
{
	(void) y;
	if (!game->set.mouse.on || game->set.is_ending || game->rnd2d.script.ing)
		return (0);
	change_dir(&game->player, x);
	mlx_mouse_move(game->win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	game->set.mouse.pos = make_pair_int(x, y);
	// mlx_mouse_get_pos(game->win, &game->set.mouse.pos.x, \
	&game->set.mouse.pos.y);
	draw_images(game);
	return (EXIT_SUCCESS);
}

// int	mouse_release(int button, int x, int y, t_game *game)
// {
// 	if (game->lcycle.exit_flag)
// 		return (EXIT_SUCCESS);
// 	if (game->key.mouse.on == TRUE || button != 1)
// 		return (EXIT_SUCCESS);
// 	if (x < (SCREEN_WIDTH - 240) / 2 || x > (SCREEN_WIDTH + 240) / 2)
// 		return (EXIT_SUCCESS);
// 	if (y < (SCREEN_HEIGHT - SCREEN_HEIGHT / 4) || \
// 	y > (SCREEN_HEIGHT - SCREEN_HEIGHT / 4 + 75))
// 		return (EXIT_SUCCESS);
// 	return (start_game(game));
// }

void	init_scriptinfo(t_script *script)
{
	free_array(script->lines);
	script->lines = NULL;
	script->ing = 0;
	script->id = 0;
}

int	get_scene(t_game *game)
{
	t_script	*script;
	int	scene_num;

	script = &game->rnd2d.script;
	scene_num = script->scene_num;

	if (!script->lines && set_scene(script))
		return (EXTRA);
	if (script->lines[script->id])
	{
		show_msg(script, game->mlx, game->win);
		script->id++;
		return (EXIT_SUCCESS);
	}
	init_scriptinfo(script);
	if (script->scene_num == INTRO)
		start_game(game);
	if (script->scene_num == OUTRO || script->scene_num == OUTRO2)
		end_game(game);
	script->scene_num = 0;
	return (EXIT_SUCCESS);
}

void	player_move(t_game *game, int keycode)
{
	t_pair_int	next_map_pos;
	t_pair_int	map_pos;
	t_player	p;

	p = game->player;
	map_pos = make_pair_int(p.pos.x, p.pos.y);
	change_pos(&p, keycode);
	next_map_pos = make_pair_int(p.pos.x, p.pos.y);
	if (p.pos.y < 0 || p.pos.x < 0)
		p = game->player;
	else if (!is_reachable(game->map, next_map_pos.x, next_map_pos.y))
		p = game->player;
	else if (!is_reachable(game->map, map_pos.x, next_map_pos.y) && \
	!is_reachable(game->map, next_map_pos.x, map_pos.y))
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
		draw_images(game);
	return (get_scene(game));
}

int	event_wt_user(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game, EXIT_SUCCESS);
	if (keycode == KEY_SPACE && game->rnd2d.script.ing && get_scene(game))
		exit_game(game, EXTRA);
	if (game->rnd2d.script.ing || game->set.is_ending)
		return (EXIT_SUCCESS);
	if (keycode == KEY_ENTER && !game->set.is_begin && get_scene(game))
		exit_game(game, EXTRA);
	if (!game->set.is_begin)
		return (EXIT_SUCCESS);
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT || \
	keycode == KEY_DOWN || keycode == KEY_UP)
		player_move(game, keycode);
	if (check_event(game))
		exit_game(game, EXTRA);
	return (EXIT_SUCCESS);
}

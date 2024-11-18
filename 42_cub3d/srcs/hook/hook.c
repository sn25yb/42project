/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:39:22 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/12 10:24:29 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d/cub3d.h"

int	display_images_hook(t_game *game)
{
	t_pair_int	pos;

	pos = game->hui.map_pos;
	if (!game->set.is_begin || game->rnd2d.script.ing || game->set.is_ending)
		return (0);
	game->hui.speed++;
	game->hui.speed %= 4;
	if (game->map[pos.y][pos.x] == 'H' && !game->hui.speed)
	{
		escape_hui(&game->hui, &game->map);
		collect_pandas(game);
	}
	display_images(game);
	return (0);
}

int	mouse_motion(int x, int y, t_game *game)
{
	(void) y;
	if (!game->set.mouse.on || game->set.is_ending || game->rnd2d.script.ing)
		return (0);
	change_dir(&game->player, cal_mouse_dir(x));
	mlx_mouse_move(game->win, SCREEN_W / 2, SCREEN_H / 2);
	game->set.mouse.pos = make_pair_int(x, y);
	display_images(game);
	return (EXIT_SUCCESS);
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
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT || keycode == KEY_DOWN \
	|| keycode == KEY_UP || keycode == KEY_ARROW_L || keycode == KEY_ARROW_R)
		player_move(game, keycode);
	if (check_event(game))
		exit_game(game, EXTRA);
	return (EXIT_SUCCESS);
}

int	destroy_game(t_game *game)
{
	exit_game(game, EXIT_SUCCESS);
	return (0);
}

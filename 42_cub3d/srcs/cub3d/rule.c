/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:34:41 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/31 13:10:30 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_escape(t_game *game)
{
	if (is_allinventory(game->rnd2d.inventory.pocket))
		game->rnd2d.script.scene_num = OUTRO;
	else
		game->rnd2d.script.scene_num = OUTRO2;
	return (get_scene(game));
}

t_boolean	get_objs(t_game *game, t_objs objs)
{
	t_objs		preq;

	if (objs == no_obj)
		return (FALSE);
	preq = find_preq(objs);
	if (!preq)
	{
		if (pushnum(&game->rnd2d.inventory.pocket, objs))
			exit_game(game, EXTRA);
		return (TRUE);
	}
	if (!has_target(game->rnd2d.inventory.pocket, preq))
		return (FALSE);
	if (objs == RUIBAO && !has_target(game->rnd2d.inventory.pocket, HUIBAO))
		return (FALSE);
	pop_target(&game->rnd2d.inventory.pocket, preq);
	if (pushnum(&game->rnd2d.inventory.pocket, objs))
		exit_game(game, EXTRA);
	return (TRUE);
}

void	start_game(t_game *game)
{
	game->set.mouse.on = TRUE;
	game->set.btn.on = TRUE;
	game->set.is_begin = TRUE;
	mlx_mouse_hide();
	display_images(game);
}

t_boolean	collect_pandas(t_game *game)
{
	t_pair_int	map_pos;
	t_objs		obj;

	map_pos = make_pair_int(game->player.pos.x, game->player.pos.y);
	obj = get_num_objs(game->map[map_pos.y][map_pos.x]);
	if (obj && get_objs(game, obj))
	{
		printf("%s gotten\n", numstr(obj));
		game->map[map_pos.y][map_pos.x] = '0';
		game->rnd2d.minimap.map[map_pos.y + 5][map_pos.x + 5] = '0';
		game->rnd2d.script.scene_num = obj;
		return (TRUE);
	}
	return (FALSE);
}

void	end_game(t_game *game)
{
	size_t		len;
	t_pair_int	pos;

	len = ft_strlen("game clear");
	pos = make_pair_int(SCREEN_W - len / 2, SCREEN_H - len / 2);
	game->set.is_ending = TRUE;
	mlx_clear_window(game->mlx, game->win);
	if (game->rnd2d.script.scene_num == OUTRO)
		mlx_string_put(game->mlx, game->win, \
		pos.x, pos.y, FONT_LIGHT, "game clear");
	else
		mlx_string_put(game->mlx, game->win, \
		pos.x, pos.y, FONT_LIGHT, "game over");
	game->rnd2d.script.scene_num = 0;
}

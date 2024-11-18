/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:23:49 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/13 12:06:32 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	display_2ds(t_rnd2d *info)
{
	display_minimap(&info->minimap, *(info->mlx), *(info->win));
	display_inventory(&info->inventory, *(info->mlx), *(info->win));
}

void	display_images(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	display_3ds(game);
	display_2ds(&game->rnd2d);
	if (display_game_clock(&game->set.start_time, game->mlx, game->win))
	{
		game->set.game_over = TRUE;
		game->rnd2d.script.scene_num = GAME_OVER;
		end_game(game);
	}
}

void	display_startscreen(t_game *game)
{
	t_canvas	img;

	mlx_clear_window(game->mlx, game->win);
	img = game->rnd2d.startbg;
	mlx_put_image_to_window(game->mlx, game->win, img.img, 0, 0);
}

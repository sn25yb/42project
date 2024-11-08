/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:23:49 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/08 15:31:44 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_2ds(t_rnd2d *info)
{
	display_minimap(&info->minimap, *(info->mlx), *(info->win));
	display_inventory(&info->inventory, *(info->mlx), *(info->win));
}

void	display_images(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	display_3dmap(game);
	display_2ds(&game->rnd2d);
	if (display_game_clock(&game->set.start_time, game->mlx, game->win))
	{
		game->set.game_over = TRUE;
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

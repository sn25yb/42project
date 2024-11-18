/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rnd3d_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:23:42 by yubshin           #+#    #+#             */
/*   Updated: 2024/11/13 12:06:59 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d/cub3d.h"

void	display_3ds(t_game *game)
{
	update_rnd3d_view(&game->rnd3d, game->player);
	update_anim(&game->rnd3d.tex3d.anim, game->rnd3d.view.pos, game->map);
	rnd_ceilfloor(&game->rnd3d.tex3d.display, \
		game->rnd3d.tex3d.ceil, game->rnd3d.tex3d.floor);
	rnd3d_wall(&game->rnd3d, game->map);
	rnd3d_door(&game->rnd3d, game->map);
	rnd_obj(&game->rnd3d, game->map);
	mlx_put_image_to_window(game->mlx, game->win, \
		game->rnd3d.tex3d.display.img, 0, 0);
}

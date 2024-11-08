/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:25:57 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/01 13:21:41 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_window(t_game *game)
{
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	game->win = NULL;
}

void	free_rnd2d(t_rnd2d *rnd, void *mlx)
{
	free_inventory(&rnd->inventory, mlx);
	free_script(&rnd->script, mlx);
	free_canvas(&rnd->startbg, mlx);
	free_2dmap(&rnd->minimap, mlx);
}

void	free_rnd3d(t_rnd3d *rnd, void *mlx)
{
	int	idx;

	idx = 0;
	free_tex3d(&rnd->tex3d, mlx);
	while (idx < N_WALL)
		free(rnd->texfile[idx++]);
}

void	free_game(t_game *game)
{
	free_huibao(&game->hui);
	free_array(game->map);
	free_rnd2d(&game->rnd2d, game->mlx);
	free_rnd3d(&game->rnd3d, game->mlx);
	free_window(game);
}

void	exit_game(t_game *game, int code)
{
	print_msg(code);
	free_game(game);
	if (code)
		code = 1;
	exit(code);
}

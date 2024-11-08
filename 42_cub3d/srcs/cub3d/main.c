/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:25:27 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/08 15:20:36 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_game(game, EXTRA);
	game->win = mlx_new_window(game->mlx, SCREEN_W, SCREEN_H, "baobao");
	if (!game->win)
		exit_game(game, EXTRA);
}

// void	leak(void)
// {
// 	system("leaks baobao");
// }

int	main(int argc, char *argv[])
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	check_valid(&game, argc, argv);
	init(&game);
	add(&game, argv[1]);
	display_startscreen(&game);
	mlx_hook(game.win, KEY_PRESS, 0, &event_wt_user, &game);
	mlx_hook(game.win, MOUSE_MOVE, 0, &mouse_motion, &game);
	mlx_hook(game.win, DESTROY_NOTIFY, 0, &destroy_game, &game);
	mlx_loop_hook(game.mlx, &display_images_hook, &game);
	mlx_loop(game.mlx);
}

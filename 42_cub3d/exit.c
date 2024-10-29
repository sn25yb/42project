/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:25:57 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/26 23:58:29 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_msg(int code)
{
	if (!code)
		return ;
	ft_putstr_fd("ERROR: ", STDERR_FILENO);
	if (code == ARG_FAILED)
		ft_putendl_fd(MSG_ARG_FAILED, STDERR_FILENO);
	else if (code == MAP_FAILED)
		ft_putendl_fd(MSG_MAP_FAILED, STDERR_FILENO);
	else
		perror("");
}

void	free_2dimage(t_img2d *img, void *mlx)
{
	if (!mlx)
		return ;
	if (img->image)
		mlx_destroy_image(mlx, img->image);
	ft_memset(img, 0, sizeof(t_img2d));
}

void	free_images(t_map2d *map, void *mlx)
{
	int	index;

	free_2dimage(&map->wall, mlx);
	free_2dimage(&map->empty, mlx);
	free_2dimage(&map->way, mlx);
	free_2dimage(&map->door[0], mlx);
	free_2dimage(&map->door[1], mlx);
	// free_2dimage(&imgs->start, mlx);
	// free_2dimage(&imgs->logo, mlx);
	free_2dimage(&map->target, mlx);
	index = 0;
	while (index < 11)
		free_2dimage(&map->object[index++], mlx);
}

void	free_2dmap(t_map2d *map, void *mlx)
{
	free_array(map->map);
	free_images(map, mlx);
	ft_memset(map, 0, sizeof(t_map2d));
}

void	free_inventory(t_inventory *inv, void *mlx)
{
	free_queue(inv->pocket.head);
	free_2dimage(&inv->img, mlx);
	ft_memset(inv, 0, sizeof(t_inventory));
}

void	free_window(t_game *game)
{
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	game->win = NULL;
}

void	free_script(t_script *script, void *mlx)
{
	free_2dimage(&script->chat, mlx);
	free_array(script->lines);
	ft_memset(script, 0, sizeof(t_script));
}

void	free_rnd2d(t_rnd2d *rnd, void *mlx)
{
	free_inventory(&rnd->inventory, mlx);
	free_script(&rnd->script, mlx);
	free_2dimage(&rnd->startbg, mlx);
	free_2dmap(&rnd->minimap, mlx);
}

void	free_game(t_game *game)
{
	int	i;

	free_array(game->map);
	free_rnd2d(&game->rnd2d, game->mlx);
	free_window(game);
	i = 0;
	while (i < 4)
		free(game->rnd.texfile[i++]);
	free(game->mlx);
}

void	exit_game(t_game *game, int code)
{
	print_msg(code);
	free_game(game);
	if (code)
		code = 1;
	exit(code);
}

int	destroy_game(t_game *game)
{
	exit_game(game, EXIT_SUCCESS);
	return (0);
}

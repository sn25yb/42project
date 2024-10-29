/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:34:56 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/27 00:31:29 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_err	add_info(t_game *game, int fd)
{
	int		cnt;
	char	*line;
	int		code;

	cnt = 0;
	code = EXIT_SUCCESS;
	while (cnt < 6)
	{
		line = get_next_line(fd);
		if (!line)
			return (MAP_FAILED);
		code = add_line(game, &line);
		if (!code)
			cnt++;
		free(line);
		if (code == MAP_FAILED || code == EXTRA)
			break ;
	}
	return (code);
}

void	add_player(t_game *game)
{
	t_pair_int		xy;
	char			*target;

	xy.y = 0;
	while (game->map[xy.y])
	{
		target = ft_strchrset(game->map[xy.y], "EWSN");
		if (target)
		{
			xy.x = target - game->map[xy.y];
			game->player.pos = make_pair_dbl(xy.x, xy.y);
			game->player.dir = dir_to_coord(game->map[xy.y][xy.x]);
			game->player.rad = cal_radian(game->player.dir);
			game->map[xy.y][xy.x] = '0';
			return ;
		}
		xy.y++;
	}
}

int	add_player2d(t_star *p_info, t_player src, void *mlx)
{
	t_img2d	*conv;

	p_info->dir = make_pair_int(src.dir.x, src.dir.y);
	p_info->pos = make_pair_int(src.pos.x, src.pos.y);
	if (get_image(mlx, &p_info->player, "./textures/2d/player.xpm"))
		return (IMG_FAILED);
	conv = &p_info->player_conv;
	*conv = p_info->player;
	conv->image = mlx_new_image(mlx, conv->size.x, conv->size.y);
	if (!conv->image)
		return (EXTRA);
	conv->addr = (unsigned int *)mlx_get_data_addr(conv->image, \
	&conv->bpp, &conv->size_l, &conv->endian);
	return (EXIT_SUCCESS);
}

int	add_script(t_script *script, void *mlx)
{
	script->scene_num = INTRO;
	return (get_image(mlx, &script->chat, SCRIPT_IMG));
}

int	add_rnd2d(t_game *game)
{
	int	code;

	game->rnd2d.minimap.mlx = game->mlx;
	game->rnd2d.minimap.win = game->win;
	code = add_player2d(&game->rnd2d.minimap.player, game->player, game->mlx);
	if (!code)
		code = add_minimap(&game->rnd2d.minimap, game->map);
	if (!code)
		code = add_inventory2d(&game->rnd2d.inventory, game->mlx);
	if (!code)
		code = get_image(game->mlx, &game->rnd2d.startbg, "./textures/2d/startbg.xpm");
	if (!code)
		code = add_script(&game->rnd2d.script, game->mlx);
	return (code);
}

t_err	add_map(t_game *game, int fd)
{
	char	*line;
	char	*gnl;
	char	*temp;
	int		code;

	line = NULL;
	while (!set_next_line(&gnl, fd))
	{
		if (!line)
			line = gnl;
		else
		{
			temp = ft_strjoin(line, gnl);
			free(line);
			free(gnl);
			if (!temp)
				return (EXTRA);
			line = temp;
		}
	}
	code = set_map(game, line);
	free(line);
	if (!code)
		return (check_validmap(game->map, &game->player.pos));
	return (code);
}

void	add(t_game *game, char *file)
{
	int		fd;
	int		cnt;
	int		code;

	fd = open(file, O_RDONLY);
	cnt = 0;
	if (fd == -1)
		exit_game(game, EXTRA);
	code = add_info(game, fd);
	if (!code)
		code = add_map(game, fd);
	close(fd);
	add_player(game);
	if (!code)
		code = add_rnd2d(game);
	if (code)
		exit_game(game, code);
	add_imgs3d(game);
}

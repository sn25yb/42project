/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:34:56 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/12 10:07:13 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	code = set_map(&game->map, line);
	free(line);
	return (code);
}

t_err	add_info(t_game *game, char *file)
{
	int		cnt;
	char	*line;
	int		code;
	int		fd;

	cnt = 0;
	fd = 0;
	code = EXIT_SUCCESS;
	while (cnt < 6 && !code)
	{
		if (read_next_line(file, &line, &fd) || !line)
			return (MAP_FAILED);
		code = add_line(game, &line, &cnt);
		free(line);
	}
	if (code)
		return (code);
	return (add_map(game, fd));
}

void	add_player(t_view *player, char ***map_ptr)
{
	t_pair_int		xy;
	char			*target;
	char			**map;

	xy.y = 0;
	map = *map_ptr;
	while (map[xy.y])
	{
		target = ft_strchrset(map[xy.y], "EWSN");
		if (target)
		{
			xy.x = (int)(target - map[xy.y]);
			player->pos = make_pair_dbl(xy.x, xy.y);
			player->map_pos = xy;
			player->dir = dir_to_coord(map[xy.y][xy.x]);
			player->rad = cal_radian(player->dir);
			map[xy.y][xy.x] = '0';
			*map_ptr = map;
			return ;
		}
		xy.y++;
	}
}

int	add_rnd2d(t_game *game)
{
	int	code;

	game->rnd2d.mlx = &game->mlx;
	game->rnd2d.win = &game->win;
	game->rnd2d.minimap.player = &game->player;
	code = add_minimap(&game->rnd2d.minimap, &game->map, game->mlx);
	if (!code)
		code = add_inventoryimg(&game->rnd2d.inventory, game->mlx);
	if (!code)
		code = get_canvas(game->mlx, \
		&game->rnd2d.startbg, "./texture/2d/startbg.xpm");
	if (!code)
		code = add_msgbox(&game->rnd2d.script, game->mlx);
	if (!code)
		code = add_profile(&game->rnd2d.script, game->mlx);
	return (code);
}

void	add(t_game *game, char *file)
{
	int		code;

	code = add_info(game, file);
	if (!code)
		code = check_validmap(game->map);
	if (!code)
		add_player(&game->player, &game->map);
	if (!code)
		code = add_huibao(&game->hui, game->map);
	if (!code)
		code = add_rnd2d(game);
	if (!code)
		code = add_tex3d(game);
	if (code)
		exit_game(game, code);
}

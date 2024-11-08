/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex3d_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:45:27 by yubshin           #+#    #+#             */
/*   Updated: 2024/11/08 16:46:06 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d/cub3d.h"

static int	add_tex3d_wall(t_tex3d *tex3d, char **filenames, void *mlx);
static int	add_tex3d_obj(t_tex3d *tex3d, void *mlx);
static int	add_tex3d_door(t_tex3d *tex3d, void *mlx);

int	add_tex3d(t_game *game)
{
	int		code;
	void	*mlx;

	mlx = game->mlx;
	game->rnd3d.tex3d.bsize.x = 32;
	game->rnd3d.tex3d.bsize.y = 32;
	code = add_tex3d_wall(&game->rnd3d.tex3d, game->rnd3d.texfile, mlx);
	if (!code)
		code = add_tex3d_obj(&game->rnd3d.tex3d, mlx);
	if (!code)
		code = add_tex3d_door(&game->rnd3d.tex3d, mlx);
	if (!code)
		code = new_canvas(&game->rnd3d.tex3d.display, mlx, SCREEN_W, SCREEN_H);
	if (!code)
		add_anim(&game->rnd3d.tex3d.anim, game->map);
	return (code);
}

static int	add_tex3d_wall(t_tex3d *tex3d, char **filenames, void *mlx)
{
	int	idx;
	int	code;

	code = EXIT_SUCCESS;
	idx = 0;
	while (idx < N_WALL && code == EXIT_SUCCESS)
	{
		if (code == EXIT_SUCCESS)
			code = get_canvas(mlx, &tex3d->wall[idx], filenames[idx]);
		idx++;
	}
	return (code);
}

static int	add_tex3d_obj(t_tex3d *tex3d, void *mlx)
{
	int			code;
	int			fd;
	t_pair_int	idx;
	char		*file;

	code = EXIT_SUCCESS;
	fd = 0;
	idx.y = 0;
	while (idx.y < N_OBJ)
	{
		idx.x = 0;
		while (idx.x < N_ANIM && code == EXIT_SUCCESS)
		{
			code = read_next_line("./texture/texlst/3d_objlst", &file, &fd);
			if (code == EXIT_SUCCESS)
				code = get_canvas(mlx, &tex3d->obj[idx.y][idx.x], file);
			free(file);
			idx.x++;
		}
		idx.y++;
	}
	if (fd > 0)
		close(fd);
	return (code);
}

static int	add_tex3d_door(t_tex3d *tex3d, void *mlx)
{
	int			code;
	int			fd;
	t_pair_int	idx;
	char		*file;

	code = EXIT_SUCCESS;
	fd = 0;
	idx.y = 0;
	while (idx.y < N_DOOR)
	{
		idx.x = 0;
		while (idx.x < N_ANIM && code == EXIT_SUCCESS)
		{
			code = read_next_line("./texture/texlst/3d_doorlst", &file, &fd);
			if (code == EXIT_SUCCESS)
				code = get_canvas(mlx, &tex3d->door[idx.y][idx.x], file);
			free(file);
			idx.x++;
		}
		idx.y++;
	}
	if (fd > 0)
		close(fd);
	return (code);
}

void	free_tex3d(t_tex3d *tex3d, void *mlx)
{
	t_pair_int	idx;

	idx.y = 0;
	while (idx.y < N_WALL)
		free_canvas(&tex3d->wall[idx.y++], mlx);
	idx.y = 0;
	while (idx.y < N_OBJ)
	{
		idx.x = 0;
		while (idx.x < N_ANIM)
			free_canvas(&tex3d->obj[idx.y][idx.x++], mlx);
		idx.y++;
	}
	idx.y = 0;
	while (idx.x < N_DOOR)
	{
		idx.x = 0;
		while (idx.x < N_ANIM)
			free_canvas(&tex3d->door[idx.y][idx.x++], mlx);
		idx.y++;
	}
	free_canvas(&tex3d->display, mlx);
	free_anim(&tex3d->anim);
}

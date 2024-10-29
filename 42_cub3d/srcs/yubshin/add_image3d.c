#include "../../cub3d.h"

void	get_new_canvas(t_canvas_3d *new, void *mlx)
{
	new->size.x = 32;
	new->size.y = 32;
	new->animation = 0;
	new->img = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	new->addr = (unsigned int *)mlx_get_data_addr(new->img, &new->bpp, &new->size_l, &new->endian);
}

int	get_3d_canvas(t_canvas_3d *new, char *filename, void *mlx)
{
	new->size.x = 32;
	new->size.y = 32;
	new->img = mlx_xpm_file_to_image(mlx, filename, &new->size.x, &new->size.y);
	if (!new->img)
		return (IMG_FAILED);
	new->addr = (unsigned int *)ft_calloc(new->size.x * new->size.y, sizeof(int));
	new->addr = (unsigned int *)mlx_get_data_addr(new->img, &new->bpp, &new->size_l, &new->endian);
	return (EXIT_SUCCESS);
}

int	add_3d_wall(t_game *game, t_tex3d *tex3d, char **filenames)
{
	int	idx;
	int	code;

	idx = 0;
	code = EXIT_SUCCESS;
	while (idx < N_WALL)
	{
		if (get_3d_canvas(&tex3d->wall[idx], filenames[idx], game->mlx))
			code = IMG_FAILED;
		idx++;
	}
	return (code);
}

int	add_3d_object(t_tex3d *tex3d, void *mlx)
{
	char	*file;
	t_pair_int idx;
	int		fd;
	int		code;
	
	fd = 0;
	idx.y = 0;
	code = EXIT_SUCCESS;
	while (idx.y < N_OBJECT)
	{
		idx.x = 0;
		while (idx.x < N_ANIMATION)
		{
			if (read_next_line("./textures/imglst/3d_object", &file, &fd))
				code = EXTRA;
			if (!code && (!file || get_3d_canvas(&tex3d->object[idx.y][idx.x], file, mlx)))
				code = IMG_FAILED;
			free(file);
			idx.x++;
		}
		idx.y++;
	}
	if (fd > 0)
		close(fd);
	return (code);
}

int	add_3d_door(t_tex3d *tex3d, void *mlx)
{
	char	*file;
	t_pair_int idx;
	int		fd;
	int		code;
	
	fd = 0;
	idx.y = 0;
	code = EXIT_SUCCESS;
	while (idx.y < N_DOOR)
	{
		idx.x = 0;
		while (idx.x < N_ANIMATION)
		{
			if (read_next_line("./textures/imglst/3d_door", &file, &fd))
				code = EXTRA;
			if (!code && (!file || get_3d_canvas(&tex3d->door[idx.y][idx.x], file, mlx)))
				code = IMG_FAILED;
			free(file);
			idx.x++;
		}
		idx.y++;
	}
	if (fd > 0)
		close(fd);
	return (code);
}

void	add_imgs3d(t_game *game)
{
	game->rnd.tex3d.widtheight.x = 32;
	game->rnd.tex3d.widtheight.y = 32;
	add_3d_wall(game, &game->rnd.tex3d, game->rnd.texfile);
	add_3d_object(&game->rnd.tex3d, game->mlx);
	add_3d_door(&game->rnd.tex3d, game->mlx);
	get_new_canvas(&game->rnd.tex3d.display, game->mlx);
}
#include "../../cub3d.h"

void	add_3d_wall(t_game *game, t_tex3d *tex3d)
{
	int			w;
	int			h;
	int			idx;

	w = game->rnd.tex3d.widtheight.x;
	h = game->rnd.tex3d.widtheight.y;
	tex3d->wall[I_EAST].img = mlx_xpm_file_to_image(game->mlx, game->rnd.texfile[I_EAST], &w, &h);
	tex3d->wall[I_WEST].img = mlx_xpm_file_to_image(game->mlx, game->rnd.texfile[I_WEST], &w, &h);
	tex3d->wall[I_SOUTH].img = mlx_xpm_file_to_image(game->mlx, game->rnd.texfile[I_SOUTH], &w, &h);
	tex3d->wall[I_NORTH].img = mlx_xpm_file_to_image(game->mlx, game->rnd.texfile[I_NORTH], &w, &h);
	idx = 0;
	while (idx < N_WALL)
	{
		if (!tex3d->wall[idx].img)
			exit_game(game, IMG_FAILED);
		idx++;
	}
}

void	add_3d_object(t_game *game, t_tex3d *tex3d)
{
	int			w;
	int			h;
	int			idx;

	w = game->rnd.tex3d.widtheight.x;
	h = game->rnd.tex3d.widtheight.y;
	tex3d->object[I_AIBAO][0].img = mlx_xpm_file_to_image(game->mlx, "textures/3d/aibao.xpm", &w, &h);
	tex3d->object[I_LEBAO][0].img = mlx_xpm_file_to_image(game->mlx, "textures/3d/lebao.xpm", &w, &h);
	tex3d->object[I_FUBAO][0].img = mlx_xpm_file_to_image(game->mlx, "textures/3d/fubao.xpm", &w, &h);
	tex3d->object[I_RUIBAO][0].img = mlx_xpm_file_to_image(game->mlx, "textures/3d/ruibao.xpm", &w, &h);
	tex3d->object[I_HUIBAO][0].img = mlx_xpm_file_to_image(game->mlx, "textures/3d/huibao.xpm", &w, &h);
	tex3d->object[I_BOOTS][0].img = mlx_xpm_file_to_image(game->mlx, "textures/3d/boots.xpm", &w, &h);
	tex3d->object[I_CARROT][0].img = mlx_xpm_file_to_image(game->mlx, "textures/3d/carrot.xpm", &w, &h);
	tex3d->object[I_KANG][0].img = mlx_xpm_file_to_image(game->mlx, "textures/3d/kangbao.xpm", &w, &h);
	tex3d->object[I_WOTOU][0].img = mlx_xpm_file_to_image(game->mlx, "textures/3d/wotou.xpm", &w, &h);
	idx = 0;
	while (idx < N_OBJECT)
	{
		if (!tex3d->object[idx][0].img)
			exit_game(game, IMG_FAILED);
		idx++;
	}
}

void	add_3d_door(t_game *game, t_tex3d *tex3d)
{
	int			w;
	int			h;
	int			idx;

	w = game->rnd.tex3d.widtheight.x;
	h = game->rnd.tex3d.widtheight.y;
	tex3d->door[0].img = mlx_xpm_file_to_image(game->mlx, "textures/3d/door.xpm", &w, &h);
	tex3d->door[1].img = mlx_xpm_file_to_image(game->mlx, "textures/3d/door.xpm", &w, &h);
	idx = 0;
	while (idx < N_DOOR)
	{
		if (!tex3d->door[idx].img)
			exit_game(game, IMG_FAILED);
		idx++;
	}
}

void	init_3d(t_tex3d *tex3d)
{
	int idx;

	tex3d->object = (t_canvas_3d **)ft_calloc(N_OBJECT, sizeof(t_canvas_3d *));
	idx = 0;
	while (idx < N_OBJECT)
		tex3d->object[idx++] = (t_canvas_3d *)ft_calloc(N_SPRITE, sizeof(t_canvas_3d));
	tex3d->wall = (t_canvas_3d *)ft_calloc(N_WALL, sizeof(t_canvas_3d ));
	tex3d->door = (t_canvas_3d *)ft_calloc(N_DOOR, sizeof(t_canvas_3d ));
}

void	add_imgs3d(t_game *game)
{
	init_3d(&game->rnd.tex3d);
	add_3d_wall(game, &game->rnd.tex3d);
	add_3d_object(game, &game->rnd.tex3d);
	add_3d_door(game, &game->rnd.tex3d);
}
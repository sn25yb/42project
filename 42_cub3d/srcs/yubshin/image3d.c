#include "../../cub3d.h"

void	add_image_character(t_game *game)
{
	t_pair_int	imgsize;
	int			index;

	imgsize.x = game->texture.info.imgsize.x;
	imgsize.y = game->texture.info.imgsize.y;
	game->image.character[0][0] = mlx_xpm_file_to_image(game->mlx, "textures/3d/ruibao.xpm", &imgsize.x, &imgsize.y);
	game->image.character[1][0] = mlx_xpm_file_to_image(game->mlx, "textures/3d/huibao.xpm", &imgsize.x, &imgsize.y);
	game->image.character[2][0] = mlx_xpm_file_to_image(game->mlx, "textures/3d/fubao.xpm", &imgsize.x, &imgsize.y);
	game->image.character[3][0] = mlx_xpm_file_to_image(game->mlx, "textures/3d/aibao.xpm", &imgsize.x, &imgsize.y);
	game->image.character[4][0] = mlx_xpm_file_to_image(game->mlx, "textures/3d/lebao.xpm", &imgsize.x, &imgsize.y);
	index = 0;
	while (index < NUMS_CHARACTER)
	{
		if (!game->image.character[index][0])
			exit_game(game, IMG_FAILED);
		index++;
	}

}

void	add_image_object(t_game *game)
{
	t_pair_int	imgsize;
	int			index;

	imgsize.x = game->texture.info.imgsize.x;
	imgsize.y = game->texture.info.imgsize.y;
	game->image.object[0] = mlx_xpm_file_to_image(game->mlx, "textures/3d/wotou.xpm", &imgsize.x, &imgsize.y);
	game->image.object[1] = mlx_xpm_file_to_image(game->mlx, "textures/3d/boots.xpm", &imgsize.x, &imgsize.y);
	game->image.object[2] = mlx_xpm_file_to_image(game->mlx, "textures/3d/carrot.xpm", &imgsize.x, &imgsize.y);
	game->image.object[3] = mlx_xpm_file_to_image(game->mlx, "textures/3d/kangbao.xpm", &imgsize.x, &imgsize.y);
	index = 0;
	while (index < NUMS_OBJECT)
	{
		if (!game->image.object[index])
			exit_game(game, IMG_FAILED);
		index++;
	}
}

void	add_image_wall(t_game *game)
{
	t_pair_int	imgsize;
	int			index;

	imgsize.x = game->texture.info.imgsize.x;
	imgsize.y = game->texture.info.imgsize.y;
	game->image.wall[0] = mlx_xpm_file_to_image(game->mlx, "textures/3d/north.xpm", &imgsize.x, &imgsize.y);
	game->image.wall[1] = mlx_xpm_file_to_image(game->mlx, "textures/3d/south.xpm", &imgsize.x, &imgsize.y);
	game->image.wall[2] = mlx_xpm_file_to_image(game->mlx, "textures/3d/east.xpm", &imgsize.x, &imgsize.y);
	game->image.wall[3] = mlx_xpm_file_to_image(game->mlx, "textures/3d/west.xpm", &imgsize.x, &imgsize.y);
	index = 0;
	while (index < NUMS_WALL)
	{
		if (!game->image.wall[index])
			exit_game(game, IMG_FAILED);
		index++;
	}
}

void	add_image_door(t_game *game)
{
	t_pair_int	imgsize;
	int			index;

	imgsize.x = game->texture.info.imgsize.x;
	imgsize.y = game->texture.info.imgsize.y;
	game->image.door[0] = mlx_xpm_file_to_image(game->mlx, "textures/3d/door.xpm", &imgsize.x, &imgsize.y);
	index = 0;
	while (index < NUMS_DOOR)
	{
		if (!game->image.door[index])
			exit_game(game, IMG_FAILED);
		index++;
	}
}

void	add_image(t_game *game)
{
	add_image_character(game);
	add_image_object(game);
	add_image_wall(game);
	add_image_door(game);
}
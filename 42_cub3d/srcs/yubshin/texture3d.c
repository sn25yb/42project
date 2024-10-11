#include "../cub3d.h"

void	set_texture(int **texture, void *image, t_image_info info)
{
	int			*addr;
	t_pair_int	pair;

	addr = (int *)mlx_get_data_addr(image, &info.bpp, &info.size_l, &info.endian);
	pair.x = 0;
	while (pair.x < info.imgsize)
	{
		pair.y = 0;
		while (pair.y < info.imgsize)
		{
			printf("%d, %d\n", pair.x, pair.y);
			(*texture)[info.imgsize * pair.y + pair.x] = addr[info.imgsize * pair.y + pair.x];
			pair.y++;
		}
		pair.x++;
	}
}

void	set_textures(t_image image, t_texture *texture)
{
	t_pair_int idx;

	idx.x = 0;
	while (idx.x < NUMS_CHARACTER && image.character[idx.x])
	{
		idx.y = 0;
		while (idx.y < NUMS_SPRITE && image.character[idx.x][idx.y])
		{
			set_texture(&texture->character[idx.x][idx.y], image.character[idx.x][idx.y], texture->info);
			idx.y++;
		}
		idx.x++;
	}
	idx.x = 0;
	while (idx.x < NUMS_OBJECT && image.object[idx.x])
	{
		set_texture(&texture->object[idx.x], image.object[idx.x], texture->info);
		idx.x++;
	}
	idx.x = 0;
	while (idx.x < NUMS_SPRITE && image.wall[idx.x])
	{
		set_texture(&texture->wall[idx.x], image.wall[idx.x], texture->info);
		idx.x++;
	}
	idx.x = 0;
	while (idx.x < NUMS_SPRITE && image.door[idx.x])
	{
		set_texture(&texture->door[idx.x], image.door[idx.x], texture->info);
		idx.x++;
	}
}

void	calloc_textures(t_texture *texture)
{
	t_pair_int idx;

	texture->character = (int ***)ft_calloc(5, sizeof(int **));
	idx.x = 0;
	while (idx.x < NUMS_CHARACTER)
	{
		texture->character[idx.x] = (int **)ft_calloc(4, sizeof(int *));
		idx.y = 0;
		while (idx.y < NUMS_SPRITE)
			texture->character[idx.x][idx.y++] = (int *)ft_calloc(texture->info.imgsize.x * texture->info.imgsize.y, sizeof(int));
		idx.x++;
	}
	texture->object = (int **)ft_calloc(NUMS_OBJECT, sizeof(int *));
	idx.x = 0;
	while (idx.x < NUMS_OBJECT)
		texture->object[idx.x++] = (int *)ft_calloc(texture->info.imgsize.x * texture->info.imgsize.y, sizeof(int));
	texture->wall = (int **)ft_calloc(NUMS_WALL, sizeof(int *));
	idx.x = 0;
	while (idx.x < NUMS_WALL)
		texture->wall[idx.x++] = (int *)ft_calloc(texture->info.imgsize.x * texture->info.imgsize.y, sizeof(int));
	texture->door = (int **)ft_calloc(NUMS_DOOR, sizeof(int *));
	idx.x = 0;
	while (idx.x < NUMS_DOOR)
		texture->door[idx.x++] = (int *)ft_calloc(texture->info.imgsize.x * texture->info.imgsize.y, sizeof(int));
}

void	init_texture(t_image image, t_texture *texture)
{
	texture->info.imgsize.x = 32;
	texture->info.imgsize.y = 32;
	texture->info.bpp = 1;
	texture->info.size_l = 1;
	texture->info.endian = 1;
	calloc_textures(texture);
	set_textures(image, texture);
}

// void	draw_texture(t_texture texture, void *mlx_ptr, void *win_ptr, t)
// {
// 	int x = 0;
// 	int y = 0;
// 	int y2 = y;
// 	int len_x = x + texture.info.imgsize;
// 	int len_y = y + texture.info.imgsize + 500;
// 	while (x < len_x)
// 	{
// 		y = y2;
// 		while (y < len_y)
// 		{
// 			unsigned int color = texture.character[0][0][texture.info.imgsize * y + x];
// 			mlx_pixel_put(mlx_ptr, win_ptr, x, y, (int)color);
// 			y++;
// 		}
// 		x++;
// 	}


// }



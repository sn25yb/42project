#include "image2d.h"

int	get_image(void *mlx, t_img2d *img, char *filename)
{
	img->image = mlx_xpm_file_to_image(mlx, \
	filename, &img->size.x, &img->size.y);
	if (!img->image)
		return (IMG_FAILED);
	img->addr = (unsigned int *)mlx_get_data_addr(img->image, &img->bpp, \
	&img->size_l, &img->endian);
	return (EXIT_SUCCESS);
}
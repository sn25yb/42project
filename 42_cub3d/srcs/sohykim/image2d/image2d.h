#ifndef IMAGE2D_H
# define IMAGE2D_H
# include "libft/base/lib.h"
# include "libft/base/pair.h"
# include "libft/ft_err.h"
# include "mlx/mlx.h"

typedef struct s_img2d
{
	void			*image;
	unsigned int	*addr;
	int				bpp;
	int				endian;
	int				size_l;
	t_pair_int		size;
}	t_img2d;

int	get_image(void *mlx, t_img2d *img, char *filename);

# endif

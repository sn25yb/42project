/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:06:00 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/11 16:55:40 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../canvas/canvas.h"

int	get_canvas(void *mlx, t_canvas *img, char *file)
{
	if (!file)
		return (IMG_FAILED);
	img->img = mlx_xpm_file_to_image(mlx, file, &img->size.x, &img->size.y);
	if (!img->img)
		return (IMG_FAILED);
	img->addr = (unsigned int *)mlx_get_data_addr(img->img, \
		&img->bpp, &img->size_l, &img->endian);
	return (EXIT_SUCCESS);
}

int	new_canvas(t_canvas *new, void *mlx, int width, int height)
{
	new->size.x = width;
	new->size.y = height;
	new->img = mlx_new_image(mlx, width, height);
	if (new->img == NULL)
		return (IMG_FAILED);
	new->addr = (unsigned int *)mlx_get_data_addr(new->img, \
		&new->bpp, &new->size_l, &new->endian);
	return (EXIT_SUCCESS);
}

void	free_canvas(t_canvas *img, void *mlx)
{
	if (!mlx)
		return ;
	if (img->img)
		mlx_destroy_image(mlx, img->img);
	ft_memset(img, 0, sizeof(t_canvas));
}

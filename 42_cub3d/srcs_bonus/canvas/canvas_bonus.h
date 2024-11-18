/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:13:55 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/01 12:53:08 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_BONUS_H
# define CANVAS_BONUS_H

# include "libft/base/pair.h"
# include "libft/error/ft_err.h"
# include "mlx/mlx.h"
# include "libft/libft/libft.h"

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
	int	flag;
}	t_rgb;

typedef struct s_canvas
{
	t_pair_int		size;
	void			*img;
	unsigned int	*addr;
	int				bpp;
	int				size_l;
	int				endian;
}	t_canvas;

//canvas.c
int		get_canvas(void *mlx, t_canvas *canvas, char *filename);
int		new_canvas(t_canvas *new, void *mlx, int width, int height);
void	free_canvas(t_canvas *canvas, void *mlx);

//canvas_rgb.c
t_err	check_rgbnum(int num, char *str);
int		rgb_to_int(int red, int green, int blue);
int		blur_rgb(t_rgb rgb, double blur_level, int blur_color);

#endif

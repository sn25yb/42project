/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:25:56 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/08 16:45:48 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP2D_H
# define MAP2D_H

# include <stdio.h>
# include <fcntl.h>
# include "libft/queue/queue.h"
# include "libft/libft/libft.h"
# include "libft/base/lib.h"
# include "libft/libgnl/get_next_line.h"
# include "libft/base/pair.h"
# include "libft/error/ft_err.h"
# include "mlx/mlx.h"
# include "../canvas/canvas.h"
# include "srcs/inventory/inventory.h"
# include "srcs/view/view.h"
# define MAP2D_WIDTH 11
# define MAP2D_HEIGHT 11
# define WAY_COLOR 0xFCF9D4

typedef struct s_imgs2d
{
	t_canvas		wall;
	t_canvas		empty;
	t_canvas		way;
	t_canvas		door[2];
	t_canvas		target;
	t_canvas		player;
	t_canvas		player_conv;
}	t_imgs2d;

typedef struct s_map2d
{
	char		**map;
	t_view		*player;
	t_imgs2d	imgs;
	char		***src;
}	t_map2d;

int			get_canvas(void *mlx, t_canvas *canvas, char *filename);
int			add_minimap(t_map2d *map, char ***src, void *mlx);
char		**make_array(int h, int w);
t_pair_int	get_maxsize(char **src);
t_canvas	select_image(char *what, t_imgs2d imgs);
void		display_minimap(t_map2d *info, void *mlx, void *win);
void		draw_playerbg(t_canvas *ret);
void		draw_playerimg(t_canvas *ret, t_canvas src, double rad);
void		draw_minimap(t_map2d *map, char **src, t_pair_int size);
void		free_2dmap(t_map2d *map, void *mlx);

#endif

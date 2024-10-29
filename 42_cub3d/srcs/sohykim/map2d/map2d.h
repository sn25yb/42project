/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:25:56 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/24 14:27:23 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MAP2D_H
# define MAP2D_H
# include "../../../libft/queue/queue.h"
# include "../../../libft/libft/libft.h"
# include "../../../libft/base/lib.h"
# include "../../../libft/libgnl/get_next_line.h"
# include "../../../libft/base/pair.h"
# include "../../../libft/ft_err.h"
# include "../../../mlx/mlx.h"
# include "../image2d/image2d.h"
# include "../inventory/inventory.h"
# include <stdio.h>
# include <fcntl.h>
// EA 1,0
// WE -1,0
// NO 0, 1
//SO 0, -1

typedef struct s_star
{
	t_pair_int	pos;
	t_pair_int	dir;
	t_img2d		player;
	t_img2d		player_conv;
}	t_star;

typedef struct s_map2d
{
	void		*mlx;
	void		*win;
	char		**map;
	t_star		player;
	t_img2d		wall;
	t_img2d		empty;
	t_img2d		way;
	t_img2d		door[2];
	t_img2d		target;
	t_img2d		object[11];
}	t_map2d;

int	get_image(void *mlx, t_img2d *img, char *filename);
int	add_minimap(t_map2d *map, char **src);

#endif

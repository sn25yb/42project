/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:31:21 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/12 11:02:41 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "libft/base/pair.h"
# include "libft/queue/queue.h"
# include "libft/libft/libft.h"
# include "libft/base/lib.h"
# include "../validation/rule.h"

# include <math.h>
# define EAST 0
# define WEST 1
# define SOUTH 2
# define NORTH 3
# define SCREEN_W 1920 
# define SCREEN_H 1080 

t_pair_dbl	dir_to_coord(int dir);
double		cal_radian(t_pair_dbl dir);
t_pair_int	make_dir(t_pair_int xy, int dir);
int			**make_intarray(t_pair_int size);
int			bfs(t_queues *q, int ***map_ptr, char **src);
t_pair_int	find_obj(char **map, char *c);

#endif

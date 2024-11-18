/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:33:20 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/13 13:59:44 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_H
# define VIEW_H

# include "libft/base/pair.h"
# include "srcs/utils/utils.h"

# include <math.h>

# define KEY_SPACE 49
# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_ENTER 36
# define KEY_ESC 53
# define KEY_ARROW_L 123
# define KEY_ARROW_R 124
# define P_STEP 0.25

typedef struct s_view
{
	t_pair_dbl	pos;
	t_pair_dbl	dir;
	t_pair_int	map_pos;
	t_pair_dbl	plane;
	double		rad;
}	t_view;

void	change_dir(t_view *p, double rad);
void	change_pos(t_view *p, int keycode);
double	cal_mouse_dir(double x);

#endif

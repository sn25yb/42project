/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:23:00 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/30 17:31:41 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

t_pair_dbl	dir_to_coord(int dir)
{
	const double	dr[4] = {0, 0, 1, -1};
	const double	dc[4] = {1, -1, 0, 0};

	if (dir == 'E')
		return (make_pair_dbl(dc[EAST], dr[EAST]));
	else if (dir == 'W')
		return (make_pair_dbl(dc[WEST], dr[WEST]));
	else if (dir == 'S')
		return (make_pair_dbl(dc[SOUTH], dr[SOUTH]));
	else
		return (make_pair_dbl(dc[NORTH], dr[NORTH]));
}

double	cal_radian(t_pair_dbl dir)
{
	double	rad1;
	double	rad2;

	rad1 = acos(dir.x);
	rad2 = asin(dir.y);
	if (dir.x < 0 && dir.y < 0)
	{
		rad1 = M_PI + rad2 * -1;
		rad2 = rad1;
	}
	else if (dir.x >= 0 && dir.y < 0)
	{
		rad2 += M_PI * 2;
		rad1 = rad2;
	}
	else if (dir.x < 0 && dir.y >= 0)
	{
		rad1 = M_PI - rad2;
		rad2 = rad1;
	}
	return (rad1);
}

t_pair_int	make_dir(t_pair_int xy, int dir)
{
	t_pair_int	ret;
	const int	dr[5] = {0, 0, 1, -1};
	const int	dc[5] = {1, -1, 0, 0};	

	ret = make_pair_int(xy.x + dc[dir], xy.y + dr[dir]);
	return (ret);
}

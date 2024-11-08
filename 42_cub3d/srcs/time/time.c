/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:49:19 by yubshin           #+#    #+#             */
/*   Updated: 2024/10/31 13:50:20 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time.h"

long	timeval_to_long(void)
{
	struct timeval	time;
	long			now_sec;
	long			now_usec;

	gettimeofday(&time, NULL);
	now_sec = (long)(time.tv_sec);
	now_usec = (long)(time.tv_usec);
	return (now_sec * 1000000 + now_usec);
}

double	get_timeleft(long pre, long now, double wait)
{
	double	timeleft;
	long	elapsed;

	elapsed = now - pre;
	timeleft = wait * 1000000 - elapsed;
	return (timeleft);
}

int	display_game_clock(long *pre, void *mlx, void *win)
{
	double	timeleft;
	long	now;
	char	*sec;
	char	*line;

	now = timeval_to_long();
	if (!*pre)
		*pre = now;
	timeleft = get_timeleft(*pre, now, TIME_LIMIT);
	if (timeleft < 0)
		return (TIME_PASSED);
	sec = ft_itoa(timeleft / 1000000);
	line = ft_strjoin(sec, "sec");
	mlx_string_put(mlx, win, 100, 100, 0xFFFFFF, line);
	free(sec);
	free(line);
	return (TIME_NPASSED);
}

int	update_anim_clock(long *pre, double wait)
{
	double	timeleft;
	long	now;

	now = timeval_to_long();
	if (!*pre)
		*pre = now;
	timeleft = get_timeleft(*pre, now, wait);
	if (timeleft < 0)
	{
		*pre = now;
		return (TIME_PASSED);
	}
	return (TIME_NPASSED);
}

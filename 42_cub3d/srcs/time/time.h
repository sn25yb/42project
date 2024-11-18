/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:50:29 by yubshin           #+#    #+#             */
/*   Updated: 2024/11/13 10:56:17 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H

# include "../../libft/libft/libft.h"
# include "../../mlx/mlx.h"
# include <sys/time.h>

# define TIME_LIMIT 120
# define TIME_PASSED 1
# define TIME_NPASSED 0

long	timeval_to_long(void);
int		display_game_clock(long *start_time, void *mlx, void *win);
int		update_anim_clock(long *pre, double wait);

#endif 
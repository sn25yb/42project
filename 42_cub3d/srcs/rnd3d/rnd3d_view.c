/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rnd3d_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:07:56 by yubshin           #+#    #+#             */
/*   Updated: 2024/11/14 10:42:30 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rnd3d.h"

void	update_rnd3d_view(t_rnd3d *rnd3d, t_view view)
{
	double	plane_offset;

	rnd3d->view = view;
	plane_offset = 0.88;
	rnd3d->view.plane.x = -view.dir.y * plane_offset;
	rnd3d->view.plane.y = view.dir.x * plane_offset;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:05:11 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/11 15:05:13 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	is_wall(char mapcode)
{
	if (mapcode == '1')
		return (TRUE);
	return (FALSE);
}

int	is_door(char mapcode)
{
	if (mapcode == 'd' || mapcode == 'e')
		return (TRUE);
	return (FALSE);
}

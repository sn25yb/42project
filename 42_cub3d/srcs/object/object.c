/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:06:40 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/29 14:06:42 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_objs	get_num_objs(char c)
{
	const char	id[10] = " wbckLAFHR";
	int			index;

	index = 10;
	while (--index > 0)
	{
		if (id[index] == c)
			return (index);
	}
	return (index);
}

void	pick_objs(int objs[11], char c)
{
	if (get_num_objs(c))
		objs[get_num_objs(c)]++;
}

const char	*numstr(t_objs objs)
{
	if (objs == wotou)
		return ("wotou");
	if (objs == carrot)
		return ("carrot");
	if (objs == boots)
		return ("boots");
	if (objs == kangbao)
		return ("kangbao");
	if (objs == FUBAO)
		return ("FUBAO");
	if (objs == AIBAO)
		return ("AIBAO");
	if (objs == LEBAO)
		return ("LEBAO");
	if (objs == HUIBAO)
		return ("HUIBAO");
	if (objs == RUIBAO)
		return ("ruibao");
	return ("exit");
}

t_objs	find_preq(t_objs panda)
{
	if (panda == LEBAO)
		return (wotou);
	else if (panda == AIBAO)
		return (kangbao);
	else if (panda == HUIBAO)
		return (boots);
	else if (panda == RUIBAO)
		return (carrot);
	else
		return (no_obj);
}

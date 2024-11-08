/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:06:48 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/29 14:08:00 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H
# include "libft/error/ft_err.h"
# include "libft/queue/queue.h"
# include "libft/base/pair.h"
# include "libft/base/lib.h"
# include "libft/libft/libft.h"

typedef enum e_objs
{
	no_obj,
	wotou,
	boots,
	carrot,
	kangbao,
	LEBAO,
	AIBAO,
	FUBAO,
	HUIBAO,
	RUIBAO,
	TOTAL_NUM,
}	t_objs;

t_objs		get_num_objs(char c);
void		pick_objs(int objs[11], char c);
const char	*numstr(t_objs objs);
t_boolean	count_objs(int objs[10]);
t_objs		find_preq(t_objs panda);

#endif

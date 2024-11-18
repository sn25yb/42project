/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:58:32 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/14 15:15:08 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef RULE_BONUS_H
# define RULE_BONUS_H
# include "libft/error/ft_err.h"
# include "libft/queue/queue.h"
# include "libft/base/pair.h"
# include "libft/base/lib.h"
# include "libft/libft/libft.h"
# include "srcs_bonus/object/object_bonus.h"
# include "srcs_bonus/utils/utils_bonus.h"

t_err		set_map(char ***map, char *line);
void		pick_exit(char c, int *num);
t_err		check_object(char **map);
t_err		is_surrbywall(char **map, char **cpy);
t_err		check_player(char **map);
t_err		check_door(char **map);
t_err		check_exit(char **map);
t_boolean	is_forbidden_route(char **map, int x, int y);
t_err		check_validmap(char **map);

#endif

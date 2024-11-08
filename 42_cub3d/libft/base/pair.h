/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:34:39 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/01 16:16:14 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_H
# define PAIR_H

typedef struct s_pair_int
{
	int	x;
	int	y;
}	t_pair_int;

typedef struct s_pair_dbl
{
	double	y;
	double	x;
}	t_pair_dbl;

t_pair_int	make_pair_int(int x, int y);
t_pair_dbl	make_pair_dbl(double x, double y);

#endif 

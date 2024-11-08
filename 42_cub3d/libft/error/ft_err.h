/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:32:25 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/24 12:32:51 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERR_H
# define FT_ERR_H
# define MSG_MAP_FAILED "INVALID MAP FILE"
# define MSG_ARG_FAILED "INVALID ARGUMENTS"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef enum e_err
{
	ARG_FAILED = 2,
	MAP_FAILED,
	IMG_FAILED,
	EXTRA
}	t_err;

void	print_msg(int code);

#endif

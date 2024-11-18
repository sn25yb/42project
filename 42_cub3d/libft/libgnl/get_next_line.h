/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:07:13 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/12 10:54:33 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_file
{
	ssize_t			readbyte;
	ssize_t			storebyte;
	int				fd;
	char			buf[BUFFER_SIZE + 1];
}	t_file;

char	*get_next_line(int fd);
#endif

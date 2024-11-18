/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:23:02 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/11 17:38:43 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*make_lines(t_file *file)
{
	file->readbyte = read(file->fd, file->buf, 1);
	if (file->readbyte <= 0)
		return (NULL);
	while (file->readbyte && !ft_strchr(file->buf, '\n'))
	{
		file->storebyte += file->readbyte;
		if (file->storebyte == BUFFER_SIZE)
			return (NULL);
		file->readbyte = read(file->fd, &file->buf[file->storebyte], 1);
	}
	return (ft_strdup(file->buf));
}

char	*get_next_line(int fd)
{
	t_file	new;
	char	*result;

	ft_memset(&new, 0, sizeof(t_file));
	new.fd = fd;
	result = make_lines(&new);
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:33:34 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/12 10:54:30 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../error/ft_err.h"
# include "../libgnl/get_next_line.h"

void	free_array(char **arr);
char	**arrcpy(char **arr);
char	*ft_strchrset(char *str, char *set);
int		read_next_line(const char *file, char **line, int *fd);
void	free_intarray(int **arr, int size);
int		is_wall(char mapcode);
int		is_door(char mapcode);

#endif

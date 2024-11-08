/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:54:34 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/01 17:54:37 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_err.h"

void	print_msg(int code)
{
	if (!code)
		return ;
	ft_putstr_fd("ERROR: ", STDERR_FILENO);
	if (code == ARG_FAILED)
		ft_putendl_fd(MSG_ARG_FAILED, STDERR_FILENO);
	else if (code == MAP_FAILED)
		ft_putendl_fd(MSG_MAP_FAILED, STDERR_FILENO);
	else
		perror("");
}

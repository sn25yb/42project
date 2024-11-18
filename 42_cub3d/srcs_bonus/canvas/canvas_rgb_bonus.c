/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:50:45 by yubshin           #+#    #+#             */
/*   Updated: 2024/11/08 16:41:56 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../canvas/canvas_bonus.h"

t_err	check_rgbnum(int num, char *str)
{
	char	*s;
	int		code;

	if (num < 0 || num > 255)
		return (MAP_FAILED);
	s = ft_itoa(num);
	code = EXIT_SUCCESS;
	if (!s)
		code = EXTRA;
	if (!code && ft_strlen(s) != ft_strlen(str))
		code = MAP_FAILED;
	if (!code && ft_memcmp(str, s, ft_strlen(s)))
		code = MAP_FAILED;
	free(s);
	return (code);
}

int	rgb_to_int(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}

int	blur_rgb(t_rgb rgb, double blur_level, int blur_color)
{
	rgb.r = (int)(rgb.r + (blur_color - rgb.r) * blur_level);
	rgb.g = (int)(rgb.g + (blur_color - rgb.g) * blur_level);
	rgb.b = (int)(rgb.b + (blur_color - rgb.b) * blur_level);
	return (rgb_to_int(rgb.r, rgb.g, rgb.b));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inventory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:28:44 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/31 10:46:47 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inventory.h"

t_boolean	is_allinventory(t_queues inv)
{
	int	index;

	index = LEBAO;
	while (index <= RUIBAO)
	{
		if (!has_target(inv, index))
			return (FALSE);
		index++;
	}
	return (TRUE);
}

int	add_inventoryimg(t_inventory *inv, void *mlx)
{
	char	**files;
	int		id;
	int		fd;
	int		code;

	fd = 0;
	id = 0;
	files = ft_calloc(TOTAL_NUM + 1, sizeof(char *));
	code = EXIT_SUCCESS;
	if (!files || read_next_line("./texture/texlst/invlst", &files[id], &fd))
		return (EXTRA);
	while (files[id] && !code && id < TOTAL_NUM)
	{
		code = get_canvas(mlx, &inv->object[id], files[id]);
		read_next_line("./texture/texlst/invlst", &files[++id], &fd);
	}
	if (fd > 0)
		close(fd);
	if ((!code && id != TOTAL_NUM) || fd > 0)
		code = EXTRA;
	free_array(files);
	return (code);
}

void	display_inventory(t_inventory *inv, void *mlx, void *win)
{
	t_queue		*node;
	t_canvas	img;
	int			id;
	int			*val;
	t_pair_int	xy;

	xy.y = UP_MARGIN;
	node = inv->pocket.head;
	id = 0;
	while (id < 5)
	{
		if (node)
		{
			val = node->val;
			img = inv->object[*val];
			node = node->next;
		}
		else
			img = inv->object[0];
		xy.x = SCREEN_W / 2 - img.size.x / 2 * 5 + id * img.size.x;
		mlx_put_image_to_window(mlx, win, img.img, xy.x, xy.y);
		id++;
	}
}

void	free_inventory(t_inventory *inv, void *mlx)
{
	int	index;

	index = 0;
	while (index < TOTAL_NUM)
		free_canvas(&inv->object[index++], mlx);
	free_queue(inv->pocket.head);
	ft_memset(inv, 0, sizeof(t_inventory));
}

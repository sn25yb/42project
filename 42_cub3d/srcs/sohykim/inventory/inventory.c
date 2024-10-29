/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inventory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:28:44 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/24 14:28:46 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "inventory.h"

t_boolean	isit_inventory(t_queues inv, int num)
{
	t_queue	*node;

	node = inv.head;
	while (node)
	{
		if (node->num == num)
			return (TRUE);
		node = node->next;
	}
	return (FALSE);
}

t_boolean	is_allinventory(t_queues inv)
{
	int	index;

	index = LEBAO;
	while (index <= RUIBAO)
	{
		if (!isit_inventory(inv, index))
			return (FALSE);
		index++;
	}
	return (TRUE);
}

void	pop_target(t_queues *inv, int num)
{
	t_queue	*node;
	t_queue	*next;

	node = inv->head;
	if (!node)
		return ;
	if (node->num == num)
	{
		inv->head = inv->head->next;
		free(node);
	}
	else
	{
		while (node->next)
		{
			if (node->next->num == num)
			{
				next = node->next->next;
				free(node->next);
				node->next = next;
				break ;
			}
			node = node->next;
		}
	}
}

int	add_inventory2d(t_inventory *inv, void *mlx)
{
	if (get_image(mlx, &inv->img, "./textures/2d/inventory.xpm"))
		return (IMG_FAILED);
	return (EXIT_SUCCESS);
}
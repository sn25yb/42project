/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:31:08 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/24 12:31:28 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "queue.h"

t_queue	*create_queue(void *src, size_t size)
{
	t_queue		*new;

	new = malloc(sizeof(t_queue));
	if (new)
	{
		new->next = 0;
		new->val = malloc(size);
		if (!new->val)
		{
			free(new);
			new = NULL;
		}
		else
			ft_memcpy(new->val, src, size);
	}
	return (new);
}

void	free_node(t_queue *node)
{
	free(node->val);
	free(node);
}

void	free_queue(t_queue	*q)
{
	t_queue	*tmp;

	while (q)
	{
		tmp = q->next;
		free_node(q);
		q = tmp;
	}
}

void	pop_target(t_queues *inv, int num)
{
	t_queue	*node;
	t_queue	*next;

	node = inv->head;
	if (!node)
		return ;
	if (!ft_memcmp(node->val, &num, sizeof(int)))
	{
		inv->head = inv->head->next;
		free_node(node);
	}
	else
	{
		while (node->next)
		{
			if (!ft_memcmp(node->next->val, &num, sizeof(int)))
			{
				next = node->next->next;
				free_node(node->next);
				node->next = next;
				break ;
			}
			node = node->next;
		}
	}
}

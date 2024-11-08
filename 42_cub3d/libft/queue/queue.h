/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:23:05 by sohykim           #+#    #+#             */
/*   Updated: 2024/10/24 12:31:54 by sohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef QUEUE_H
# define QUEUE_H
# include "../base/pair.h"
# include "../libft/libft.h"
# include "../error/ft_err.h"
# include <stdio.h>

typedef struct s_queue
{
	void			*val;
	struct s_queue	*next;
}	t_queue;

typedef struct s_queues
{
	struct s_queue	*head;
}	t_queues;

t_queue		*create_queue(void *src, size_t size);
void		free_queues(t_queues *q);
int			push(t_queues *q, t_pair_int xy);
int			pushnum(t_queues *q, int num);
void		pop(t_queues *q);
void		free_queue(t_queue	*q);
t_boolean	has_target(t_queues inv, int num);
void		pop_target(t_queues *inv, int num);
void		free_node(t_queue *node);

#endif

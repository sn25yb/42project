/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inventory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubshin <yubshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:06:24 by sohykim           #+#    #+#             */
/*   Updated: 2024/11/12 10:57:59 by yubshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INVENTORY_H
# define INVENTORY_H
# include "libft/queue/queue.h"
# include "libft/base/lib.h"
# include "../canvas/canvas.h"
# include "mlx/mlx.h"
# include "../object/object.h"
# include "srcs/utils/utils.h"
# define UP_MARGIN 50
# define INV_WIDTH 105
# define INV_HEIGHT 78
# define LEFT_MARGIN 

typedef struct s_inventory
{
	t_queues		pocket;
	t_canvas		object[TOTAL_NUM];
}	t_inventory;

int			add_inventoryimg(t_inventory *inv, void *mlx);
void		pop_target(t_queues *inv, int num);
t_boolean	is_allinventory(t_queues inv);
void		display_inventory(t_inventory *inv, void *mlx, void *win);
void		free_inventory(t_inventory *inv, void *mlx);

#endif

#ifndef INVENTORY_H
# define INVENTORY_H
# include "libft/queue/queue.h"
# include "../image2d/image2d.h"
# include "mlx/mlx.h"
# include "../object/object.h"

typedef struct s_inventory
{
	t_queues	pocket;
	t_img2d		img;
}	t_inventory;

int			add_inventory2d(t_inventory *inv, void *mlx);
t_boolean  	isit_inventory(t_queues inv, int num);
void		pop_target(t_queues *inv, int num);
t_boolean	is_allinventory(t_queues inv);

#endif
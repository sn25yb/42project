CC = cc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -L./libft \
		  -L./mlx \

LDLIBS = -lft \
		 -lmlx \
		 -lm

CPPFLAGS = -I. \
		   -I./libft \
		   -I./mlx \
		   -MMD -MP

MLXFLAG = -framework OpenGL -framework AppKit

SRC_CUB3D = ./srcs/cub3d/
SRC_CANVAS = ./srcs/canvas/
SRC_TIME = ./srcs/time/
SRC_TEX3D = ./srcs/tex3d/
SRC_RND3D = ./srcs/rnd3d/
SRC_INV = ./srcs/inventory/
SRC_MMAP = ./srcs/minimap/
SRC_OBJ = ./srcs/object/
SRC_SCRIPT = ./srcs/script/
SRC_UTILS = ./srcs/utils/
SRC_VALID = ./srcs/validation/
SRC_VIEW = ./srcs/view/
SRC_HOOK = ./srcs/hook/

BASE = ./base/

SRCS = $(SRC_CUB3D)main.c \
	   $(SRC_CUB3D)exit.c \
	   $(SRC_CUB3D)event.c \
	   $(SRC_CUB3D)display.c \
	   $(SRC_CUB3D)rule.c \
	   $(SRC_CUB3D)setting.c \
	   $(SRC_CUB3D)utils.c \
	   $(SRC_CUB3D)arg.c \
	   $(SRC_CANVAS)canvas.c \
	   $(SRC_CANVAS)canvas_rgb.c \
	   $(SRC_TIME)time.c \
	   $(SRC_TEX3D)tex3d_add.c \
	   $(SRC_TEX3D)anim_add.c \
	   $(SRC_TEX3D)anim_update.c \
	   $(SRC_RND3D)rnd3d_display.c \
	   $(SRC_RND3D)rnd3d_view.c \
	   $(SRC_RND3D)rnd3d_wall.c \
	   $(SRC_RND3D)rnd3d_wall_raycal.c \
	   $(SRC_RND3D)rnd3d_wall_dda.c \
	   $(SRC_RND3D)rnd3d_wall_drawcal.c \
	   $(SRC_RND3D)rnd3d_wall_draw.c \
	   $(SRC_RND3D)rnd3d_obj.c \
	   $(SRC_RND3D)rnd3d_obj_cal.c \
	   $(SRC_RND3D)rnd3d_obj_draw.c \
	   $(SRC_RND3D)rnd3d_ceilfloor.c \
	   $(SRC_INV)inventory.c \
	   $(SRC_MMAP)map2d.c \
	   $(SRC_MMAP)utils.c \
	   $(SRC_MMAP)display.c \
	   $(SRC_MMAP)draw.c \
	   $(SRC_MMAP)map2d.c \
	   $(SRC_OBJ)object.c \
  	   $(SRC_SCRIPT)script.c \
	   $(SRC_SCRIPT)setting.c \
	   $(SRC_UTILS)utils.c \
	   $(SRC_UTILS)hook_utils.c \
	   $(SRC_VALID)map.c \
	   $(SRC_VALID)door.c \
	   $(SRC_VALID)player.c \
	   $(SRC_VALID)object.c \
	   $(SRC_VALID)wall.c \
	   $(SRC_VIEW)utils.c \
	   $(SRC_HOOK)hook.c \
	   $(SRC_HOOK)hook_loop.c \

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
NAME = baobao

all : $(NAME)

$(NAME): $(OBJS)
	make -C mlx
	make -C libft
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) $(MLXFLAG) -o $@ $^

-include $(DEPS)

$(SRC_CUB3D)%.o : $(SRC_CUB3D)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRC_CANVAS)%.o : $(SRC_CANVAS)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRC_TIME)%.o : $(SRC_TIME)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRC_TEX3D)%.o : $(SRC_TEX3D)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRC_RND3D)%.o : $(SRC_RND3D)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRC_INV)%.o : $(SRC_INV)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRC_MMAP)%.o : $(SRC_MMAP)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRC_OBJ)%.o : $(SRC_OBJ)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRC_SCRIPT)%.o : $(SRC_SCRIPT)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRC_UTILS)%.o : $(SRC_UTILS)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRC_VALID)%.o : $(SRC_VALID)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRC_VIEW)%.o : $(SRC_VIEW)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRC_HOOK)%.o : $(SRC_HOOK)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean :
	make clean -C mlx
	make clean -C libft
	rm -f $(OBJS)
	rm -f $(DEPS)

fclean : clean
	rm -f libft/libft.a
	rm -f mlx/libmlx.a
	rm -f $(NAME)

re : fclean
	make all

.PHONY : all clean fclean re

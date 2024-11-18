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

MLXFLAG = -framework OpenGL -framework AppKit

SRC_DIR = ./srcs/
SRCBONUS_DIR = ./srcs_bonus/
CUB3D = cub3d/
CANVAS = canvas/
TIME = time/
TEX3D = tex3d/
RND3D = rnd3d/
INV = inventory/
MMAP = minimap/
OBJ = object/
SCRIPT = script/
UTILS = utils/
VALID = validation/
VIEW = view/
HOOK = hook/

SRCS = $(SRC_DIR)$(CUB3D)main.c \
	   $(SRC_DIR)$(CUB3D)exit.c \
	   $(SRC_DIR)$(CUB3D)event.c \
	   $(SRC_DIR)$(CUB3D)display.c \
	   $(SRC_DIR)$(CUB3D)rule.c \
	   $(SRC_DIR)$(CUB3D)setting.c \
	   $(SRC_DIR)$(CUB3D)utils.c \
	   $(SRC_DIR)$(CUB3D)arg.c \
	   $(SRC_DIR)$(CANVAS)canvas.c \
	   $(SRC_DIR)$(CANVAS)canvas_rgb.c \
	   $(SRC_DIR)$(TIME)time.c \
	   $(SRC_DIR)$(TEX3D)tex3d_add.c \
	   $(SRC_DIR)$(TEX3D)anim_add.c \
	   $(SRC_DIR)$(TEX3D)anim_update.c \
	   $(SRC_DIR)$(RND3D)rnd3d_display.c \
	   $(SRC_DIR)$(RND3D)rnd3d_view.c \
	   $(SRC_DIR)$(RND3D)rnd3d_wall.c \
	   $(SRC_DIR)$(RND3D)rnd3d_wall_raycal.c \
	   $(SRC_DIR)$(RND3D)rnd3d_wall_dda.c \
	   $(SRC_DIR)$(RND3D)rnd3d_wall_drawcal.c \
	   $(SRC_DIR)$(RND3D)rnd3d_wall_draw.c \
	   $(SRC_DIR)$(RND3D)rnd3d_obj.c \
	   $(SRC_DIR)$(RND3D)rnd3d_obj_cal.c \
	   $(SRC_DIR)$(RND3D)rnd3d_obj_draw.c \
	   $(SRC_DIR)$(RND3D)rnd3d_ceilfloor.c \
	   $(SRC_DIR)$(INV)inventory.c \
	   $(SRC_DIR)$(MMAP)map2d.c \
	   $(SRC_DIR)$(MMAP)utils.c \
	   $(SRC_DIR)$(MMAP)display.c \
	   $(SRC_DIR)$(MMAP)draw.c \
	   $(SRC_DIR)$(MMAP)map2d.c \
	   $(SRC_DIR)$(OBJ)object.c \
  	   $(SRC_DIR)$(SCRIPT)script.c \
	   $(SRC_DIR)$(SCRIPT)setting.c \
	   $(SRC_DIR)$(UTILS)utils.c \
	   $(SRC_DIR)$(UTILS)hook_utils.c \
	   $(SRC_DIR)$(VALID)map.c \
	   $(SRC_DIR)$(VALID)door.c \
	   $(SRC_DIR)$(VALID)player.c \
	   $(SRC_DIR)$(VALID)object.c \
	   $(SRC_DIR)$(VALID)wall.c \
	   $(SRC_DIR)$(VIEW)utils.c \
	   $(SRC_DIR)$(HOOK)hook.c \
	   $(SRC_DIR)$(HOOK)hook_loop.c \

SRCS_BONUS = $(SRCBONUS_DIR)$(CUB3D)main_bonus.c \
	   $(SRCBONUS_DIR)$(CUB3D)exit_bonus.c \
	   $(SRCBONUS_DIR)$(CUB3D)event_bonus.c \
	   $(SRCBONUS_DIR)$(CUB3D)display_bonus.c \
	   $(SRCBONUS_DIR)$(CUB3D)rule_bonus.c \
	   $(SRCBONUS_DIR)$(CUB3D)setting_bonus.c \
	   $(SRCBONUS_DIR)$(CUB3D)utils_bonus.c \
	   $(SRCBONUS_DIR)$(CUB3D)arg_bonus.c \
	   $(SRCBONUS_DIR)$(CANVAS)canvas_bonus.c \
	   $(SRCBONUS_DIR)$(CANVAS)canvas_rgb_bonus.c \
	   $(SRCBONUS_DIR)$(TIME)time_bonus.c \
	   $(SRCBONUS_DIR)$(TEX3D)tex3d_add_bonus.c \
	   $(SRCBONUS_DIR)$(TEX3D)anim_add_bonus.c \
	   $(SRCBONUS_DIR)$(TEX3D)anim_update_bonus.c \
	   $(SRCBONUS_DIR)$(RND3D)rnd3d_display_bonus.c \
	   $(SRCBONUS_DIR)$(RND3D)rnd3d_view_bonus.c \
	   $(SRCBONUS_DIR)$(RND3D)rnd3d_wall_bonus.c \
	   $(SRCBONUS_DIR)$(RND3D)rnd3d_wall_raycal_bonus.c \
	   $(SRCBONUS_DIR)$(RND3D)rnd3d_wall_dda_bonus.c \
	   $(SRCBONUS_DIR)$(RND3D)rnd3d_wall_drawcal_bonus.c \
	   $(SRCBONUS_DIR)$(RND3D)rnd3d_wall_draw_bonus.c \
	   $(SRCBONUS_DIR)$(RND3D)rnd3d_obj_bonus.c \
	   $(SRCBONUS_DIR)$(RND3D)rnd3d_obj_cal_bonus.c \
	   $(SRCBONUS_DIR)$(RND3D)rnd3d_obj_draw_bonus.c \
	   $(SRCBONUS_DIR)$(RND3D)rnd3d_ceilfloor_bonus.c \
	   $(SRCBONUS_DIR)$(INV)inventory_bonus.c \
	   $(SRCBONUS_DIR)$(MMAP)map2d_bonus.c \
	   $(SRCBONUS_DIR)$(MMAP)utils_bonus.c \
	   $(SRCBONUS_DIR)$(MMAP)display_bonus.c \
	   $(SRCBONUS_DIR)$(MMAP)draw_bonus.c \
	   $(SRCBONUS_DIR)$(MMAP)map2d_bonus.c \
	   $(SRCBONUS_DIR)$(OBJ)object_bonus.c \
  	   $(SRCBONUS_DIR)$(SCRIPT)script_bonus.c \
	   $(SRCBONUS_DIR)$(SCRIPT)setting_bonus.c \
	   $(SRCBONUS_DIR)$(UTILS)utils_bonus.c \
	   $(SRCBONUS_DIR)$(UTILS)hook_utils_bonus.c \
	   $(SRCBONUS_DIR)$(VALID)map_bonus.c \
	   $(SRCBONUS_DIR)$(VALID)door_bonus.c \
	   $(SRCBONUS_DIR)$(VALID)player_bonus.c \
	   $(SRCBONUS_DIR)$(VALID)object_bonus.c \
	   $(SRCBONUS_DIR)$(VALID)wall_bonus.c \
	   $(SRCBONUS_DIR)$(VIEW)utils_bonus.c \
	   $(SRCBONUS_DIR)$(HOOK)hook_bonus.c \
	   $(SRCBONUS_DIR)$(HOOK)hook_loop_bonus.c \

BONUS = bonus
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
TARGET = $(if $(filter bonus, $(MAKECMDGOALS)), $(OBJS_BONUS), $(OBJS))
NAME = cub3D

all : $(NAME)

$(BONUS) : $(NAME)

$(NAME): $(TARGET)
	make -C mlx
	make -C libft
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) $(MLXFLAG) -o $@ $^

$(SRC_DIR)$(CUB3D)%.o : $(SRC_DIR)$(CUB3D)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRC_DIR)$(CANVAS)%.o : $(SRC_DIR)$(CANVAS)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRC_DIR)$(TIME)%.o : $(SRC_DIR)$(TIME)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRC_DIR)$(TEX3D)%.o : $(SRC_DIR)$(TEX3D)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRC_DIR)$(RND3D)%.o : $(SRC_DIR)$(RND3D)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRC_DIR)$(INV)%.o : $(SRC_DIR)$(INV)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRC_DIR)$(MMAP)%.o : $(SRC_DIR)$(MMAP)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRC_DIR)$(OBJ)%.o : $(SRC_DIR)$(OBJ)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRC_DIR)$(SCRIPT)%.o : $(SRC_DIR)$(SCRIPT)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRC_DIR)$(UTILS)%.o : $(SRC_DIR)$(UTILS)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRC_DIR)$(VALID)%.o : $(SRC_DIR)$(VALID)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRC_DIR)$(VIEW)%.o : $(SRC_DIR)$(VIEW)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRC_DIR)$(HOOK)%.o : $(SRC_DIR)$(HOOK)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<


#bonus
$(SRCBONUS_DIR)$(CUB3D)%.o : $(SRCBONUS_DIR)$(CUB3D)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRCBONUS_DIR)$(CANVAS)%.o : $(SRCBONUS_DIR)$(CANVAS)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRCBONUS_DIR)$(TIME)%.o : $(SRCBONUS_DIR)$(TIME)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRCBONUS_DIR)$(TEX3D)%.o : $(SRCBONUS_DIR)$(TEX3D)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRCBONUS_DIR)$(RND3D)%.o : $(SRCBONUS_DIR)$(RND3D)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRCBONUS_DIR)$(INV)%.o : $(SRCBONUS_DIR)$(INV)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRCBONUS_DIR)$(MMAP)%.o : $(SRCBONUS_DIR)$(MMAP)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRCBONUS_DIR)$(OBJ)%.o : $(SRCBONUS_DIR)$(OBJ)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRCBONUS_DIR)$(SCRIPT)%.o : $(SRCBONUS_DIR)$(SCRIPT)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRCBONUS_DIR)$(UTILS)%.o : $(SRCBONUS_DIR)$(UTILS)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRCBONUS_DIR)$(VALID)%.o : $(SRCBONUS_DIR)$(VALID)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRCBONUS_DIR)$(VIEW)%.o : $(SRCBONUS_DIR)$(VIEW)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRCBONUS_DIR)$(HOOK)%.o : $(SRCBONUS_DIR)$(HOOK)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean :
	make clean -C mlx
	make clean -C libft
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean : clean
	rm -f libft/libft.a
	rm -f mlx/libmlx.a
	rm -f $(NAME)

re : fclean
	make all

.PHONY : all clean fclean re

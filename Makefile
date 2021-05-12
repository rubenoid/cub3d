NAME = cub3D
MLX_DIR = ./minilibx
LIBFT = ./libft

SRCS = main.c \
	bmp.c \
	ft_movement.c \
	keypress_functions.c \
	movement_utils0.c \
	movement_utils2.c \
	cub_color0.c \
	cub_color1.c \
	cub_extension.c \
	cub_parse_map0.c \
	cub_parse_map1.c \
	cub_parse_map2.c \
	cub_parse_map3.c \
	cub_parse_map4.c \
	cub_player_position.c \
	cub_resolution.c \
	cub_texture.c \
	dda_wall0.c \
	dda_wall1.c \
	dda_wall2.c \
	dda_sprites0.c \
	dda_sprites1.c \
	draw_and_render.c \
	error_and_exit.c


SRCS_B = cub3D_bonus/main_bonus.c \
	cub3D_bonus/bmp_bonus.c \
	cub3D_bonus/ft_movement_bonus.c \
	cub3D_bonus/keypress_functions_bonus.c \
	cub3D_bonus/movement_utils0_bonus.c \
	cub3D_bonus/movement_utils1_bonus.c \
	cub3D_bonus/movement_utils2_bonus.c \
	cub3D_bonus/cub_extension_bonus.c \
	cub3D_bonus/cub_parse_map0_bonus.c \
	cub3D_bonus/cub_parse_map1_bonus.c \
	cub3D_bonus/cub_parse_map2_bonus.c \
	cub3D_bonus/cub_parse_map3_bonus.c \
	cub3D_bonus/cub_parse_map4_bonus.c \
	cub3D_bonus/cub_player_position_bonus.c \
	cub3D_bonus/cub_resolution_bonus.c \
	cub3D_bonus/cub_texture_bonus.c \
	cub3D_bonus/dda_floor_ceiling0_bonus.c \
	cub3D_bonus/dda_floor_ceiling1_bonus.c \
	cub3D_bonus/dda_wall0_bonus.c \
	cub3D_bonus/dda_wall1_bonus.c \
	cub3D_bonus/dda_wall2_bonus.c \
	cub3D_bonus/dda_sprites0_bonus.c \
	cub3D_bonus/dda_sprites1_bonus.c \
	cub3D_bonus/draw_and_render_bonus.c \
	cub3D_bonus/error_and_exit_bonus.c

OBJ = main.o \
	bmp.o \
	ft_movement.o \
	keypress_functions.o \
	movement_utils0.o \
	movement_utils2.o \
	cub_color0.o \
	cub_color1.o \
	cub_extension.o \
	cub_parse_map0.o \
	cub_parse_map1.o \
	cub_parse_map2.o \
	cub_parse_map3.o \
	cub_parse_map4.o \
	cub_player_position.o \
	cub_resolution.o \
	cub_texture.o \
	dda_wall0.o \
	dda_wall1.o \
	dda_wall2.o \
	dda_sprites0.o \
	dda_sprites1.o \
	draw_and_render.o \
	error_and_exit.o

OBJ_B = cub3D_bonus/main_bonus.o \
	cub3D_bonus/bmp_bonus.o \
	cub3D_bonus/ft_movement_bonus.o \
	cub3D_bonus/keypress_functions_bonus.o \
	cub3D_bonus/movement_utils0_bonus.o \
	cub3D_bonus/movement_utils1_bonus.o \
	cub3D_bonus/movement_utils2_bonus.o \
	cub3D_bonus/cub_extension_bonus.o \
	cub3D_bonus/cub_parse_map0_bonus.o \
	cub3D_bonus/cub_parse_map1_bonus.o \
	cub3D_bonus/cub_parse_map2_bonus.o \
	cub3D_bonus/cub_parse_map3_bonus.o \
	cub3D_bonus/cub_parse_map4_bonus.o \
	cub3D_bonus/cub_player_position_bonus.o \
	cub3D_bonus/cub_resolution_bonus.o \
	cub3D_bonus/cub_texture_bonus.o \
	cub3D_bonus/dda_floor_ceiling0_bonus.o \
	cub3D_bonus/dda_floor_ceiling1_bonus.o \
	cub3D_bonus/dda_wall0_bonus.o \
	cub3D_bonus/dda_wall1_bonus.o \
	cub3D_bonus/dda_wall2_bonus.o \
	cub3D_bonus/dda_sprites0_bonus.o \
	cub3D_bonus/dda_sprites1_bonus.o \
	cub3D_bonus/draw_and_render_bonus.o \
	cub3D_bonus/error_and_exit_bonus.o

FLAGS = -Wall -Wextra -Werror -Ofast

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(MLX_DIR)
	make -C $(LIBFT)
	cp $(MLX_DIR)/libmlx.dylib .
	$(CC) $^ -Llibft -lft  -Lminilibx -lmlx -framework OpenGL \
			-framework AppKit -o $(NAME) $(FLAGS)

bonus: $(OBJ_B)
	make -C $(MLX_DIR)
	make -C $(LIBFT)
	cp $(MLX_DIR)/libmlx.dylib .
	$(CC) $^ -Llibft -lft  -Lminilibx -lmlx -framework OpenGL \
			-framework AppKit -o $(NAME) $(FLAGS)

%.o: %.c
	$(CC) $(FLAGS) -Iminilibx -c $< -o $@

clean:
	make clean -C $(MLX_DIR)
	make clean -C $(LIBFT)
	rm -f $(OBJ)
	rm -f $(OBJ_B)
	rm -f libmlx.dylib

fclean: clean
	rm -f $(NAME)

re: fclean all

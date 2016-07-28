# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scebula <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/25 15:37:58 by scebula           #+#    #+#              #
#    Updated: 2016/07/25 16:28:28 by scebula          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = event.c \
		   parse.c \
		   main.c \
		   movements.c \
		   putpixel.c \
		   event_mouse.c \
		   init_img.c \
		   init_mlx.c \
		   init_struct.c \
		   dda.c \
		   draw_t.c \
		   creator.c \
		   display.c \
		   close.c\
		   game.c \
		   no_event.c \
		   utility.c
INC_NAME = wolf3d.h \
		   mlx.h \
		   libft.h \
		   keys.h

OBJ_NAME = $(SRC_NAME:.c=.o)
NAME = wolf3d
CC = gcc
CFLAGS =  -O3
EXEC_NAME = wolf3d
MLX_FLAGS = -lft -lmlx -framework OpenGL -framework Appkit
LIBFT = libft.a
LIBMLX = libmlx.a
LIBFT_DIR = libft/
MLX_DIR = mlx/
LIB_DIR = lib/
INC_DIR = inc/
SRC_FILES = $(addprefix src/,$(SRC_NAME))
OBJ_FILES = $(addprefix obj/,$(OBJ_NAME))
INC_FILES = $(addprefix inc/,$(INC_NAME))

all: $(NAME) norminette welcome

$(NAME): create_libft create_mlx objects
ifeq ($(wildcard $(EXEC_NAME)),)
	@echo "\x1b[33m-- COMPILING ... --\033[0m"
	$(CC) $(CFLAGS) -o $(EXEC_NAME) $(OBJ_FILES) -Llib $(MLX_FLAGS)
	$(EXEC_EXIST = 1)
	@echo "\x1b[32m-- COMPILING SUCCESSFULL --"
else
	@echo "\x1b[31mNo need another compilation."
endif

create_libft:
	@echo "\x1b[31mMaking LIBFT ...\033[0m"
	@make -s -C $(LIBFT_DIR)
	@mkdir -p lib
	@cp $(LIBFT_DIR)$(LIBFT) $(LIB_DIR)$(LIBFT)
	cp $(LIBFT_DIR)libft.h $(INC_DIR)libft.h
	

create_mlx:
	@echo "\x1b[31mMaking LIBMLX ...\033[0m"
	@make -s -C $(MLX_DIR)
	cp $(MLX_DIR)$(LIBMLX) $(LIB_DIR)$(LIBMLX)
	cp $(MLX_DIR)mlx.h $(INC_DIR)mlx.h

norminette:
	@echo "----------NORMINETTE------------"
	@echo "\x1b[37m"
	@norminette $(SRC_FILES)
	@norminette ./inc/wolf3d.h
	@norminette ./inc/keys.h
	@norminette ./inc/libft.h

welcome:
	@echo "\x1b[36m"
	@echo "Have fun with Wolf3d !"
	@echo "./wolf3d [filename][x-position][y-position]"
	@echo "OR"
	@echo "./wolf3d [length][height][x-position][y-position]"

objects:
ifeq ($(wildcard $(EXEC_NAME)),) 
	$(CC) $(CFLAGS) -c -Iinc/ $(SRC_FILES)
	mkdir -p obj
	mv $(OBJ_NAME) obj/
else
endif

clean:
	make fclean -C $(LIBFT_DIR)
	rm -f $(INC_DIR)libft.h
	rm -f $(INC_DIR)mlx.h
	rm -rf ./obj
	rm -rf ./lib
	

fclean: clean
	rm -f $(NAME)

re: fclean
	@make all
fcleanlibft: 
	make fclean -C $(LIBFT_DIR)

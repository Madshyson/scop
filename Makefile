# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlavanan <mlavanan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/05 20:50:24 by mlavanan          #+#    #+#              #
#    Updated: 2018/07/22 16:51:24 by mlavanan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scop

SRC = 	src/main.c \
		src/init.c \
		src/parsing.c \
		src/movement.c \
		src/rotation.c \
		src/shaders.c \
		src/shaderglsl.c \
		src/errors.c \
		src/draw.c \
		src/keyhook.c

OBJ = 	main.o \
		init.o \
		parsing.o \
		movement.o \
		rotation.o \
		shaders.o \
		shaderglsl.o \
		errors.o \
		draw.o \
		keyhook.o
		
HEADER =./lib/libft/libft.h\
		./lib/glfw/include/GLFW/glfw3.h\
		./inc/scop.h

FINDLIBFT = -Llibft

LIBFTA = ./lib/libft/libft.a

GLFWA = ./lib/glfw/src/libglfw3.a

FLAGS = -Wall -Wextra -Werror 

LIBFT_DIR = ./lib/libft/

GLFW_DIR = ./lib/glfw/

all: $(NAME)

$(NAME):
	@clear
	@echo "\033[35;4mRule all!\033[0m"
	@make fclean -C $(LIBFT_DIR)
	@make -C $(LIBFT_DIR)
	@gcc $(FLAGS) -c $(SRC) $(HEADER)
	@gcc -o $(NAME) $(OBJ) $(LIBFTA) $(GLFWA) -L/usr/local/lib/ -I/usr/local/include -framework Cocoa -framework IOKit -framework CoreVideo -framework OpenGL -framework AppKit 

clean:
	@clear
	@echo "\033[35;4mRule clean!\033[0m"
	@rm -f $(OBJ)
	@rm -f scop.h.gch
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@clear
	@echo "\033[35;4mRule fclean!\033[0m"
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all
	@clear
	@echo "\033[35;4mRules fclean and all!\033[0m"

.PHONY: all, clean, fclean, re
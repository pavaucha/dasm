# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pavaucha <pavaucha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 09:44:22 by pavaucha          #+#    #+#              #
#    Updated: 2019/02/18 16:50:47 by pavaucha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

SRC_PATH	= srcs/
OBJ_PATH	= objs/
LIBFT_PATH	= libft/
LIBFT_A		= libft/libft.a

SRC_NAME = 	main.c 

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

CC = gcc

CFLAGS = -g -fsanitize=address -fno-omit-frame-pointer \
 		 -fsanitize=address	\
 		 -fno-omit-frame-pointer		\
 		 -fsanitize-address-use-after-scope \

# CFLAGS = -g3 

LDFLAGS =  -Llibft
LDLIBS = -lft
CPPFLAGS = -I includes -I libft/includes

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A)
	@$(CC) $(OBJ) -o $@ $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

$(LIBFT_A):
	@make -C $(LIBFT_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $< $(CFLAGS) $(CPPFLAGS)

clean:
	@make clean -C $(LIBFT_PATH)
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 12:32:15 by luiberna          #+#    #+#              #
#    Updated: 2024/03/13 22:54:02 by luiberna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = fdf.c init.c verifiers.c free.c map.c screen.c draw_alg.c projections.c

CC = cc

OBJS = $(SRCS:.c=.o)

INCLUDE = ./Includes/

CFLAGS = -I$(INCLUDE) -g #-Wall -Wextra -Werror 

RM = rm -f

LIB_MINILIBX = -L$(MINILIBX) -lmlx -framework OpenGL -framework AppKit

MINILIBX = ./minilibx/

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./Libft
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_MINILIBX) ./Libft/libft.a -o $(NAME)

clean:
	make clean -C ./Libft
	make clean -C $(MINILIBX)
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./Libft
	make clean -C $(MINILIBX)
	rm -f $(NAME)

re: fclean $(NAME)

r: 
	make re && ./fdf 

.PHONY: all clean fclean re



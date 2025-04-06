# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joudafke <joudafke@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 01:31:00 by joudafke          #+#    #+#              #
#    Updated: 2025/03/28 22:48:15 by joudafke         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER			= server
NAME_CLIENT			= client
NAME_SERVER_BONUS	= server_bonus
NAME_CLIENT_BONUS	= client_bonus
CC					= cc
FLAGS				= -Wall -Wextra -Werror
RM					= rm -f
SRCS_SERVER			= 	server.c	\
						ft_printf/ft_printf.c	\
						ft_printf/ft_putchar.c	\
						ft_printf/ft_putstr.c	\
						ft_printf/ft_putptr.c	\
						ft_printf/ft_putnbr.c	\
						ft_printf/ft_putunbr.c	\
						ft_printf/ft_puthex.c
SRC_CLIENT			= client.c
SRCS_SERVER_BONUS	= 	server_bonus.c	\
						ft_printf/ft_printf.c	\
						ft_printf/ft_putchar.c	\
						ft_printf/ft_putstr.c	\
						ft_printf/ft_putptr.c	\
						ft_printf/ft_putnbr.c	\
						ft_printf/ft_putunbr.c	\
						ft_printf/ft_puthex.c
SRC_CLIENT_BONUS	= client_bonus.c
OBJ_SERVER			= $(SRCS_SERVER:.c=.o)
OBJ_CLIENT			= $(SRC_CLIENT:.c=.o)
OBJ_SERVER_BONUS	= $(SRCS_SERVER_BONUS:.c=.o)
OBJ_CLIENT_BONUS	= $(SRC_CLIENT_BONUS:.c=.o)

all:				$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):		$(OBJ_SERVER)
					@$(CC) $(FLAGS) $(OBJ_SERVER) -o $(NAME_SERVER)
					@echo "\033[1;36m  Server compilation successful \033[0m"

$(NAME_CLIENT):		$(OBJ_CLIENT)
					@$(CC) $(FLAGS) $(OBJ_CLIENT) -o $(NAME_CLIENT)
					@echo "\033[1;36m  Client compilation successful \033[0m"

bonus:				$(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS):$(OBJ_SERVER_BONUS)
					@$(CC) $(FLAGS) $(OBJ_SERVER_BONUS) -o $(NAME_SERVER_BONUS)
					@echo "\033[1;36m  Server_bonus compilation successful \033[0m"

$(NAME_CLIENT_BONUS):$(OBJ_CLIENT_BONUS)
					@$(CC) $(FLAGS) $(OBJ_CLIENT_BONUS) -o $(NAME_CLIENT_BONUS)
					@echo "\033[1;36m  Client_bonus compilation successful \033[0m"

%.o:				%.c
					@$(CC) $(FLAGS) -c $< -o $@

clean:
					@$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)
					@echo "\033[1;35m  Objects files deleted \033[0m"

fclean:				clean
					@$(RM) $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)
					@echo "\033[1;35m  All servers and clients deleted \033[0m"
		
re:					fclean all

.PHONY:				all clean fclean re bonus
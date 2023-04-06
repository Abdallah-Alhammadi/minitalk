# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abalhamm <abalhamm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 14:06:40 by abalhamm          #+#    #+#              #
#    Updated: 2023/04/06 17:38:59 by abalhamm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = clientB.c

SERVER = serverB.c

CLIENT_NAME = client

SERVER_NAME = SERVER

CC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

all:  $(CLIENT_NAME) $(SERVER_NAME)

$(SERVER_NAME) : $(SERVER)
	$(CC) $(FLAGS) lib.c $(SERVER) -o $(SERVER_NAME)

$(CLIENT_NAME) : $(CLIENT)
	$(CC) $(FLAGS) lib.c $(CLIENT) -o $(CLIENT_NAME)

clean:
	$(RM) serverB.o clientB.o

fclean: clean
	$(RM) server client
	
re: fclean all

.PHONY:	all clean fclean re
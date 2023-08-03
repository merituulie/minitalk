# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 17:49:39 by meskelin          #+#    #+#              #
#    Updated: 2023/06/05 16:20:03 by meskelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH = ./libft

NAME = minitalk

SERVER = server
CLIENT = client
HS = client.h

BUILD_FLAGS = -Wall -Wextra -Werror # -fsanitize=address,undefined -g

SERVER_FILES = $(SERVER)
CLIENT_FILES = $(CLIENT)

SERVER_SUFF = $(addsuffix .c, $(SERVER_FILES))
CLIENT_SUFF = $(addsuffix .c, $(CLIENT_FILES))

.PHONY = all
all: $(NAME)

$(SERVER):
	make -C $(LIBFT_PATH)
	cc $(BUILD_FLAGS) $(SERVER_SUFF) -I $(HS) \
	-L $(LIBFT_PATH) -lft -o $(SERVER)

$(CLIENT):
	make -C $(LIBFT_PATH)
	cc $(BUILD_FLAGS) $(CLIENT_SUFF) \
	-L $(LIBFT_PATH) -lft -o $(CLIENT)

$(NAME): $(SERVER) $(CLIENT)

.PHONY: clean
clean:
	make fclean -C $(LIBFT_PATH)

.PHONY: fclean
fclean: clean
	rm -f $(SERVER)
	rm -f $(CLIENT)

.PHONY: re
re: fclean all

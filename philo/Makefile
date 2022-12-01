# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 16:52:41 by jungchoi          #+#    #+#              #
#    Updated: 2022/12/01 18:06:41 by jungchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=thread

INCLUDES_DIR = includes
SRCS_DIR = srcs
OBJS_DIR = objs

SRCS = $(addprefix $(SRCS_DIR)/, \
	philo.c \
	init.c \
	act.c \
	monitor.c \
	utils.c \
	free.c)

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I $(INCLUDES_DIR) -o $@


$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	@mkdir $(OBJS_DIR) 2> /dev/null || true
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

clean :
	rm -rf $(OBJS_DIR)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY = all clean fclean re

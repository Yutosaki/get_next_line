# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yutsasak <yutsasak@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/24 15:40:06 by yutsasak          #+#    #+#              #
#    Updated: 2024/05/24 16:00:30 by yutsasak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

CFLAGS = -Wall -Wextra -Werror -I includes

SRCS =	get_next_line.c \
		get_next_line_utils.c

# BFILES = 
# 		get_next_line_bonus.c \
# 		get_next_line_utils_bonus.c

# BSRCS = $(addprefix sources/bonus/,$(BFILES))

OBJS = $(SRCS:.c=.o)
# BOBJS = $(BSRCS:.c=.o)

ifdef WITH_BONUS
	OBJS = $(BOBJS)
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

bonus:
	@make WITH_BONUS=TRUE

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
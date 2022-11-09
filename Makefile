# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 18:57:24 by mtomomit          #+#    #+#              #
#    Updated: 2022/11/03 22:51:39 by mtomomit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= ./push_swap
NAME_BONUS		= ./checker
LIBFT			= libft.a
PUSH_SWAP		= ./incs/push_swap.a
PUSH_SWAP_BONUS	= ./incs/checker_bonus.a
LIBFT_PATH		= $(PUSH_SWAP_PATH)/libft
PUSH_SWAP_PATH	= $(shell pwd)

SRC 		= ./srcs/push_swap.c \
				./srcs/heap_sort.c \
				./srcs/move_utils.c \
				./srcs/move_utils2.c \
				./srcs/move_utils3.c \
				./srcs/find_best_move.c \
				./srcs/order_stack.c \
				./srcs/ft_error.c \
				./srcs/utils.c \

SRC_BONUS		= ./srcs_bonus/checker_bonus.c \
					./srcs_bonus/check_order_bonus.c \
					./srcs_bonus/ft_error_bonus.c \
					./srcs_bonus/move_bonus.c \
					./srcs_bonus/move_utils_bonus.c \
					./srcs_bonus/move_utils2_bonus.c \
					./srcs_bonus/move_utils3_bonus.c \


OBJS = ${SRC:.c=.o}
OBJS_BONUS = ${SRC_BONUS:.c=.o}

HEADER = ./incs/push_swap.h
HEADER_BONUS = ./incs/checker_bonus.h

LIB_FLAGS = ar -rcs

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -I/libft -I/incs -c $< -o ${<:.c=.o}

all: $(NAME)

$(PUSH_SWAP):	$(OBJS) $(HEADER)
		$(LIB_FLAGS) $(PUSH_SWAP) $(OBJS)

$(NAME): $(OBJS) $(HEADER) $(PUSH_SWAP)
		make -C $(LIBFT_PATH)
		$(CC) ${CFLAGS} -o $(NAME) $(PUSH_SWAP) $(LIBFT_PATH)/$(LIBFT)

bonus: $(NAME_BONUS)

$(PUSH_SWAP_BONUS):	$(OBJS_BONUS) $(HEADER_BONUS)
		$(LIB_FLAGS) $(PUSH_SWAP_BONUS) $(OBJS_BONUS)

$(NAME_BONUS): $(BIN) $(OBJS_BONUS) $(HEADER_BONUS) $(PUSH_SWAP_BONUS)
		make -C $(LIBFT_PATH)
		$(CC) ${CFLAGS} -o $(NAME_BONUS) $(PUSH_SWAP_BONUS) $(LIBFT_PATH)/$(LIBFT)

clean:
	rm -f $(OBJS)
	rm -f ./libft/$(LIBFT)
	rm -f $(PUSH_SWAP)
	make clean -C $(LIBFT_PATH)

fclean:	clean
	rm -f $(NAME)

clean_bonus:
	rm -f $(OBJS_BONUS)
	rm -f ./libft/$(LIBFT)
	rm -f $(PUSH_SWAP_BONUS)
	make clean -C $(LIBFT_PATH)

fclean_bonus:	clean_bonus
	rm -f $(NAME_BONUS)

rebonus: fclean_bonus bonus

re: fclean all

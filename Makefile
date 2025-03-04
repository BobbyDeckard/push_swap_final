# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imeulema <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 11:52:28 by imeulema          #+#    #+#              #
#    Updated: 2025/01/13 17:02:09 by imeulema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wextra -Wall -Werror
RM = rm
RMFLAGS = -f
MAKE = make

# SOURCES
SRCS = $(addprefix srcs/, $(SRCS_FILES))
SRCS_FILES = main.c \
			 $(OPERATIONS) \
			 $(PARSING) \
			 $(SORTING) \
			 $(UTILS)
OBJS = $(SRCS:.c=.o)

# OPERATIONS
OPERATIONS = $(addprefix operations/, $(OPS_FILES))
OPS_FILES = push.c \
			reverse.c \
			rotate.c \
			swap.c

# PARSING
PARSING = $(addprefix parsing/, $(PARS_FILES))
PARS_FILES = checks.c \
			 cl_checks.c \
			 cl_numbers.c \
			 parsing.c \
			 str_checks.c \
			 str_numbers.c

# SORTING
SORTING = $(addprefix sorting/, $(SORT_FILES))
SORT_FILES = bubble.c \
			 sort.c \
			 sort5.c \
			 turbo.c \
			 turk.c \
			 turk_cost.c \
			 turk_cost_place.c \
			 turk_move.c \
			 turk_move_each.c \
			 turk_utils.c

# UTILS
UTILS = $(addprefix utils/, $(UTLS_FILES))
UTLS_FILES = exit.c \
			 list.c \
			 print.c

# INCLUDES
HEADERS = incl/push_swap.h
LIBRARY = libft/libft.a

RED = \033[0;31m
YELLOW = \033[0;33m
GREEN = \033[0;32m
RESET = \033[0m

all: $(LIBRARY) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBRARY) -o $(NAME)
	echo "$(GREEN)Push Swap compiled!$(RESET)"

%.o: %.c $(HEADERS) $(LIBRARY)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBRARY):
	$(MAKE) -C libft --no-print-directory

clean:
	$(RM) $(RMFLAGS) $(OBJS)
	$(MAKE) clean -C libft --no-print-directory

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)
	$(MAKE) fclean -C libft --no-print-directory
	echo "$(GREEN)Full clean done.$(RESET)"

re: fclean all

.PHONY: all clean fclean re

.SILENT:

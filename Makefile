# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 15:41:04 by tliangso          #+#    #+#              #
#    Updated: 2022/10/05 01:32:05 by tliangso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### EXECUTABLE ###
NAME	= push_swap
BONUS_NAME	= checker

### DIR ###
DIRSRC	=	./
BONUS_SRC =	bonus/
HEAD	= ./
LIBFT_SRC = ./
### TESTER GIT URL ###
TESTER1 =
TESTER2 =
TESTER3 =

### SOURCE FILE ###
SRC		=	push_swap.c utils.c radix.c error.c index.c \
			swap.c rotate.c reverse_rotate.c push.c sort_ha_and_below.c \
			my_func_too_long.c check_args.c insertion_sort.c insertion_utils.c

BONUS	=


EXTRA	=

LIBFT	=	ft_atoi.c lst_utils.c ft_strlen.c ft_split.c ft_isdigit.c \
			ft_putstr_fd.c

### PATH ###
SRCS	= ${addprefix ${DIRSRC}, ${SRC}}
BONUS_SRCS = ${addprefix ${BONUS_SRC}, ${BONUS}}
EXTRA_SRCS = ${addprefix ${DIRSRC}, ${EXTRA}}
LIBFT_SRCS = ${addprefix ${LIBFT_SRC}, ${LIBFT}}

### OBJECT FILE ###
OBJS	= ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}
EXRTA_OBJS = ${EXTRA_SRCS:.c=.o}
LIBFT_OBJS = ${LIBFT_SRCS:.c=.o}

### COMPILATION ###
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

### COLORS ###
NOC		= \033[0m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
WHITE	= \033[1;37m

### RULES ###
.c.o:
	@${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}
	@echo "$(BLUE)clang $(WHITE)$(notdir $@)$(NOC)"

all: ${NAME}

${NAME}:	${OBJS} ${LIBFT_OBJS}

	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT_OBJS}
	@echo "$(GREEN)$@$(NOC)"

bonus:		${BONUS_OBJS} ${LIBFT_OBJS}
	@${CC} ${CFLAGS} -o ${BONUS_NAME} ${BONUS_OBJS} ${LIBFT_OBJS}
	@echo "$(GREEN)$@$(NOC)"

extra:	${OBJS} ${BONUS_OBJS} ${EXRTA_OBJS} ${LIBFT_OBJS}
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${BONUS_OBJS} ${EXRTA_OBJS} ${LIBFT_OBJS}

clean:
	@echo "$(RED)clean$(NOC)"
	@${RM} ${OBJS} ${BONUS_OBJS} ${EXRTA_OBJS} ${LIBFT_OBJS}

fclean: clean
	@echo "$(RED)fclean$(NOC)"
	@${RM} ${NAME}

re: fclean	all

tester:
	@echo "$(YELLOW)Testers are not perfect$(NOC)"
	git clone ${TESTER1} TESTER1
	git clone ${TESTER2} TESTER2
	git clone ${TESTER3} TESTER3

norm:
	norminette

gitpush:
	git add .
	git status
	git commit -m ${NAME}
	git push

.PHONY:		all	clean	fclean	re bonus norm gitpush tester

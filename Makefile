# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 15:41:04 by tliangso          #+#    #+#              #
#    Updated: 2022/10/12 11:07:17 by tliangso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### EXECUTABLE ###
NAME		= push_swap
BONUS_NAME	= checker

### DIR ###
DIRSRC		= src/
BONUS_SRC	= bonus/
HEAD		= include/
LIBFT_SRC	= libft/
SHARE_SRC	= share/

### TESTER GIT URL ###
TESTER1		= git@github.com:laisarena/push_swap_tester.git
TESTER2		= https://github.com/LeoFu9487/push_swap_tester.git
TESTER3		= git@github.com:louisabricot/push_swap_tester.git
TESTER4		= git@github.com:ael-bekk/push_swap_tester.git

### SOURCE FILE ###
SRC		=	push_swap.c radix.c \
			sort_ha_and_below.c \
			my_func_too_long.c insertion_sort.c insertion_utils.c \
			youtube_sort.c

BONUS	=	checker.c utils_bonus.c \


SHARE	=	swap.c rotate.c reverse_rotate.c push.c utils.c error.c index.c check_args.c

LIBFT	=	ft_atoi.c lst_utils.c ft_strlen.c ft_split.c ft_isdigit.c ft_strjoin.c\
			ft_putstr_fd.c get_next_line.c get_next_line_utils.c ft_strtrim.c ft_strdup.c

### PATH ###
SRCS		= ${addprefix ${DIRSRC}, ${SRC}}
BONUS_SRCS	= ${addprefix ${BONUS_SRC}, ${BONUS}}
EXTRA_SRCS	= ${addprefix ${DIRSRC}, ${EXTRA}}
LIBFT_SRCS	= ${addprefix ${LIBFT_SRC}, ${LIBFT}}
SHARE_SRCS	= ${addprefix ${SHARE_SRC}, ${SHARE}}

### OBJECT FILE ###
OBJS		= ${SRCS:.c=.o}
BONUS_OBJS	= ${BONUS_SRCS:.c=.o}
EXRTA_OBJS	= ${EXTRA_SRCS:.c=.o}
LIBFT_OBJS	= ${LIBFT_SRCS:.c=.o}
SHARE_OBJS	= ${SHARE_SRCS:.c=.o}

### COMPILATION ###
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -g

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

all: ${NAME} ${BONUS_NAME}

bonus: ${BONUS_NAME}

${NAME}:	${OBJS} ${LIBFT_OBJS} ${SHARE_OBJS}

	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT_OBJS} ${SHARE_OBJS}
	@echo "$(GREEN)$@$(NOC)"

${BONUS_NAME}:		${BONUS_OBJS} ${LIBFT_OBJS} ${SHARE_OBJS}
	@${CC} ${CFLAGS} -o ${BONUS_NAME} ${BONUS_OBJS} ${LIBFT_OBJS} ${SHARE_OBJS}
	@echo "$(GREEN)${BONUS_NAME}$(NOC)"

extra:	${OBJS} ${BONUS_OBJS} ${EXRTA_OBJS} ${LIBFT_OBJS}
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${BONUS_OBJS} ${EXRTA_OBJS} ${LIBFT_OBJS}

clean:
	@echo "$(RED)clean$(NOC)"
	@${RM} ${OBJS} ${BONUS_OBJS} ${EXRTA_OBJS} ${LIBFT_OBJS} ${SHARE_OBJS}

fclean: clean
	@echo "$(RED)fclean$(NOC)"
	@${RM} ${NAME} ${BONUS_NAME}

re: fclean	all

tester:
	@echo "$(YELLOW)Testers are not perfect but its good enough$(NOC)"
	git clone ${TESTER1} TESTER1
	git clone ${TESTER2} TESTER2
	git clone ${TESTER3} TESTER3
	git clone ${TESTER3} TESTER4

norm:
	norminette

gitpush:
	git add .
	git status
	git commit -m ${NAME}
	git push

help:
	@clear
	@echo "$(GREEN)Avaibles options:$(NOC)"
	@echo "$(RED)==================$(NOC)"
	@echo "$(RED)| $(YELLOW)make ${NAME} $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make ${BONUS_NAME}   $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make norm      $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make tester    $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make clean     $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make fclean    $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make re        $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make help      $(RED)|$(NOC)"
	@echo "$(RED)==================$(NOC)"

.PHONY:		all	clean	fclean	re bonus norm gitpush tester help

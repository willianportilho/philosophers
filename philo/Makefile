# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: willian <willian@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 21:44:36 by wportilh          #+#    #+#              #
#    Updated: 2022/12/09 23:57:20 by willian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES =		1_main.c 2_init.c 3_one_philo.c 4_more_than_one_philo.c \
				5_life.c 6_finish.c 7_utils.c 8_lib.c

NAME =			philo

CC =			cc
CFLAGS =		-g3 -Wall -Wextra -Werror
THREAD =		-pthread
RM =			rm -f
RM_ALL =		rm -rf

VAL =			valgrind --leak-check=full --show-leak-kinds=all

HELL =			valgrind --tool=helgrind

DRD =			valgrind --tool=drd

INC =			./

SRC_PATH =		./

OBJ_PATH =		obj/

SRCS =			./

OBJS =			${addprefix ${OBJ_PATH}, ${SOURCES:.c=.o}}

ITALIC =		\033[3m
BLACK =			\033[30m
RED =			\033[31m
GREEN =			\033[32m
YELLOW =		\033[33m
BLUE =			\033[34m
PURPLE =		\033[35m
CYAN =			\033[36m
WHITE =			\033[37m
RESET =			\033[0m

all:			${NAME}

${NAME}:		${OBJS}
				@echo "${CYAN}--------------------------"
				@echo "         objs ok!"
				@echo "--------------------------"
				@${CC} ${THREAD} ${OBJS} -o ${NAME}
				@echo "--------------------------"
				@echo "minishell program created!"
				@echo "--------------------------${RESET}"

${OBJ_PATH}%.o:	${SRC_PATH}%.c
				@mkdir -p obj
				@${CC} ${CFLAGS} -c $< -o $@

val:			${NAME}
				${VAL} ./philo 4 410 200 200 7

hell:			${NAME}
				${HELL} ./philo 4 410 200 200 7

drd:			${NAME}
				${DRD} ./philo 4 410 200 200 7

run:			${NAME}
				./philo 13 10000 30 30

clean:		
				@${RM_ALL} ${OBJ_PATH}
				@echo "${CYAN}--------------------------"
				@echo "     clean completed!"
				@echo "--------------------------${RESET}"

fclean:			clean
				@${RM} ${NAME}
				@echo "${CYAN}--------------------------"
				@echo "    fclean completed!"
				@echo "--------------------------${RESET}"

re:				fclean all
				@echo "${CYAN}--------------------------"
				@echo "      re completed!"
				@echo "--------------------------${RESET}"

norm:
				norminette ${SRCS}

.PHONY:			all clean fclean re norm val hell drd
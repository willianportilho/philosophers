# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 21:44:36 by wportilh          #+#    #+#              #
#    Updated: 2022/11/30 02:14:51 by wportilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES =		main.c philo_utils.c philo_init.c philo_clean.c philo_time.c \
				philo_start.c philo_finish.c

NAME =			philo

CC =			cc
CFLAGS =		-g3 -Wall -Wextra -Werror
THREAD =		-pthread
RM =			rm -f
RM_ALL =		rm -rf

VAL =			valgrind --leak-check=full --show-leak-kinds=all

INC =			./inc

SRC_PATH =		src/

OBJ_PATH =		obj/

SRCS =			src/

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
				${VAL} ./philo 5 4 3 2 1

run:			${NAME}
				./philo 3 3 3 3

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
				norminette ${SRCS} ${INC}

.PHONY:			all clean fclean re norm val
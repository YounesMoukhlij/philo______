# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 09:19:32 by abechcha          #+#    #+#              #
#    Updated: 2024/03/01 10:12:39 by abechcha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Wextra -Werror

SRC = creat_threads.c\
	  ft_atoi.c\
	  ft_error.c\
	  extra_functions.c\
	  ft_set_element.c\
	  main.c\
	  ft_is_die.c\

OBJ = ${SRC:.c=.o}

all : ${NAME} 

%.o : %.c philo.h
	cc ${CFLAGS} -c $< -o $@

${NAME} : ${OBJ}
	cc ${OBJ} -o ${NAME}

clean : 
	rm -rf ${OBJ}

fclean : clean
	rm -rf ${NAME}

re : fclean all

PHONY : clean 

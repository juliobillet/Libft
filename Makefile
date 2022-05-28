# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbillet <jbillet@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/08 23:35:07 by jbillet           #+#    #+#              #
#    Updated: 2022/05/27 20:27:45 by jbillet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	ft_toupper.c	\
		ft_strtrim.c	\
		ft_putchar_fd.c	\
		ft_substr.c		\
		ft_strlcpy.c	\
		ft_memset.c		\
		ft_calloc.c		\
		ft_strmapi.c	\
		ft_putendl_fd.c	\
		ft_strlcat.c	\
		ft_itoa.c		\
		ft_memchr.c		\
		ft_memmove.c	\
		ft_striteri.c	\
		ft_putstr_fd.c	\
		ft_putnbr_fd.c	\
		ft_strdup.c		\
		ft_isdigit.c	\
		ft_strlen.c		\
		ft_split.c		\
		ft_strjoin.c	\
		ft_memcmp.c		\
		ft_strrchr.c	\
		ft_isalnum.c	\
		ft_atoi.c		\
		ft_memcpy.c		\
		ft_isalpha.c	\
		ft_strnstr.c	\
		ft_strchr.c		\
		ft_tolower.c	\
		ft_isprint.c	\
		ft_strncmp.c	\
		ft_bzero.c		\
		ft_isascii.c	\

OBJS = ${SRCS:.c=.o}
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
		${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${OBJS}
		ar rcs $@ $^

clean :
		rm -rf ${OBJS}

fclean : clean
		rm -rf ${NAME}

all : ${OBJS} ${NAME}

re : fclean all

.PHONY : all re clean fclean

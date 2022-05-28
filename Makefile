# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbillet <jbillet@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/08 23:35:07 by jbillet           #+#    #+#              #
#    Updated: 2022/05/28 09:34:02 by jbillet          ###   ########.fr        #
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
RESET = \033[0m
GREEN = \033[0;32m
YELLOW = \033[0;33m
CYAN = \033[0;36m

%.o: %.c
		@echo "${CYAN}Compiling${RESET} ${YELLOW}$<${RESET}"
		${CC} ${CFLAGS} -c $< -o $@
		@echo "${YELLOW}$<${RESET} ${GREEN}Compiled successfully!${RESET}"

${NAME} : ${OBJS}
		@echo "${CYAN}Creating${RESET} ${YELLOW}$@${RESET}"
		ar rcs $@ $^
		@echo "${YELLOW}$@${RESET} ${GREEN}Created successfully!${RESET}"

clean :
		@echo "${CYAN}Applying${RESET} ${YELLOW}$@${RESET}"
		rm -rf ${OBJS}
		@echo "${YELLOW}$@${RESET} ${GREEN}Applied successfully!${RESET}"

fclean : clean
		@echo "${CYAN}Applying${RESET} ${YELLOW}$@${RESET}"
		rm -rf ${NAME}
		@echo "${YELLOW}$@${RESET} ${GREEN}Applied successfully!${RESET}"

all : ${OBJS} ${NAME}

re : fclean all

.PHONY : all re clean fclean

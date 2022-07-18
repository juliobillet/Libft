# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbillet <jbillet@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/08 23:35:07 by jbillet           #+#    #+#              #
#    Updated: 2022/07/19 00:30:31 by jbillet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Source and objects paths and files
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

# Name of the Library to be created
NAME = libft.a

# C compiling command and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# COLORS
RESET = \033[0m
GREEN = \033[0;32m
YELLOW = \033[0;33m
CYAN = \033[0;36m

# Compile each C file into an object at a time.
%.o: %.c
		@echo "${CYAN}Compiling${RESET} ${YELLOW}$<${RESET}"
		${CC} ${CFLAGS} -c $< -o $@
		@echo "${YELLOW}$<${RESET} ${GREEN}Compiled successfully!${RESET}"

# Create the Library itself using the object files created above
${NAME} : ${OBJS}
		@echo "${CYAN}Creating${RESET} ${YELLOW}$@${RESET}"
		ar rcs $@ $^
		@echo "${YELLOW}$@${RESET} ${GREEN}Created successfully!${RESET}"

# Clean the object files
clean :
		@echo "${CYAN}Applying${RESET} ${YELLOW}$@${RESET}"
		rm -rf ${OBJS}
		@echo "${YELLOW}$@${RESET} ${GREEN}Applied successfully!${RESET}"

# Clean the object files and the library file
fclean : clean
		@echo "${CYAN}Applying${RESET} ${YELLOW}$@${RESET}"
		rm -rf ${NAME}
		@echo "${YELLOW}$@${RESET} ${GREEN}Applied successfully!${RESET}"

# Create all the object files and then create the Library
all : ${OBJS} ${NAME}

# Clean everything and run it all again
re : fclean all

# Restrict some key words so Makefile understand them exclusively as targets
.PHONY : all re clean fclean

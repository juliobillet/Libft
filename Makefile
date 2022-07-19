# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbillet <jbillet@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/08 23:35:07 by jbillet           #+#    #+#              #
#    Updated: 2022/07/19 07:03:40 by jbillet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Includes, Source and objects paths and files
INCLUDES = includes/

FILES = 	ft_toupper	\
		ft_strtrim		\
		ft_putchar_fd	\
		ft_substr		\
		ft_strlcpy		\
		ft_memset		\
		ft_calloc		\
		ft_strmapi		\
		ft_putendl_fd	\
		ft_strlcat		\
		ft_itoa			\
		ft_memchr		\
		ft_memmove		\
		ft_striteri		\
		ft_putstr_fd	\
		ft_putnbr_fd	\
		ft_strdup		\
		ft_isdigit		\
		ft_strlen		\
		ft_split		\
		ft_strjoin		\
		ft_memcmp		\
		ft_strrchr		\
		ft_isalnum		\
		ft_atoi			\
		ft_memcpy		\
		ft_isalpha		\
		ft_strnstr		\
		ft_strchr		\
		ft_tolower		\
		ft_isprint		\
		ft_strncmp		\
		ft_bzero		\
		ft_isascii		\

SRCS_PATH = srcs/

OBJS_PATH = objs/
OBJS = ${addprefix ${OBJS_PATH}, ${addsuffix .o, ${FILES}}}

OBJS_DIR = .cache_exists

# Name of the Library to be created
NAME = libft.a

# C compiling command and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I

# Colors
RESET = \033[0m
GREEN = \033[0;32m
YELLOW = \033[0;33m
CYAN = \033[0;36m
RED = \033[0;91m

# Compile each C file into an object at a time.
${OBJS_PATH}%.o: ${SRCS_PATH}%.c | ${OBJS_DIR}
		@echo "${CYAN}Compiling${RESET} ${YELLOW}$<${RESET}"
		${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@
		@echo "${YELLOW}$<${RESET} ${GREEN}Compiled successfully!${RESET}"

# Create OBJS folder
${OBJS_DIR} :
		@mkdir -p ${OBJS_PATH}

# Create the Library itself using the object files created above
${NAME} : ${OBJS}
		@echo "${CYAN}Creating${RESET} ${YELLOW}$@${RESET}"
		ar rcs $@ $^
		@echo "${YELLOW}$@${RESET} ${GREEN}Created successfully!${RESET}"

# Clean the object files
clean :
		@echo "${CYAN}Applying${RESET} ${YELLOW}$@${RESET}"
		@echo "${RED}Deleting:${RESET} ${YELLOW}${OBJS_PATH} folder!${RESET}"
		rm -rf ${OBJS_PATH}
		@echo "${YELLOW}${OBJS_PATH} folder!${RESET} ${RED}was deleted!${RESET}"
		@echo "${YELLOW}$@${RESET} ${GREEN}Applied successfully!${RESET}"

# Clean the object files and the library file
fclean : clean
		@echo "${CYAN}Applying${RESET} ${YELLOW}$@${RESET}"
		@echo "${RED}Deleting:${RESET} ${YELLOW}${NAME} file!${RESET}"
		rm -rf ${NAME}
		@echo "${YELLOW}${NAME} file${RESET} ${RED}was deleted!${RESET}"
		@echo "${YELLOW}$@${RESET} ${GREEN}Applied successfully!${RESET}"

# Create all the object files and then create the Library
all : ${NAME}

# Clean everything and run it all again
re : fclean all

# Restrict some key words so Makefile understand them exclusively as targets
.PHONY : all re clean fclean

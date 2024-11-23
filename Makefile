# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 09:48:53 by seojang           #+#    #+#              #
#    Updated: 2024/11/23 04:50:23 by mku              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.DEFAULT_GOAL := all

CC = cc
RM = rm -rf

SRC = main.c \
	ft_tokenizer.c \
	ft_export.c \
	ft_qoute.c \
	ft_split.c \
	ft_split_utils.c \
	ft_libft.c \
	ft_lst_util.c \
	ft_paser.c \
	ft_paser_util_pipe.c \
	ft_paser_util_redir.c \
	ft_paser_util_exe.c \
	ft_paser_util_heredoc.c \
	ft_paser_utils.c \
	ft_env_utils.c\
	ft_itoa.c \
	./String/ft_string.c\
	./String/ft_string2.c\
	./builtin/ft_builtin.c\
	./builtin/ft_cd.c\
	./builtin/ft_cd_utils.c\
	./builtin/ft_env.c\
	./builtin/ft_pwd.c\
	./builtin/ft_export.c\
	./builtin/ft_export_utils.c\
	./builtin/ft_exit.c\
	./builtin/ft_echo.c\
	./builtin/ft_unset.c

HEADER =	ms_test.h\
		./String/ft_string.h\
		./builtin/builtin.h\

OBJ_S = $(SRC_S:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address

NAME = minishell

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -lreadline -o $@

%.o : %.c
	$(CC) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re

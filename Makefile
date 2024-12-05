# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 09:48:53 by seojang           #+#    #+#              #
#    Updated: 2024/12/05 19:55:14 by mku              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.DEFAULT_GOAL := all

CC = cc
RM = rm -rf

SRC = main.c \
	Tokenizer/ft_tokenizer.c \
	Tokenizer/ft_export.c \
	Tokenizer/ft_qoute.c \
	Tokenizer/ft_qoute_check.c\
	Utils/ft_split.c \
	Utils/ft_split_utils.c \
	Utils/ft_lst_util.c \
	Utils/ft_env_utils.c\
	ft_paser.c \
	ft_paser_util_pipe.c \
	ft_paser_util_redir.c \
	ft_paser_util_exe.c \
	ft_paser_util_heredoc.c \
	ft_paser_utils.c \
	String/ft_string.c\
	String/ft_string2.c\
	String/ft_itoa.c\
	String/ft_libft.c \
	Signal/ft_sig_handler.c\
	Signal/ft_signal.c

HEADER = ms_test.h\
	    Signal/ft_signal.h\
	    String/ft_string.h

OBJ_S = $(SRC_S:.c=.o)

CFLAGS = -g -fsanitize=address #-Wall -Werror -Wextra

NAME = minishell

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lreadline -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re

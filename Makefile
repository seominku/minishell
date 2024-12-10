# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 09:48:53 by seojang           #+#    #+#              #
#    Updated: 2024/12/10 17:48:35 by mku              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.DEFAULT_GOAL := all

CC = cc
RM = rm -rf

SRC = main.c \
	Paser/ft_paser.c\
	Paser/ft_paser_here_util.c\
	Paser/ft_paser_man_util.c\
	Paser/ft_paser_util_exe.c\
	Paser/ft_paser_util_exe_norm.c\
	Paser/ft_paser_util_here.c\
	Paser/ft_paser_util_here_ex.c\
	Paser/ft_paser_util_here_first.c\
	Paser/ft_paser_util_pipe.c\
	Paser/ft_paser_util_redir.c\
	Paser/ft_paser_util_redir_norm.c\
	Paser/ft_paser_utils.c\
	String/ft_string.c\
	String/ft_string2.c\
	String/ft_ms_split.c\
	String/ft_itoa.c\
	String/ft_libft.c \
	Signal/ft_signal_util.c\
	Signal/ft_signal.c\
	Tokenizer/ft_tokenizer.c \
	Tokenizer/ft_export.c \
	Tokenizer/ft_qoute_check.c\
	Tokenizer/ft_check_token.c\
	Tokenizer/qoute.c\
	Tokenizer/qoute_utils.c\
	Tokenizer/q_export.c\
	Utils/ft_split.c \
	Utils/ft_split_utils.c \
	Utils/ft_lst_util.c \
	Utils/ft_env_utils.c\
	builtin/ft_builtin.c\
	builtin/ft_cd.c\
	builtin/ft_cd_utils.c\
	builtin/ft_echo.c\
	builtin/ft_env.c\
	builtin/ft_exit.c\
	builtin/ft_export_utils.c\
	builtin/ft_export.c\
	builtin/ft_pwd.c\
	builtin/ft_unset.c

HEADER = ms_test.h\
	    builtin/builtin.h\
	    Signal/ft_signal.h\
	    String/ft_string.h\
	    Tokenizer/ft_tokenizer.h\
	    Utils/utils.h\
	    paser/paser.h

OBJ_S = $(SRC_S:.c=.o)

CFLAGS = -g -fsanitize=address -Wall -Werror -Wextra

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

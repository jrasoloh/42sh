# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/30 11:15:13 by echojnow          #+#    #+#              #
#    Updated: 2018/06/14 13:58:02 by jrasoloh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

CC = clang
FLAG = -Wall -Wextra #-Werror

INC_DIR = incs
SRCS_DIR = srcs
OBJS_DIR = objs

SRCS_NAME = \
	  twentyonesh.c \
	  edit_line.c \
	  line_memo.c \
	  manage_term.c \
	  sighandlers.c \
	  init.c \
	  eval.c \
	  interpreter.c \
	  lexer.c \
	  lexer_make_tgs.c \
	  parser.c \
	  token_utils.c \
	  update_input.c \
	  builtins.c \
	  builtins_un_setenv.c \
	  builtin_cd.c \
	  env.c \
	  utils.c
OBJS_NAME = $(SRCS_NAME:.c=.o)

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_NAME))
OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS_NAME))

INCLUDE = -I$(INC_DIR) -Ilibft/includes
LIB = -Llibft -lft -ltermcap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAG) $^ -o $@ $(LIB)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(FLAG) $(INCLUDE) -c $^ -o $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: all
	@./$(NAME)

deb: all
	@valgrind --track-origins=yes ./$(NAME)

debl: all
	@valgrind --track-origins=yes --leak-check=full ./$(NAME)

norm:
	@norminette $(SRCS) $(INC_DIR)/twentyonesh.h | grep -B1 "Warning\|Error" \
		|| echo OK

vim:
	@nvim Makefile $(INC_DIR)/twentyonesh.h $(SRCS)

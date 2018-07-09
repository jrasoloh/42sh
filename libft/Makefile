# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/05 12:16:35 by echojnow          #+#    #+#              #
#    Updated: 2018/06/18 17:22:38 by echojnow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror

SRCS = \
	   ft_lstnew.c \
	   ft_lstdelone.c \
	   ft_lstdel.c \
	   ft_lstadd.c \
	   ft_lstapp.c \
	   ft_lstlast.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   \
	   ft_slistnew.c \
	   ft_slistadd.c \
	   ft_slistaddn.c \
	   ft_slistapp.c \
	   ft_slistappn.c \
	   ft_slistins_s.c \
	   ft_slistinsn_s.c \
	   ft_slistlast.c \
	   ft_slistlen.c \
	   ft_slistiter.c \
	   ft_slistdel.c \
	   \
	   ft_silistnew.c \
	   ft_silistadd.c \
	   ft_silistaddn.c \
	   ft_silistins_s.c \
	   ft_silistinsn_s.c \
	   ft_silistdel.c \
	   \
	   ft_tlistnew.c \
	   ft_tlistadd.c \
	   ft_tlistaddn.c \
	   ft_tlistapp.c \
	   ft_tlistappn.c \
	   ft_tlistlast.c \
	   ft_tlistlen.c \
	   ft_tlisti.c \
	   ft_tlistiter.c \
	   ft_tlistdel.c \
	   ft_tlistdelone.c \
	   \
	   ft_abstnew.c \
	   ft_abstaddn.c \
	   ft_abstadd.c \
	   ft_abstmax.c \
	   ft_abstmin.c \
	   ft_abstiter_inorder.c \
	   ft_abstdel.c \
	   \
	   ft_bstknew.c \
	   ft_bstkaddn.c \
	   ft_bstkaddnt.c \
	   ft_bstkadd.c \
	   ft_bstkaddt.c \
	   ft_bstkmax.c \
	   ft_bstkmin.c \
	   ft_bstkiter_inorder.c \
	   ft_bstkdel.c \
	   \
	   ft_bstnew.c \
	   ft_bstaddn.c \
	   ft_bstadd.c \
	   ft_bstmax.c \
	   ft_bstmin.c \
	   ft_bstiter_inorder.c \
	   ft_bstdel.c \
	   \
	   ft_memset.c \
	   ft_memcpy.c \
	   ft_memccpy.c \
	   ft_memmove.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   \
	   ft_memalloc.c \
	   ft_memdel.c \
	   \
	   ft_bzero.c \
	   \
	   ft_strlen.c \
	   ft_strdup.c \
	   ft_strcmp.c \
	   ft_strncmp.c \
	   ft_strcpy.c \
	   ft_strncpy.c \
	   ft_strcat.c \
	   ft_strncat.c \
	   ft_strlcat.c \
	   ft_strapp.c \
	   ft_strappf.c \
	   ft_strappc.c \
	   ft_strappcf.c \
	   ft_strchr.c \
	   ft_strchri.c \
	   ft_strnchri.c \
	   ft_strrchr.c \
	   ft_strrchri.c \
	   ft_strstr.c \
	   ft_strnstr.c \
	   \
	   ft_strnew.c \
	   ft_strdel.c \
	   ft_strclr.c \
	   ft_strext.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strequ.c \
	   ft_strnequ.c \
	   ft_strsub.c \
	   ft_strrm.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_strsplit.c \
	   \
	   ft_ntsarr_len.c \
	   ft_ntsarr_free.c \
	   ft_ntsarr_push.c \
	   ft_ntsarr_print.c \
	   \
	   ft_itoa.c \
	   ft_atoi.c \
	   \
	   ft_format_internal.c \
	   ft_format.c \
	   \
	   ft_toupper.c \
	   ft_tolower.c \
	   \
	   ft_strisblank.c \
	   \
	   ft_abs.c \
	   ft_pow.c \
	   ft_numlen.c \
	   ft_numlen_base.c \
	   \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_isblank.c \
	   \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_putnbr_base_fd.c \
	   ft_putmem_fd.c \
	   ft_put_fd.c \
	   \
	   ft_putchar.c \
	   ft_putstr.c \
	   ft_putendl.c \
	   ft_putnbr.c \
	   ft_putnbr_base.c \
	   ft_putdebug.c \
	   ft_putmem.c \
	   ft_put.c \
	   \
	   ft_tabsort.c \
	   \
	   ft_pathjoin.c \
	   ft_pathjoinc.c \
	   ft_basename.c \
	   \
	   ft_throw.c \
	   ft_err.c \
	   \
	   ft_gnl.c \
	   ft_file_exists.c


OBJS = $(SRCS:.c=.o)

INCLUDES=includes

all: $(NAME)

$(NAME): $(OBJS)
	ar cr $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $^ -I $(INCLUDES)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

norm:
	@norminette $(SRCS) $(INCLUDES)/libft.h | grep -B1 "Warning\|Error" \
		|| echo OK

vim:
	nvim Makefile includes/libft.h

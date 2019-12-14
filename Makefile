# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/12/14 12:45:05 by mrozniec     #+#   ##    ##    #+#        #
#    Updated: 2019/12/14 13:40:43 by mrozniec    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #
NAME = libftprintf.a

SRC =	ft_printf.c\
		ft_parse.c\
		ft_convert.c\
		ft_wchar_utf_8.c\
		convertion/ft_cmin_conv.c\
		convertion/ft_dmin_conv.c\
		convertion/ft_nmin_conv.c\
		convertion/ft_pmin_conv.c\
		convertion/ft_smin_conv.c\
		convertion/ft_umin_conv.c\
		convertion/ft_xmin_conv.c\
		convertion/ft_xmaj_conv.c\
		convertion/ft_perc_conv.c\
		flags/ft_apost.c\
		flags/ft_hash.c\
		flags/ft_hflags.c\
		flags/ft_hhflags.c\
		flags/ft_lflags.c\
		flags/ft_llflags.c\
		flags/ft_plus.c\
		flags/ft_precision.c\
		flags/ft_size_champ.c\
		flags/ft_space.c\
		flags/ft_zero.c

HEADER =	libft.h\
			libftprintf.h\
			convertion/libconv.h\
			flags/libflag.h

OBJ =	$(SRC:.c=.o)

OBJ_FT =	ft_atoi.o\
			ft_bzero.o\
			ft_calloc.o\
			ft_isalnum.o\
			ft_isalpha.o\
			ft_isascii.o\
			ft_isdigit.o\
			ft_isprint.o\
			ft_itoa.o\
			ft_llitoa.o\
			ft_itoa_base.o\
			ft_hitoa_base.o\
			ft_hhitoa_base.o\
			ft_litoa_base.o\
			ft_llitoa_base.o\
			ft_memccpy.o\
			ft_memchr.o\
			ft_memcmp.o\
			ft_memcpy.o\
			ft_memmove.o\
			ft_memset.o\
			ft_putchar_fd.o\
			ft_putendl_fd.o\
			ft_putnbr_fd.o\
			ft_putstr_fd.o\
			ft_split.o\
			ft_strchr.o\
			ft_strdup.o\
			ft_strjoin.o\
			ft_strjoinmod.o\
			ft_strlcat.o\
			ft_strlcpy.o\
			ft_strlen.o\
			ft_strmapi.o\
			ft_strncmp.o\
			ft_strnstr.o\
			ft_strrchr.o\
			ft_strtrim.o\
			ft_substr.o\
			ft_tolower.o\
			ft_toupper.o

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@ar x libft.a
	@ar rc $(NAME) $(OBJ) $(OBJ_FT)

%.o: %.c
	@cc -o $@ -c $< -Wall -Wextra -Werror

.PHONY: clean fclean re all

clean:
	@/bin/rm -f $(OBJ) $(OBJ_FT)

fclean: clean
	@/bin/rm -rf $(NAME) __.SYMDEF\ SORTED

re: fclean all

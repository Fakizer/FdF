#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/09 13:47:37 by vvlasenk          #+#    #+#              #
#    Updated: 2016/12/09 13:47:38 by vvlasenk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME 	=	fdf
LIBFT	=	libft.a

GCC		=	gcc
WWW		=	-Wall -Wextra -Werror
IGRAPH	=	-L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL \
			-framework AppKit

SRCFDF	=	main.c create_data.c draw.c error.c file.c help.c \
			init_data.c math.c max_min.c push_keys.c \
			rot_proc.c set_color.c
SRCLIB	=	ft_memset.c ft_memcpy.c ft_memchr.c ft_memcmp.c \
			ft_strcmp.c ft_bzero.c ft_memmove.c ft_strlen.c \
			ft_strcpy.c ft_strncpy.c ft_memccpy.c ft_toupper.c \
			ft_strcat.c ft_strncat.c ft_strchr.c ft_strrchr.c \
			ft_strncmp.c ft_tolower.c ft_strstr.c ft_strdup.c \
			ft_strnstr.c ft_atoi.c ft_strlcat.c ft_isalpha.c \
			ft_isdigit.c ft_isalnum.c ft_isprint.c ft_isascii.c \
			ft_putstr.c ft_putchar.c ft_memalloc.c ft_memdel.c \
			ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
			ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
			ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
			ft_strsplit.c ft_itoa.c ft_putendl.c ft_putnbr.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			ft_lstmap.c ft_lstnew.c ft_lstiter.c ft_lstdelone.c \
			ft_lstdel.c ft_lstadd.c ft_putnbr_fd.c \
			get_next_line.c

OBJLIB	=	$(addprefix $(OBJDIRL),$(SRCLIB:.c=.o))
OBJFDF	=	$(addprefix $(OBJDIRF),$(SRCFDF:.c=.o))

INCLUDES=	-I./includes/

LIBFTDIR=	./libft/
OBJDIRL	=	./objlib/
OBJDIRF =	./objfdf/
SRCDIR	=	./sources/

all: $(NAME)

$(NAME):	$(LIBFT) $(OBJDIRF) $(OBJFDF)
			$(GCC) -o $@ $(IGRAPH) $(OBJFDF) $(LIBFT)

$(LIBFT):	$(OBJDIRL) $(OBJLIB)
			ar rc $(LIBFT) $(OBJLIB)

$(OBJDIRL):
			mkdir -p $@

$(OBJDIRL)%.o:$(LIBFTDIR)%.c
			$(GCC) $(WWW) $(INCLUDES) -o $@ -c $<

$(OBJDIRF):
			mkdir -p $@

$(OBJDIRF)%.o:$(SRCDIR)%.c
			$(GCC) $(WWW) $(INCLUDES) -o $@ -c $<

clean:
	rm -rf $(OBJLIB) $(OBJDIRL) $(OBJFDF) $(OBJDIRF)

fclean: clean
	rm -f $(LIBFT) $(NAME)

re: fclean all


# gcc -o fdf main.c -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit
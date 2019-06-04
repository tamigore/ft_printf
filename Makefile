# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artprevo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 00:20:03 by artprevo          #+#    #+#              #
#    Updated: 2019/06/04 17:20:59 by tamigore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exec

LIB = libft/libft.a

FLAGS = -Wall -Wextra -Werror

BASE_SRC = main.c init.c parsing.c usefull.c subs.c printf.c find.c

SRC = $(addprefix srcs/, $(BASE_SRC))

BASE_OBJ = $(BASE_SRC:.c=.o)

OBJ = $(addprefix objs/, $(BASE_OBJ))

HEADERS = includes/

all : $(NAME)

$(NAME) : $(OBJ) $(LIB)
	gcc $(FLAGS) $(OBJ) $(LIB) -o $(NAME) -I$(HEADERS)

$(OBJ) : $(SRC)
	gcc $(FLAGS) -c $(SRC) -I$(HEADERS)
	@test -d objs || mkdir objs
	@mv $(BASE_OBJ) objs/

$(LIB) :
	@test -e $(LIB) || (cd libft ; make)

.PHONY : clean lclean fclean

clean :
	rm -rf objs/*

lclean:
	(cd libft ; make clean)

fclean : clean lclean
	rm -f $(NAME)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artprevo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 00:20:03 by artprevo          #+#    #+#              #
#    Updated: 2019/01/07 18:18:42 by artprevo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exec

LIB = libft/libft.a

FLAGS = -Wall -Wextra -Werror

BASE_SRC = init.c parsing.c usefull.c

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
	rm -rdf obj/

lclean:
	(cd libft ; make clean)

fclean : clean lclean
	rm -f $(NAME)

re: fclean all

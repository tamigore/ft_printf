# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tamigore <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/19 16:16:11 by tamigore          #+#    #+#              #
#    Updated: 2019/09/19 16:16:20 by tamigore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror #-Weverything

LIBFT = libft

DIR_S = srcs

DIR_O = objs

HEADER = includes

SOURCES = conv_nb.c		\
		  double.c		\
		  find.c		\
		  init.c		\
		  itoa.c		\
		  modif.c		\
		  option.c		\
		  option_one.c	\
		  option_duo.c	\
		  printf.c		\
		  free.c		\
		  usefull.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/ft_printf.h
	mkdir -p objs
	$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<



test: test_printf/test.c test_printf/main.c $(NAME)
	gcc test_printf/test.c libftprintf.a $(FLAGS) -I $(HEADER) -o test
	gcc test_printf/main.c libftprintf.a $(FLAGS) -I $(HEADER) -o main

tclean:
	@rm -f test
	@rm -f main
	@rm -rf a.out.dSYM


norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(DIR_S)/

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

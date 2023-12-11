# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 16:31:00 by akoutate          #+#    #+#              #
#    Updated: 2023/12/11 17:08:33 by akoutate         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_print_char.c ft_print_num.c ft_print_unum.c ft_print_adrs.c ft_print_hexa.c
OBJ = $(SRC:.c=.o)
CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
RM = rm -f
AR = ar rc

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $@ $^

%.o : %.c ft_printf.h
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean
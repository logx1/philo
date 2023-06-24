# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/10 21:43:36 by abdel-ou          #+#    #+#              #
#    Updated: 2023/06/24 11:40:34 by abdel-ou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo

SRC = main.c time.c sleep.c print.c inits.c check_died.c ft_atoi.c eating.c end.c 

CC = cc

FLAGS = -Wall -Werror -Wextra


OBJ = $(SRC:.c=.o)


$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)


%.o:%.c
	$(CC) $(FLAGS) -c $^ -o $@

all : $(NAME)

fclean:
	@rm -rf $(NAME) $(OBJ)
clean:
	@rm -rf $(OBJ)

re:fclean all 
	
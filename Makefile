# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aljacque <aljacque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 16:52:56 by aljacque          #+#    #+#              #
#    Updated: 2018/11/21 16:53:29 by aljacque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = fillit.c
OBJ = $(SRC:.c=.o)
HEADER = fillit.h
CFLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc $(CFLAG) -c $(SRC) -I $(HEADER)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	@norminette -RCheckForbiddenSourceHeader $(SRCS) | grep -e 'Warning' -e 'Error' -B1 || true

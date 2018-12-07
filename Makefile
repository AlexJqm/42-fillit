# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aljacque <aljacque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 16:52:56 by aljacque          #+#    #+#              #
#    Updated: 2018/12/07 17:58:25 by aljacque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = 	ft_check_error.c \
		ft_check_pieces.c \
		ft_convers.c \
		ft_fillit.c \
		ft_free_tab.c \
		ft_next_sqrt.c \
		ft_print_error.c \
		ft_print_res.c \
		ft_print_tab.c \
		ft_shift_pieces.c \
		ft_tab_dup.c \
		ft_tab_size.c \
		get_next_line.c \
		main.c
OBJ = $(SRC:.c=.o)
HEADER =	includes/fillit.h \
			libft/libft.h
CFLAG = -Wall -Werror -Wextra

# COLOR MACRO #

LOG_CLEAR		=	\033[2K
LOG_UP 			=	\033[A
LOG_NOCOLOR		=	\033[0m
LOG_BLACK		=	\033[1;30m
LOG_RED			=	\033[1;31m
LOG_GREEN		=	\033[1;32m
LOG_YELLOW		=	\033[1;33m
LOG_BLUE		=	\033[1;34m
LOG_VIOLET		=	\033[1;35m
LOG_CYAN		=	\033[1;36m
LOG_WHITE		=	\033[1;37m

# EXEC #

all: $(NAME)

$(NAME):
	@make -C libft
	@echo "\n\t$(LOG_RED)██$(LOG_NOCOLOR) please wait..."
	@gcc $(CFLAG) -c $(SRC) -I $(HEADER)
	@echo "\t$(LOG_GREEN)██$(LOG_NOCOLOR) compilation OK"
	@ar rc $(NAME) $(OBJ)
	@echo "\t$(LOG_GREEN)██$(LOG_NOCOLOR) ar rc OK"
	@ranlib $(NAME)
	@echo "\t$(LOG_GREEN)██$(LOG_NOCOLOR) ranlib OK"
	@echo "\t$(LOG_GREEN)██$(LOG_NOCOLOR) $(NAME) created.\n"

clean:
	@make clean -C libft
	@echo "\n\t$(LOG_RED)██$(LOG_NOCOLOR) please wait..."
	@rm -f $(OBJ)
	@echo "\t$(LOG_GREEN)██$(LOG_NOCOLOR) rm .o OK"
	@echo "\t$(LOG_GREEN)██$(LOG_NOCOLOR) $(NAME) succes all .o deleted.\n"

fclean: clean
	@make fclean -C libft
	@echo "\n\t$(LOG_RED)██$(LOG_NOCOLOR) please wait..."
	@rm -f $(NAME)
	@echo "\t$(LOG_GREEN)██$(LOG_NOCOLOR) rm $(NAME) OK"
	@echo "\t$(LOG_GREEN)██$(LOG_NOCOLOR) $(NAME) succes $(NAME) deleted.\n"

re:
	fclean all
	make re -C libft

# EXTRA #

norm:
	@echo "\n\t$(LOG_RED)██$(LOG_NOCOLOR) please wait...\n"
	@norminette -RCheckForbiddenSourceHeader $(SRCS) | grep -e 'Warning' -e 'Error' -B1 || true
	@echo "\n\t$(LOG_GREEN)██$(LOG_NOCOLOR) norminette finish.\n"

help:
	@echo "\n\t$(LOG_YELLOW)clean$(LOG_NOCOLOR)\t\tCleaning all object"
	@echo "\t$(LOG_YELLOW)fclean$(LOG_NOCOLOR)\t\tCleaning all object and executable"
	@echo "\t$(LOG_YELLOW)norm$(LOG_NOCOLOR)\t\tCheck norminette"
	@echo "\t$(LOG_YELLOW)re$(LOG_NOCOLOR)\t\tDeleting all object and build\n"

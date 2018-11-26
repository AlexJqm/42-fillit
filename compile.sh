clang -Wall -Wextra -Werror -I libft/includes -o ft_fillit.o -c ft_fillit.c
clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
clang -o fillit main.o ft_fillit.o -I libft/includes -L libft/ -lft

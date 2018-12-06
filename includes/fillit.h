/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:38:29 by coremart          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/12/06 16:09:24 by coremart         ###   ########.fr       */
=======
/*   Updated: 2018/12/06 17:10:10 by aljacque         ###   ########.fr       */
>>>>>>> 85eaa1f4bc6dd133b6a176680e66184f1cb4c012
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# define BUFF_SIZE 5

typedef struct	s_fd
{
	char		*content;
	int			fd;
	struct s_fd	*next;
}				t_fd;

typedef struct	s_piece
{
	char	piece[4][4];
}				t_piece;

t_piece			*ft_check_error(int fd);
void			ft_print_error(int fd, int num);
int				get_next_line(const int fd, char **line);
void			ft_print_tab(t_piece *tab);
size_t			ft_tab_size(t_piece *tab);
size_t			ft_next_sqrt(size_t nb);
void			ft_check_pieces(t_piece *tab, int fd);
t_piece			*ft_shift_pieces(t_piece *tab);

#endif
